#include "Chat.h"


void SendMsg(char* Buffer, HANDLE hPipe, HANDLE hMutex, HANDLE hEvent)
{
	while (1)
	{
		WaitForSingleObject(hMutex, INFINITE);

		printf("Send the message to other : ");

		DWORD cbBytes = 0;
		std::cin.getline(Buffer, BUFFSIZE);
		
		if (strcmp(Buffer, "File Send"))
		{
			std::cout << "File Sending 구현 ~~~~~~~~ \n";
			//std::thread file_send = 
		}
		else if (Buffer, "Data Send")
		{

		}
		BOOL bResult = WriteFile(
			hPipe,                // handle to pipe 
			Buffer,             // buffer to write from 
			strlen(Buffer) + 1,   // number of bytes to write, include the NULL
			&cbBytes,             // number of bytes written 
			NULL);                // not overlapped I/O 

		if ((!bResult) || (strlen(Buffer) + 1 != cbBytes)) //error 처리 
		{
			printf("\nError occurred while writing : %d \n", GetLastError());
			CloseHandle(hPipe);
			return; 
		}
		else
			printf("Send was successful.\n");

		std::this_thread::sleep_for((std::chrono::milliseconds(100)));

		memset(Buffer, 0, BUFFSIZE);
		WaitForSingleObject(hEvent, INFINITE);
		ReleaseMutex(hMutex);

	}

}

void RecvMsg(char* Buffer, HANDLE hPipe, HANDLE hEvent)
{

	while (1)
	{

		DWORD cbBytes = 0;
		BOOL bResult = ReadFile(
			hPipe,                // handle to pipe 
			Buffer,             // buffer to receive data 
			1024,     // size of buffer 
			&cbBytes,             // number of bytes read 
			NULL);                // not overlapped I/O 

		if ((!bResult) || (cbBytes == 0))
		{
			printf("\nError occurred while reading from the server: %d\n", GetLastError());
			CloseHandle(hPipe);
			return;  //Error
		}


		if (strlen(Buffer) != 0)
		{
			printf("\nRecv was successful.\n");
			std::cout << "Recved message : " << Buffer << "\n";
			std::this_thread::sleep_for((std::chrono::milliseconds(100)));

			memset(Buffer, 0, BUFFSIZE);
		}
		SetEvent(hEvent);

	}
}