#include "Chat.h"

void SendMsg(Chat* test)
{
	while (1)
	{
		DWORD cbBytes = 0;

		std::cout << "Send the message : ";

		std::getline(std::cin, test->Buffer);
		WaitForSingleObject(test->hMutex, INFINITE);

		if (!strcmp(test->Buffer.c_str(), "File Send"))
		{
			std::cout << "File Sending 구현 ~~~~~~~~ \n";
		}
		else if (!strcmp(test->Buffer.c_str(), "Data Send"))
		{
			std::cout << "Data Sending 구현 ~~~ \n";
		}

		BOOL bResult = WriteFile(
			test->hPipe_write,                // handle to pipe 
			test->Buffer.c_str(),             // buffer to write from 
			strlen(test->Buffer.c_str()) + 1,   // number of bytes to write, include the NULL
			&cbBytes,             // number of bytes written 
			NULL);                // not overlapped I/O 


		if ((!bResult) || (test->Buffer.length() + 1 != cbBytes)) //error 처리 
		{
			printf("\nError occurred while writing : %d \n", GetLastError());
			CloseHandle(test->hPipe_write);
			return;
		}
		else
			printf("Send was successful.\n");

		std::this_thread::sleep_for((std::chrono::milliseconds(100)));

		test->Buffer.clear();
		WaitForSingleObject(test->hEvent, INFINITE);
		ReleaseMutex(test->hMutex);
	}
}

void RecvMsg(Chat* test)
{
	char test_buffer[BUFFSIZE] = { 0, };

	while (1)
	{
		DWORD cbBytes = 0;
		BOOL bResult = ReadFile(
			test->hPipe_read,                // handle to pipe 
			(char*)test->Buffer.c_str(),
			BUFFSIZE,				// size of buffer 
			&cbBytes,             // number of bytes read 
			NULL);                // not overlapped I/O 

		if ((!bResult) || (cbBytes == 0)) //에러처리 
		{
			printf("\nError occurred while reading from the server: %d\n", GetLastError());
			CloseHandle(test->hPipe_read);
			return; 
		}
		if (strlen(test->Buffer.c_str()) != 0)
		{
			printf("\nRecv was successful.\n");
			std::cout << "Recved message : " << test->Buffer.c_str() << "\n";
			test->Buffer.clear();
		}
		else
			std::cout << "Buffer is Empty! \n\n";
		
		SetEvent(test->hEvent);

	}
}