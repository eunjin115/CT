#define BUFFSIZE 1024 //최대 메시지 길이 1024 bytes

HANDLE hMutex;
HANDLE hEvent;

void SendMsg(char* Buffer, HANDLE hPipe, std::mutex& m)
{
	//1024bytes 의 LPDWORD 만들어야 함 
	while (1)
	{
		WaitForSingleObject(hMutex, INFINITE);

		printf("Send the message to other : ");

		//DWORD cbBytes; //4bytes씩 읽게 되어있다 
		DWORD cbBytes = 0;
		std::cin >> Buffer;
		BOOL bResult = WriteFile(
			hPipe,                // handle to pipe 
			Buffer,             // buffer to write from 
			strlen(Buffer) + 1,   // number of bytes to write, include the NULL
			&cbBytes,             // number of bytes written 
			NULL);                // not overlapped I/O 

		if ((!bResult) || (strlen(Buffer) + 1 != cbBytes))
		{
			printf("\nError occurred while writing : %d \n", GetLastError());
			CloseHandle(hPipe);
			return;  //Error
		}
		else
		{
			printf("\n Send was successful. \n");
		}
		std::this_thread::sleep_for((std::chrono::milliseconds(100)));

		memset(Buffer, 0, BUFFSIZE);
		WaitForSingleObject(hEvent, INFINITE);
		ReleaseMutex(hMutex);

	}

}

void RecvMsg(char* Buffer, HANDLE hPipe) //event필요할까..? 
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

		std::cout << "cbBytes : " << cbBytes << "\n \n";
		if ((!bResult) || (cbBytes == 0))
		{
			printf("\nError occurred while reading from the server: %d \n", GetLastError());
			CloseHandle(hPipe);
			return;  //Error
		}


		if (strlen(Buffer) != 0)
		{
			printf("\n Recv was successful.\n");
			std::cout << "Recved message : " << Buffer << "\n"; 
			std::this_thread::sleep_for((std::chrono::milliseconds(100)));

			memset(Buffer, 0, BUFFSIZE);
		}
		SetEvent(hEvent);

	}
}