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



struct File
{
	int file_size = 0;
	char buffer[1200000054] = { 0, }; //최대 1GB
};

class Chat
{
public:
	HANDLE hPipe_write;
	HANDLE hPipe_read;
	HANDLE hMap;
	HANDLE hMutex;
	HANDLE hEvent;

	std::string Buffer;

	virtual int Initial() = 0;
	virtual void Send() = 0;
};
void SendMsg(Chat* test);
void RecvMsg(Chat* test);
class Server : public Chat
{
public:
	virtual int Initial();
	virtual void Send()
	{
		std::thread t1 = std::thread(SendMsg, this);
		std::thread t2 = std::thread(RecvMsg, this);
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
		std::thread t1 = std::thread(SendMsg, this);
		std::thread t2 = std::thread(RecvMsg, this);
		std::this_thread::sleep_for((std::chrono::milliseconds(1000)));
		t1.detach();
		t2.detach();
	}
};

#endif