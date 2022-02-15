#define BUFFSIZE 1024 //최대 메시지 길이 1024 bytes
void SendMsg(char* Buffer, HANDLE hPipe, std::mutex& m)
//void SendMsg(char* Buffer, HANDLE hPipe, HANDLE& hMutex)
{
	//1024bytes 의 LPDWORD 만들어야 함 
	while (1)
	{
		{
			std::lock_guard<std::mutex> lockguard(m);
			printf("Send the message to other : ");

			//DWORD cbBytes; //4bytes씩 읽게 되어있다 
			DWORD cbBytes = BUFFSIZE;
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
				printf("\nSend was successful. \n");
			}
		}
	}

}

//void RecvMsg(char* Buffer, HANDLE hPipe, HANDLE& hMutex) //event필요할까..? 
void RecvMsg(char* Buffer, HANDLE hPipe, std::mutex& m) //event필요할까..? 
{
	while (1)
	{
		{
			//std::lock_guard<std::mutex> lockguard(m);
			//DWORD cbBytes; //4bytes씩 읽게 되어있다 
			DWORD cbBytes = BUFFSIZE;

			BOOL bResult = ReadFile(
				hPipe,                // handle to pipe 
				Buffer,             // buffer to receive data 
				sizeof(Buffer),     // size of buffer 
				&cbBytes,             // number of bytes read 
				NULL);                // not overlapped I/O 

			if ((!bResult) || (0 == cbBytes))
			{
				printf("\nError occurred while reading from the server: %d \n", GetLastError());
				CloseHandle(hPipe);
				return;  //Error
			}
			else
			{
				printf("\n Recv was successful.\n");
			}

			std::cout << "Recved message : " << Buffer << "\n"; //자꾸 4bytes씩 읽음 
			memset(Buffer, 0, sizeof(Buffer));
		}
	}
}