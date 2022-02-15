#include <windows.h>

#include <iostream>
#include <string>

#include <thread>
#include <chrono>

#include <memory>
#include <mutex>

#include "Message.h"

//#define BUFFSIZE 1024 //최대 메시지 길이 1024 bytes

LPTSTR Named_pipe1 = TEXT("\\\\.\\Pipe\\MyNamedPipe1"); //server to client
LPTSTR Named_pipe2 = TEXT("\\\\.\\Pipe\\MyNamedPipe2"); //client to server
LPTSTR Mutex = TEXT("Mutex");

HANDLE hPipe1;
HANDLE hPipe2;
HANDLE hMutex;


class Chat
{
public:
	std::mutex m;
	char Buffer[BUFFSIZE] = { 0, };
	virtual int initial() = 0;
	virtual void Send() = 0;


};

class Server : public Chat
{
public:
	virtual int initial()
	{
		hPipe1 = CreateNamedPipe(
			Named_pipe1,             // pipe name 
			PIPE_ACCESS_DUPLEX,       // read/write access 
			PIPE_TYPE_MESSAGE |       // message type pipe 
			PIPE_READMODE_MESSAGE |   // message-read mode 
			PIPE_WAIT,                // blocking mode 
			PIPE_UNLIMITED_INSTANCES, // max. instances  
			BUFFSIZE,              // output buffer size 
			BUFFSIZE,              // input buffer size 
			NMPWAIT_USE_DEFAULT_WAIT, // client time-out 
			NULL);                    // default security attribute 

		if (hPipe1 == INVALID_HANDLE_VALUE) //error 
		{
			printf("\nError occurred while creating the pipe: %d \n", GetLastError());
			return -1;
		}

		std::cout << "Waiting for client connection... \n";

		if (!ConnectNamedPipe(hPipe1, NULL))
		{
			printf("\nError occurred while creating the pipe: %d \n", GetLastError());
			CloseHandle(hPipe1);
			return -1;  //Error
		}

		hPipe2 = CreateFile(
			Named_pipe2,   // pipe name 
			GENERIC_READ |  // read and write access 
			GENERIC_WRITE,
			0,              // no sharing 
			NULL,           // default security attributes
			OPEN_EXISTING,  // opens existing pipe 
			0,              // default attributes 
			NULL);          // no template file 

		if (hPipe2 == INVALID_HANDLE_VALUE) //error 
		{
			printf("\nError occurred while creating the pipe: %d \n", GetLastError());
			return -1;
		}

		//printf("\n ConnectNamedPipe() was successful. \n");
		printf("\n Server Connection was successful. \n");
		return 0;
	}
	virtual void Send()
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe1), std::ref(m));
		std::thread t2 = std::thread(RecvMsg, Buffer, std::ref(hPipe2), std::ref(m));

		std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
		t1.detach();
		t2.detach();
	}
};

class Client : public Chat
{
public:

	virtual int initial()
	{
		hPipe2 = CreateNamedPipe(
			Named_pipe2,             // pipe name 
			PIPE_ACCESS_DUPLEX,       // read/write access 
			PIPE_TYPE_MESSAGE |       // message type pipe 
			PIPE_READMODE_MESSAGE |   // message-read mode 
			PIPE_WAIT,                // blocking mode 
			PIPE_UNLIMITED_INSTANCES, // max. instances  
			BUFFSIZE,              // output buffer size 
			BUFFSIZE,              // input buffer size 
			NMPWAIT_USE_DEFAULT_WAIT, // client time-out 
			NULL);                    // default security attribute 

		if (hPipe2 == INVALID_HANDLE_VALUE) //error 
		{
			printf("\nError occurred while creating the pipe: %d \n", GetLastError());
			return -1;
		}

		hPipe1 = CreateFile(
			Named_pipe1,   // pipe name 
			GENERIC_READ |  // read and write access 
			GENERIC_WRITE,
			0,              // no sharing 
			NULL,           // default security attributes
			OPEN_EXISTING,  // opens existing pipe 
			0,              // default attributes 
			NULL);          // no template file 

		if (hPipe1 == INVALID_HANDLE_VALUE) //error 
		{
			printf("\nError occurred while creating the pipe: %d \n", GetLastError());
			return -1;
		}

		//printf("\n CreateFile() was successful.\n");
		printf("\n Client Connection was successful. \n");

		return 0;
	}

	virtual void Send()
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe2), std::ref(m));
		std::thread t2 = std::thread(RecvMsg, Buffer, std::ref(hPipe1), std::ref(m));

		std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
		t1.detach();
		t2.detach();
	}
};



int main()
{
	int type;
	std::cout << "Enter Type : 0 - Server, 1 - Client \n";
	std::cin >> type;
	std::shared_ptr<Chat> tmp;

	if (type)
		tmp = std::make_shared<Client>();
	else
		tmp = std::make_shared<Server>();

	tmp->initial(); //변수 초기화 
	
	tmp->Send();
	while (1)
	{

	}
}
