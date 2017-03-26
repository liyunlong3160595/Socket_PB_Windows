#include "SocketPackage.h"

CSocketPackage::CSocketPackage()
{
}
int CSocketPackage::initall()
{
	int iRet = 0;
	if (WSAStartup(MAKEWORD(2, 2), &(this->wsd)) != 0)
	{
		//cout << "WSAStartup failed!" << endl;
		return -1;
	}
	//SOCKET          sHost;          //服务器套接字  
	this->sHost = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sHost)
	{
		//cout << "socket failed!" << endl;
		WSACleanup();//释放套接字资源  
		return  -1;
	}
	//SOCKADDR_IN     servAddr;		//服务器地址  
	this->servAddr.sin_family = AF_INET;
	this->servAddr.sin_addr.s_addr = inet_addr("192.169.1.101");
	this->servAddr.sin_port = htons(SERVE_RECEIVE_PORT);
	iRet = connect(sHost, (LPSOCKADDR)&(this->servAddr), sizeof(this->servAddr));
	int iErr = WSAGetLastError();
	if (SOCKET_ERROR == iRet)
	{

		//cout << "connect failed!" << endl;
		closesocket(sHost); //关闭套接字  
		WSACleanup();       //释放套接字资源  
		return iRet;
	}
	return iRet;
}
int CSocketPackage::sendBuff(char* szSend)
{
	int iRet = 0;
	
	//向服务器发送数据  
	//cout << " 向服务器发送数据:  ";
	iRet = send(sHost, szSend, strlen(szSend), 0);
	if (SOCKET_ERROR == iRet)
	{
		//cout << "send failed!" << endl;
		closesocket(sHost); //关闭套接字  
		WSACleanup();       //释放套接字资源  
		return -1;
	}
	closesocket(sHost); //关闭套接字  
	WSACleanup();       //释放套接字资源  
	return 0;
}

int CSocketPackage::receiveBuff(char* szReceive)
{

	int iRet = 0;
	while (true)
	{
		//从服务器接收数据  
		iRet = recv(sHost, szReceive, 1024, 0);     // 接收服务器端的数据
		if (SOCKET_ERROR == iRet)
		{
			closesocket(sHost); //关闭套接字  
			WSACleanup();       //释放套接字资源  
			return iRet;
		}

	}
	return 0;
}
CSocketPackage::~CSocketPackage()
{
}
