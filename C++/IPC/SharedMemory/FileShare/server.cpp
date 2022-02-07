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
    std::string path;
    //std::stringstream buffer;
   
    //buffer 크기 최대 1GB로 잡아줘야 함 -> 그래야 shared memory 1GB 가능 
    //buffer 런타임때 할당 하면 즈을대로 안된다~! 
    char buffer[100000000];
};

int main()
{
    //Name of FMO(file mapping object) (should be consistent between the two test processes)
    //const std::wstring FMO_Name(L"TestFMO");

    //TCHAR FMO_Name[] = TEXT("\\\\.\\Global\\SharedMemory");

    LPTSTR FMO_Name = TEXT("SharedMemory");

    //Create an FMO
    HANDLE hMap = CreateFileMapping(
        INVALID_HANDLE_VALUE,       // use paging file
        NULL,                       // default security
        PAGE_READWRITE,             // read-write permission
        0,                          // maximum object size (high-order DWORD)
        sizeof(MyTestData),         // maximum object size (low-order DWORD)
        //FMO_Name.c_str());          // Name of FMO
        FMO_Name);          // Name of FMO

    if (hMap == NULL)
    {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    //Map to Buffer
    void* pBuffer = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

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


    //파일 작성 코드로 변경 
    //while (1)
    //{
    //    shared_data->path = "C:\\Users\\USER\\Desktop\\test\\lover_of_mine.txt";
    //    std::cout << shared_data->path << "\n";
    //    Sleep(1000);
    //}
    //std::ifstream fin;
    //fin.open(shared_data->path, std::ios::binary);
    //shared_data->buffer << fin.rdbuf();

    std::cout << "Read Done!\n";

    //Unmap
    UnmapViewOfFile(pBuffer);
    //Turn off FMO's Handle
    CloseHandle(hMap);

    return 0;
}