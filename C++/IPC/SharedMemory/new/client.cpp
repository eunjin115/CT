#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>

LPTSTR Mutex = TEXT("Mutex"); //named mutex
LPTSTR shared_memory = TEXT("SharedMemory");

HANDLE hMutex;
HANDLE hMap;

struct TestData
{
    int file_size;
    char path[256] = { 0, };
    bool type = false;  //0이면 server -> client, 1이면 client -> server 
    //char buffer[1200000054] = { 0 }; //최대 1GB
    char buffer[1800000000] = { 0 }; //최대 1GB
};

TestData* initial()
{
    hMutex = OpenMutex(
        MUTEX_ALL_ACCESS,
        FALSE,
        Mutex
    );

    //Client는 SharedMemory를 open하여 사용 
    HANDLE hMap = OpenFileMapping( //first shared memory 
        FILE_MAP_ALL_ACCESS,
        FALSE,
        shared_memory);

    if (hMap == NULL) //error 처리 
    {
        std::cout << "Could not find file mapping object (" << GetLastError() << ").\n";
        return NULL;
    }

    //SharedMemory에 대한 실제 메모리 매핑 
    TestData* shared_data = (TestData*)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    if (shared_data == NULL) //error 처리 
    {
        std::cout << "Could not map view of file (" << GetLastError() << ").\n";
        CloseHandle(hMap);
        return NULL;
    }

    return shared_data;
}

void SendFile(TestData*& shared_data) //동기화 객체 추가하기 
{

    if (shared_data->file_size == 0)
    {
        WaitForSingleObject(hMutex, INFINITE);

        std::ifstream fin;

        fin.open(shared_data->path, std::ios::binary);
        fin.seekg(0, std::ios::end);

        shared_data->file_size = fin.tellg();    //get file size 
        fin.seekg(0, std::ios::beg);

        fin.read(shared_data->buffer, shared_data->file_size);
        fin.close();

        std::cout << "File Sending is done. \n\n";
        ReleaseMutex(hMutex);
    }
    else
        std::cout << "Already File Written on buffer. \n\n";
    return;
}

void RecvFile(TestData*& shared_data)
{
    std::ofstream fout;
    WaitForSingleObject(hMutex, INFINITE);

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
    //버퍼 비우기 
    shared_data->file_size = 0;
    //사실 버퍼를 다 비워야 하는데,, 일단 파일 사이즈만 0으로

    ReleaseMutex(hMutex);

}

int main()
{
    TestData* shared_data = initial();

    if (shared_data == NULL) //error
        return 1;

    char input;
    std::string path;


    while (1)
    {
        //S or R 입력받기        
        std::cout << "Please Enter Command. \n S - Send file, R - Receive file, Q - Exit \n";
        std::cin >> input;

        if (input == 'S' || input == 's')
        {
            std::cout << "Enter File Name : ";
            std::cin >> shared_data->path;

            std::thread file_send = std::thread(SendFile, std::ref(shared_data));
            //std::this_thread::sleep_for((std::chrono::milliseconds(100)));
            //file_send.detach();
            file_send.join();
            continue;
        }
        else if (input == 'R' || input == 'r')
        {
            std::thread file_recv = std::thread(RecvFile, std::ref(shared_data));
            //std::this_thread::sleep_for((std::chrono::milliseconds(100)));
            //file_recv.detach();
            file_recv.join();
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

    ::UnmapViewOfFile(shared_data);
    ::CloseHandle(hMap);
    ::CloseHandle(hMutex);

    return 0;
}