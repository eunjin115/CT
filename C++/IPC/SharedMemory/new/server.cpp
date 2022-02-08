#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>

#pragma warning(disable:4996)

struct TestData
{
    bool type = false;  //0이면 server -> client, 1이면 client -> server 
    char buffer[100000000] = { 0, }; //최대 1GB
};

void SendFile(std::string path, TestData* &shared_data);

int main()
{
    //FMO = File Mapping Object
    //Named SharedMemory 정의 (두 프로세스 모두 있어야 한다) 
	LPTSTR shared_memory_1 = TEXT("SharedMemory1"); //server write to client 
	LPTSTR shared_memory_2 = TEXT("SharedMemory2"); //client write to server

    //Server는 첫 번째 SharedMemory만을 생성
    HANDLE first_hMap = CreateFileMapping( //first shared memory 
        INVALID_HANDLE_VALUE, 
        NULL,
        PAGE_READWRITE,
        0,
        sizeof(TestData),
        shared_memory_1);

    if (shared_memory_1 == NULL) //error 처리 
    {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    //SharedMemory에 대한 실제 메모리 매핑 
    void* first_pBuffer = MapViewOfFile(shared_memory_1, FILE_MAP_ALL_ACCESS, 0, 0, 0); 

    TestData* first_shared_data = (TestData*)first_pBuffer;

    char input;
    std::string path;
    while (1)
    {
        //S or R 입력받기        
        std::cout << "Please Enter Command. \n S - Send file, R - Recive file, Q - Exit \n";
        std::cin >> input;

        if (input == 'S' || input == 's') //switch문으로,, 바꿔야 하나,, 
        {
            std::cout << "Enter Path : ";
            std::cin >> path;

            SendFile(path, first_shared_data);
        }
        else if (input == 'R' || input == 'r')
        {
            std::cout << "구현하기~~~~~~~~~~ \n";
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

void SendFile(std::string path, TestData* &shared_data) //동기화 객체 추가하기 
{
    std::ifstream fin;
    int file_size = 0;
    
    fin.open(path, std::ios::binary);
    fin.seekg(0, std::ios::end);
    file_size = fin.tellg();    //get file size
    char* tmp = new char[file_size + 1];
    fin.seekg(0, std::ios::beg);

    fin.read(tmp, file_size);
    CopyMemory(shared_data->buffer, tmp, file_size);
    fin.close();

    std::cout << "File Write Done \n\n";

}