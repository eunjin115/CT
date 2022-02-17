#ifndef __CLASS_H__
#define __CLASS_H__

#include <windows.h>

#include <iostream>
#include <fstream>
#include <string>

#include <thread>
#include <chrono>

#include <memory>
#include <mutex>

#define BUFFSIZE 1024

LPTSTR Named_pipe1 = TEXT("\\\\.\\Pipe\\MyNamedPipe1"); //server to client
LPTSTR Named_pipe2 = TEXT("\\\\.\\Pipe\\MyNamedPipe2"); //client to server

LPTSTR Mutex = TEXT("Mutex");
LPTSTR SharedMemory = TEXT("SharedMemory");
LPTSTR Event = TEXT("Event");

HANDLE hPipe1;
HANDLE hPipe2;
HANDLE hMap;
HANDLE hMutex;
HANDLE hEvent;

struct File
{
	int file_size = 0;
	char buffer[1200000054] = { 0, }; //최대 1GB
};

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
	virtual int initial();
	virtual void Send()
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe1), std::ref(m));
		std::thread t2 = std::thread(RecvMsg, Buffer, std::ref(hPipe2));

		std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
		t1.detach();
		t2.detach();
	}
};

class Client : public Chat
{
public:

	virtual int initial();

	virtual void Send()
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe2), std::ref(m));
		std::thread t2 = std::thread(RecvMsg, Buffer, std::ref(hPipe1));

		std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
		t1.detach();
		t2.detach();

	}
};

#endif