#pragma once
#include"DefineResouce.h"
#include "winsock2.h"  
#include <iostream>  
#include<Windows.h>
#include"errno.h"
#include "spdlog/spdlog.h"
#pragma comment(lib,"ws2_32.lib")
class CSocketPackage
{
public:
	WSADATA         wsd;            //WSADATA变量  
	SOCKET          sHost;          //服务器套接字 
	SOCKADDR_IN     servAddr;		//服务器地址 
	char cBuffSend[BUF_SIZE];
	char cBuffReceive[BUF_SIZE];
	int initall();
	int sendBuff(char*);
	int receiveBuff(char*);
	CSocketPackage();
	~CSocketPackage();
};

