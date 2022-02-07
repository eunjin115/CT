//write data 

#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//Data structure for testing
struct MyTestData //구조체를 client와 맞춰줘야 한다 
{
    int TestInt;        //Integer data for testing
    char TestStr[5];    //String data for testing

    //buffer 크기 최대 1GB로 잡아줘야 함 -> 그래야 shared memory 1GB 가능 
    //buffer 런타임때 할당 하면 즈을대로 안된다~! 
    char buffer[100000000];
};

int main()
{
    //Name of FMO(file mapping object) (should be consistent between the two test processes)

    LPTSTR shared_memory_1 = TEXT("SharedMemory1"); //server -> client 
    LPTSTR shared_memory_2 = TEXT("SharedMemory2"); //client -> server

    //Create an FMO
    HANDLE first_hMap = CreateFileMapping ( //first shared memory 
        INVALID_HANDLE_VALUE,       // use paging file
        NULL,                       // default security
        PAGE_READWRITE,             // read-write permission
        0,                          // maximum object size (high-order DWORD)
        sizeof(MyTestData),         // maximum object size (low-order DWORD)
        //0xFFFFFF? 
        shared_memory_1);          // Name of FMO

    HANDLE second_hMap = CreateFileMapping( //first shared memory 
        INVALID_HANDLE_VALUE,       // use paging file
        NULL,                       // default security
        PAGE_READWRITE,             // read-write permission
        0,                          // maximum object size (high-order DWORD)
        sizeof(MyTestData),         // maximum object size (low-order DWORD)
        //0xFFFFFF? 
        shared_memory_2);          // Name of FMO

    if (shared_memory_1 == NULL || shared_memory_2 == NULL)
    {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    //Map to Buffer
    void* pBuffer = MapViewOfFile(shared_memory_1, FILE_MAP_ALL_ACCESS, 0, 0, 0); //server to client buffer (wirte) 

    //Convert pointer to MyTestData type
    MyTestData* shared_data = (MyTestData*)pBuffer;

    std::ifstream fin;
    std::ofstream fout;

    int i = 0;
    //Changing data in a loop
    while (1)
    {
        if (i != 0)
            continue;
        if (i == 0)
        {
            i++;
            //Write a random data
            shared_data->TestInt = rand() % 10;
            for (int i = 0; i < 4; i++)
                shared_data->TestStr[i] = 'a' + rand() % 26;
            shared_data->TestStr[4] = '\0';

            //get path
            shared_data->path = "C:\\Users\\USER\\Desktop\\test\\lover_of_mine.txt";
            fin.open(shared_data->path, std::ios::binary);
            fin.seekg(0, std::ios::end);
            int file_size = fin.tellg();

            fin.seekg(0, std::ios::beg);
            fin.read(shared_data->buffer, file_size);
            shared_data->buffer[file_size] = '\0';
            fin.close();

            //Print information:
            std::cout << "Write to shared memory:" << shared_data->TestInt << ' ' << shared_data->TestStr << std::endl;

            //Stay for 1 second
            Sleep(1000);
        }
    }

    std::cout << "Read Done!\n";

    //Unmap
    UnmapViewOfFile(pBuffer);
    //Turn off FMO's Handle
    CloseHandle(hMap);

    return 0;
}