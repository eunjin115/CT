#include "Chat.h"

LPTSTR Named_pipe1 = TEXT("\\\\.\\Pipe\\MyNamedPipe1"); //server to client
LPTSTR Named_pipe2 = TEXT("\\\\.\\Pipe\\MyNamedPipe2"); //client to server

LPTSTR Mutex = TEXT("Mutex");
LPTSTR SharedMemory = TEXT("SharedMemory");
LPTSTR Event = TEXT("Event");

int Server::Initial() //생성자로 변경해도 될 것 같다
{
	hPipe_write = CreateNamedPipe(
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

	hMsgEvent = CreateEvent(NULL, TRUE, FALSE, Event);
	hFileEvent = CreateEvent(NULL, TRUE, FALSE, Event);

	if (hPipe_write == INVALID_HANDLE_VALUE) //error 
	{
		printf("\nError occurred while creating the pipe: %d \n", GetLastError());
		return -1;
	}

	std::cout << "Waiting for client connection... \n";

	if (!ConnectNamedPipe(hPipe_write, NULL))
	{
		printf("\nError occurred while creating the pipe: %d \n", GetLastError());
		CloseHandle(hPipe_write);
		return -1;  //Error
	}

	hPipe_read = CreateFile(
		Named_pipe2,   // pipe name 
		GENERIC_READ |  // read and write access 
		GENERIC_WRITE,
		0,              // no sharing 
		NULL,           // default security attributes
		OPEN_EXISTING,  // opens existing pipe 
		0,              // default attributes 
		NULL);          // no template file 

	if (hPipe_read == INVALID_HANDLE_VALUE) //error 
	{
		printf("\nError occurred while creating the pipe: %d \n", GetLastError());
		return -1;
	}

	HANDLE hMap = CreateFileMapping( //first shared memory 
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		sizeof(File),
		SharedMemory);

	if (hMap == NULL) //error 처리 
	{
		std::cout << "Could not find file mapping object (" << GetLastError() << ").\n";
		return -1;
	}

	//SharedMemory에 대한 실제 메모리 매핑 
	shared_data = (File*)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	if (shared_data == NULL)
	{
		std::cout << "Could not map view of file (" << GetLastError() << ").\n";
		CloseHandle(hMap);
		return -1;
	}

	printf("\n Server Connection was successful. \n");
	return 0;
}

int Client::Initial()
{
	hPipe_write = CreateNamedPipe(
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

	hMsgEvent = OpenEvent(EVENT_ALL_ACCESS, TRUE, Event);
	hFileEvent = OpenEvent(EVENT_ALL_ACCESS, TRUE, Event);

	if (hPipe_write == INVALID_HANDLE_VALUE) //error 
	{
		printf("\nError occurred while creating the pipe: %d \n", GetLastError());
		return -1;
	}

	hPipe_read = CreateFile(
		Named_pipe1,   // pipe name 
		GENERIC_READ |  // read and write access 
		GENERIC_WRITE,
		0,              // no sharing 
		NULL,           // default security attributes
		OPEN_EXISTING,  // opens existing pipe 
		0,              // default attributes 
		NULL);          // no template file 

	if (hPipe_read == INVALID_HANDLE_VALUE) //error 
	{
		printf("\nError occurred while creating the pipe: %d \n", GetLastError());
		return -1;
	}
	std::this_thread::sleep_for((std::chrono::milliseconds(100)));
	//Client는 SharedMemory를 open하여 사용 
	HANDLE hMap = OpenFileMapping( //first shared memory 
		FILE_MAP_ALL_ACCESS,
		FALSE,
		SharedMemory);

	if (hMap == NULL) //error 처리 
	{
		std::cout << "Could not find file mapping object (" << GetLastError() << ").\n";
		return -1;
	}

	//SharedMemory에 대한 실제 메모리 매핑 
	 shared_data = (File*)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	if (shared_data == NULL) //error 처리 
	{
		std::cout << "Could not map view of file (" << GetLastError() << ").\n";
		CloseHandle(hMap);
		return -1;
	}


	printf("\n Client Connection was successful. \n");

	return 0;
}