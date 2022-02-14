void SendMsg(char* Buffer, HANDLE hPipe, std::mutex &m)
{
	std::lock_guard<std::mutex> lockguard(m);

	printf("Send the message to other : ");

	DWORD cbBytes;
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
		printf("\nWriteFile() was successful.");
	}
	memset(Buffer, 0, sizeof(Buffer));
}

void RecvMsg(char* Buffer, HANDLE hPipe, std::mutex& m)
{
	std::lock_guard<std::mutex> lockguard(m);
	DWORD cbBytes;

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
		printf("\nReadFile() was successful.\n");
	}

	std::cout << "Recved message : " << Buffer << "\n";
	memset(Buffer, 0, sizeof(Buffer));
}