#include "Chat.h"

LPTSTR Named_pipe1 = TEXT("\\\\.\\Pipe\\MyNamedPipe1"); //server to client
LPTSTR Named_pipe2 = TEXT("\\\\.\\Pipe\\MyNamedPipe2"); //client to server

LPTSTR Mutex = TEXT("Mutex");
LPTSTR SharedMemory = TEXT("SharedMemory");
LPTSTR Event = TEXT("Event");

int Server::Initial() //생성자로 변경해도 될 것 같다
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

	hMutex = CreateMutex(
		NULL,
		FALSE,
		Mutex);

	hEvent = CreateEvent(NULL, TRUE, FALSE, Event);

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

	printf("\n Server Connection was successful. \n");
	return 0;
}

int Client::Initial()
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

	hMutex = OpenMutex(
		MUTEX_ALL_ACCESS,
		FALSE,
		Mutex
	);

	hEvent = OpenEvent(EVENT_ALL_ACCESS, TRUE, Event);

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

	printf("\n Client Connection was successful. \n");

	return 0;
}