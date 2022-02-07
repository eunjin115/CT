//Read data

#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//Data structure for testing
struct MyTestData
{
    int TestInt;        //Integer data for testing
    char TestStr[5];    //String data for testing

    char buffer[100000000];
};

int main()
{
    //Name of FMO(file mapping object) (should be consistent between the two test processes)

    LPTSTR FMO_Name = TEXT("SharedMemory");
    //Open an FMO
    HANDLE hMap = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,    // Read/Write Permissions
        FALSE,                  // do not inherit the name
        //FMO_Name.c_str());      // Name of FMO
        FMO_Name);      // Name of FMO

    if (hMap == NULL)
    {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }
    //Map to Buffer
    void* pBuffer = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    //Convert pointer to MyTestData type
    MyTestData* shared_data = (MyTestData*)pBuffer;

    std::ofstream fout;
    int len=0;
    //Reading data continuously in a loop
    while (1)
    {
        //Print information:
        std::cout << "Read shared memory:" << shared_data->TestInt << ' ' << shared_data->TestStr << std::endl;
        //Stay for 0.1 seconds
        Sleep(100);
        fout.open("C:\\Users\\USER\\Desktop\\test\\copy\\lover_of_mine_copy.txt", std::ios::binary);
        fout.write(shared_data->buffer, strlen(shared_data->buffer));
        //동기화 객체 필요 (세마포어 or mutex) 
        std::cout << "read done \n";
    }
    //fout.open("C:\\Users\\USER\\Desktop\\test\\copy\\lover_of_mine_copy.txt", std::ios::binary);
    //fout.open(shared_data->path+"copy.txt", std::ios::binary);
    //fout.write(shared_data->buffer.str().c_str(), shared_data->buffer.str().size());

    //int i = 0;
    //while(1)
    //{
    //    if (!i)
    //    {
    //        std::cout << shared_data->path << "\n";
    //        fout.write(shared_data->buffer.str().c_str(), shared_data->buffer.str().size());
    //        Sleep(1);
    //    }
    //    i++;
    //}

    //Unmap
    UnmapViewOfFile(pBuffer);
    //Turn off FMO's Handle
    CloseHandle(hMap);

    return 0;
}