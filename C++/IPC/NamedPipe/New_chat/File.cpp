#include "Chat.h"

void SendFile(Chat* msg, std::string path, File*& shared_data)
{
    std::ifstream fin;

    if (WaitForSingleObject(msg->hMutex, INFINITE) == WAIT_OBJECT_0) //lock 걸렸다면 종료까지 대기
    {
        fin.open(path, std::ios::binary);
        fin.seekg(0, std::ios::end);

        shared_data->file_size = fin.tellg();
        fin.seekg(0, std::ios::beg);

        fin.read(shared_data->buffer, shared_data->file_size);
        fin.close();

        std::cout << "File Sending is done. \n\n";

        ReleaseMutex(msg->hMutex); //unlock 
        SetEvent(msg->hFileEvent);
    }
}

void RecvFile(Chat* msg, File* shared_data)
{
    std::string path;
    if (WaitForSingleObject(msg->hFileEvent, INFINITE) == WAIT_OBJECT_0)
    {
        std::cout << "Enter File Name : ";
        std::cin >> path;
        if (shared_data->file_size != 0)
        {
            std::ofstream fout;
            fout.open(path, std::ios::binary);
            fout.write(shared_data->buffer, shared_data->file_size);
            std::cout << "Read Done \n\n";
            memset(shared_data->buffer, 0, strlen(shared_data->buffer));
        }
        else
        {
            std::cout << "buffer is empty! \n";
            return;
        }
    }
    
}