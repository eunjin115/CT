#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include <thread>

HANDLE hMutex;

struct TestData
{
    int file_size = 0;
    char path[256] = { 0, };
    bool type = false;  //0이면 server -> client, 1이면 client -> server 
    char buffer[1200000054] = { 0, }; //최대 1GB
};

void SendFile(TestData*& shared_data);
void RecvFile(TestData*& shared_data);

int main()
{
    //FMO = File Mapping Object
    //Named SharedMemory 정의 (두 프로세스 모두 있어야 한다) 
    LPTSTR shared_memory = TEXT("SharedMemory1"); //server write to client 

    //Server는 첫 번째 SharedMemory만을 생성
    HANDLE hMap = CreateFileMapping( //first shared memory 
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        sizeof(TestData),
        shared_memory);


    if (hMap == NULL) //error 처리 
    {
        std::cout << "Could not find file mapping object (" << GetLastError() << ").\n";
        return 1;
    }

    //SharedMemory에 대한 실제 메모리 매핑 
    void* mapped_memory = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    if (mapped_memory == NULL)
    {
        std::cout << "Could not map view of file (" << GetLastError() << ").\n";
        CloseHandle(hMap);
        return 1;
    }

    TestData* shared_data = (TestData*)mapped_memory;

    LPTSTR Mutex = TEXT("Mutex"); //named mutex
    hMutex = CreateMutex(
        NULL,
        FALSE,
        Mutex);

    char input;
    std::string path;
    while (1)
    {
        //S or R 입력받기        
        std::cout << "Please Enter Command. \n S - Send file, R - Recive file, Q - Exit \n";
        std::cin >> input;

        if (input == 'S' || input == 's')
        {
            std::cout << "Enter File Name : ";
            std::cin >> shared_data->path;

            std::thread file_send = std::thread(SendFile, std::ref(shared_data));

            file_send.detach();
            //SendFile(shared_data);
            continue;
        }
        else if (input == 'R' || input == 'r')
        {
            RecvFile(shared_data);
            continue;
        }
        else if (input == 'Q' || input == 'q')
        {
            break;
        }
        else
        {
            std::cout << "Check command again. \n";
            continue;
        }
    }

    return 0;
}

void SendFile(TestData*& shared_data) //동기화 객체 추가하기 
{
    std::ifstream fin;

    WaitForSingleObject(hMutex, INFINITE);
    //::Sleep(10000);
    fin.open(shared_data -> path, std::ios::binary);
    fin.seekg(0, std::ios::end);

    shared_data->file_size = fin.tellg();    //get file size 
    fin.seekg(0, std::ios::beg);

    fin.read(shared_data->buffer, shared_data->file_size);
    fin.close();
    std::cout << "\n\n File Sending is done. \n\n";

    ReleaseMutex(hMutex);
}


void RecvFile(TestData*& shared_data) 
{
    std::ofstream fout;

    std::string path;
    std::cout << "Enter New File Name : ";
    std::cin >> path;
    fout.open(path, std::ios::binary);

    if (shared_data->file_size != 0)
        fout.write(shared_data->buffer, shared_data->file_size);
    else
    {
        std::cout << "buffer is empty! \n";
        return;
    }

    std::cout << "Read Done \n\n";
}