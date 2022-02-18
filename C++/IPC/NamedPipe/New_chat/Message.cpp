#include "Chat.h"

void SendMsg(Chat* msg)
{
	std::string path;
	while (1)
	{
		DWORD cbBytes = 0;

		std::cout << "Send the message : ";

		std::getline(std::cin, msg->Buffer);
		WaitForSingleObject(msg->hMutex, INFINITE);

		BOOL bResult = WriteFile(
			msg->hPipe_write,                // handle to pipe 
			msg->Buffer.c_str(),             // buffer to write from 
			strlen(msg->Buffer.c_str()) + 1,   // number of bytes to write, include the NULL
			&cbBytes,             // number of bytes written 
			NULL);                // not overlapped I/O

		if (!strcmp(msg->Buffer.c_str(), "File Send"))
		{
			std::cout << "File Sending 구현 ~~~~~~~~ \n";
			std::cout << "Enter File name : ";
			std::cin >> path;

			std::thread file_send = std::thread(SendFile,std::ref(msg) ,std::ref(path), std::ref(msg->shared_data));
			std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
			file_send.detach();

			continue;
		}
		else if (!strcmp(msg->Buffer.c_str(), "Data Send"))
		{
			std::cout << "Data Sending 구현 ~~~ \n";
		}

		if ((!bResult) || (msg->Buffer.length() + 1 != cbBytes)) //error 처리 
		{
			printf("\nError occurred while writing : %d \n", GetLastError());
			CloseHandle(msg->hPipe_write);
			return;
		}

		msg->Buffer.clear();
		WaitForSingleObject(msg->hMsgEvent, INFINITE);
		ReleaseMutex(msg->hMutex);

	}
}

void RecvMsg(Chat* msg)
{
	while (1)
	{
		DWORD cbBytes = 0;
		BOOL bResult = ReadFile(
			msg->hPipe_read,                // handle to pipe 
			(char*)msg->Buffer.c_str(),
			BUFFSIZE,				// size of buffer 
			&cbBytes,             // number of bytes read 
			NULL);                // not overlapped I/O 

		if ((!bResult) || (cbBytes == 0)) //에러처리 
		{
			printf("\nError occurred while reading from the server: %d\n", GetLastError());
			CloseHandle(msg->hPipe_read);
			return; 
		}

		if (strlen(msg->Buffer.c_str()) != 0)
		{
			printf("\nRecv was successful.\n");
			std::cout << "Recved message : " << msg->Buffer.c_str() << "\n";
			msg->Buffer.clear();
		}
		//else
		//	std::cout << "Buffer is Empty! \n\n";
		
		SetEvent(msg->hMsgEvent);
	}
}