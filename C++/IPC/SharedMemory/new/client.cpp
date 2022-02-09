#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

struct TestData
{
    int file_size;
    bool type;  //0이면 server -> client, 1이면 client -> server 
    char buffer[100000000] = { 0 }; //최대 1GB
};


void SendFile(std::string path, TestData*& shared_data);
void RecvFile(TestData*& shared_data);

int main()
{
    //Named SharedMemory 정의 (두 프로세스 모두 있어야 한다) 
    LPTSTR shared_memory_1 = TEXT("SharedMemory1"); //server write to client 
    LPTSTR shared_memory_2 = TEXT("SharedMemory2"); //client write to server

    //Client는 첫 번째 SharedMemory를 open하여 사용 
    HANDLE first_hMap = OpenFileMapping( //first shared memory 
        FILE_MAP_ALL_ACCESS,
        FALSE,
        shared_memory_1);
    
    //HANDLE second_hMap = CreateFileMapping(
    //    INVALID_HANDLE_VALUE,       // use paging file
    //    NULL,                       // default security
    //    PAGE_READWRITE,             // read-write permission
    //    0,                          // maximum object size (high-order DWORD)
    //    sizeof(TestData),             // maximum object size (low-order DWORD)
    //    shared_memory_2);             // Name of FMO

    if (first_hMap == NULL) //error 처리 
    {
        printf("Could not find file mapping object (%d).\n", GetLastError());
        CloseHandle(first_hMap);
        //CloseHandle(second_hMap);
        return 1;
    }

    //SharedMemory에 대한 실제 메모리 매핑 
    void* first_pBuffer = MapViewOfFile(first_hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    //void* second_pBuffer = MapViewOfFile(second_hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    TestData* first_shared_data = (TestData*)first_pBuffer;
    //TestData* second_shared_data = (TestData*)second_pBuffer;

    char input;
    std::string path;

    while (1)
    {
        //S or R 입력받기        
        std::cout << "Please Enter Command. \n S - Send file, R - Recive file, Q - Exit \n";
        std::cin >> input;

        if (input == 'S' || input == 's')
        {
            std::cout << "Enter Path : ";
            std::cin >> path;
            SendFile(path, first_shared_data);
            continue;
        }
        else if (input == 'R' || input == 'r')
        {
            RecvFile(first_shared_data);
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

void SendFile(std::string path, TestData*& shared_data) //동기화 객체 추가하기 
{
    std::ifstream fin;

    fin.open(path, std::ios::binary);
    fin.seekg(0, std::ios::end);

    shared_data->file_size = fin.tellg();    //get file size 
    fin.seekg(0, std::ios::beg);

    fin.read(shared_data->buffer, shared_data->file_size);
    fin.close();

    std::cout << "File Sending is done. \n\n";
}


void RecvFile(TestData*& shared_data) //동기화 객체 추가하기 
{
    std::ofstream fout;

    fout.open("copy.txt", std::ios::binary);
    if (shared_data->buffer != NULL)
        fout.write(shared_data->buffer, shared_data->file_size);
    else
    {
        std::cout << "buffer is empty! \n";
        return;
    }
    std::cout << "Read Done \n\n";
}