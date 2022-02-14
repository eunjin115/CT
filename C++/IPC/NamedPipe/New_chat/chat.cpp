#include <windows.h>

#include <iostream>
#include <string>

#include <thread>
#include <chrono>

#include <memory>
#include <mutex>

#include "Message.h"

#define BUFFSIZE 1024 //최대 메시지 길이 1024 bytes

//LPTSTR Named_pipe1 = TEXT("NamedPipe1"); //server to client
//LPTSTR Named_pipe2 = TEXT("NamedPipe2"); //client to server

//얘네는 왜 이름이 꼭 이래야 하는 겨?
LPTSTR Named_pipe1 = TEXT("\\\\.\\Pipe\\MyNamedPipe"); //server to client
LPTSTR Named_pipe2 = TEXT("\\\\.\\Pipe\\MyNamedPipe"); //client to server


HANDLE hPipe1;
HANDLE hPipe2;

class Chat
{
public:
	char Buffer[BUFFSIZE];
	std::mutex m;

	void Send(HANDLE hPipe)
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe), std::ref(m));
		//t1.join();
		t1.detach();
		//while (1)
		//{
		//	std::lock_guard<std::mutex> lockguard(m);
		//	printf("Send the message to other : ");

		//	DWORD cbBytes;
		//	std::cin >> Buffer;
		//	BOOL bResult = WriteFile(
		//		hPipe,                // handle to pipe 
		//		Buffer,             // buffer to write from 
		//		strlen(Buffer) + 1,   // number of bytes to write, include the NULL
		//		&cbBytes,             // number of bytes written 
		//		NULL);                // not overlapped I/O 
		//	if ((!bResult) || (strlen(Buffer) + 1 != cbBytes))
		//	{
		//		printf("\nError occurred while writing to the server: %d", GetLastError());
		//		CloseHandle(hPipe);
		//		return;  //Error
		//	}
		//	else
		//	{
		//		printf("\nWriteFile() was successful.");
		//	}
		//	memset(Buffer, 0, sizeof(Buffer));

		//}
		
	}
	void Recv(HANDLE hPipe)
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe), std::ref(m));
		//t1.join();
		t1.detach();
		//DWORD cbBytes;
		//while (1)
		//{
		//	std::lock_guard<std::mutex> lockguard(m);

		//	BOOL bResult = ReadFile(
		//		hPipe,                // handle to pipe 
		//		Buffer,             // buffer to receive data 
		//		sizeof(Buffer),     // size of buffer 
		//		&cbBytes,             // number of bytes read 
		//		NULL);                // not overlapped I/O 

		//	if ((!bResult) || (0 == cbBytes))
		//	{
		//		printf("\nError occurred while reading from the server: %d", GetLastError());
		//		CloseHandle(hPipe);
		//		return;  //Error
		//	}
		//	else
		//	{
		//		printf("\nReadFile() was successful.");
		//	}

		//	std::cout << "Recved message : " << Buffer << "\n";
		//	memset(Buffer, 0, sizeof(Buffer));

		//}
		
	}

	virtual int test()
	{
		std::cout << "TEST \n\n";
		return 999;
	}
};

class Server : public Chat
{
public:
	virtual int test()
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

		printf("\nConnectNamedPipe() was successful. \n");
		return 0;
	}
};

class Client : public Chat
{
public:

	virtual int test()
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

		printf("\nCreateFile() was successful.\n");
		return 0;
	}
};


int main()
{

	//type 입력받고 그 type이 client인지 server인지 확인한 다음 instance 따로 만들어서 진행 
	int type;
	std::cout << "Enter Type : 0 - Server, 1 - Client \n";
	std::cin >> type;
	std::shared_ptr<Chat> tmp;

	if (type)
		tmp = std::make_shared<Client>();
	else
		tmp = std::make_shared<Server>();

	char input;
	std::string path;
	tmp->test();
	//tmp->Send(hPipe1); //client to server 
	//tmp->Recv(hPipe2);

	while (1)
	{
		if (type)
		{
			tmp->Send(hPipe1); //client to server 
			tmp->Recv(hPipe2);
		}
		else
		{
			tmp->Send(hPipe2);
			tmp->Recv(hPipe1);

		}
	}

	return 0;
}