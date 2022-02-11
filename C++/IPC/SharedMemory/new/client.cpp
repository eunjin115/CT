#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

#include <thread>
#include <chrono>

LPTSTR Mutex = TEXT("Mutex");
LPTSTR SharedMemory = TEXT("SharedMemory");

HANDLE hMutex;
HANDLE hMap;


struct DataFile
{
    int file_size = 0;
    char buffer[1200000054] = { 0, }; //최대 1GB
};


DataFile* initial()
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
        SharedMemory);

    if (hMap == NULL) //error 처리 
    {
        std::cout << "Could not find file mapping object (" << GetLastError() << ").\n";
        return NULL;
    }

    //SharedMemory에 대한 실제 메모리 매핑 
    DataFile* shared_data = (DataFile*)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    if (shared_data == NULL) //error 처리 
    {
        std::cout << "Could not map view of file (" << GetLastError() << ").\n";
        CloseHandle(hMap);
        return NULL;
    }

    return shared_data;
}

void SendFile(std::string path, DataFile*& shared_data)
{
    std::ifstream fin;

    if (WaitForSingleObject(hMutex, INFINITE) == WAIT_OBJECT_0) //lock 걸렸다면 종료까지 대기
    {
        fin.open(path, std::ios::binary);
        fin.seekg(0, std::ios::end);

        shared_data->file_size = fin.tellg();
        fin.seekg(0, std::ios::beg);

        fin.read(shared_data->buffer, shared_data->file_size);
        fin.close();

        std::cout << "File Sending is done. \n\n";

        ReleaseMutex(hMutex); //unlock 
    }
}

void RecvFile(std::string path, DataFile*& shared_data)
{
    if (shared_data->file_size != 0)
    {
        std::ofstream fout;
        fout.open(path, std::ios::binary);
        fout.write(shared_data->buffer, shared_data->file_size);
        std::cout << "Read Done \n\n";
    }
    else
    {
        std::cout << "buffer is empty! \n";
        return;
    }
}

int main()
{
    DataFile* shared_data = initial();

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
            std::cin >> path;
            std::thread file_send = std::thread(SendFile, std::ref(path), std::ref(shared_data));
            std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
            file_send.detach();
            continue;
        }
        else if (input == 'R' || input == 'r')
        {
            std::cout << "Enter New File Name : ";
            std::cin >> path;

            std::thread file_recv = std::thread(RecvFile, std::ref(path), std::ref(shared_data));
            std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
            file_recv.detach();
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

    UnmapViewOfFile(shared_data);
    CloseHandle(hMap);
    CloseHandle(hMutex);

    return 0;
}