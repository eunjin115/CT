#pragma once

#ifndef __CHAT__H_
#define __CHAT__H_

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <memory>
#include <mutex>

#define BUFFSIZE 1024

void SendMsg(char* Buffer, HANDLE hPipe, HANDLE hMutex, HANDLE hEvent);
void RecvMsg(char* Buffer, HANDLE hPipe, HANDLE hEvent);

struct File
{
	int file_size = 0;
	char buffer[1200000054] = { 0, }; //최대 1GB
};

class Chat
{
public:
	HANDLE hPipe1;
	HANDLE hPipe2;
	HANDLE hMap;
	HANDLE hMutex;
	HANDLE hEvent;
	char Buffer[BUFFSIZE] = { 0, };

	virtual int Initial() = 0;
	virtual void Send() = 0;
};

class Server : public Chat
{
public:
	virtual int Initial();
	virtual void Send()
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe1), std::ref(hMutex), std::ref(hEvent));
		std::thread t2 = std::thread(RecvMsg, Buffer, std::ref(hPipe2), std::ref(hEvent));
		std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
		t1.detach();
		t2.detach();
	}
};

class Client : public Chat
{
public:
	virtual int Initial();
	virtual void Send()
	{
		std::thread t1 = std::thread(SendMsg, std::ref(Buffer), std::ref(hPipe2), std::ref(hMutex), std::ref(hEvent));
		std::thread t2 = std::thread(RecvMsg, Buffer, std::ref(hPipe1), std::ref(hEvent));
		std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
		t1.detach();
		t2.detach();
	}
};

#endif