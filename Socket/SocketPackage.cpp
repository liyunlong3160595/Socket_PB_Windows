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
	//SOCKET          sHost;          //�������׽���  
	this->sHost = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sHost)
	{
		//cout << "socket failed!" << endl;
		WSACleanup();//�ͷ��׽�����Դ  
		return  -1;
	}
	//SOCKADDR_IN     servAddr;		//��������ַ  
	this->servAddr.sin_family = AF_INET;
	this->servAddr.sin_addr.s_addr = inet_addr("192.169.1.101");
	this->servAddr.sin_port = htons(SERVE_RECEIVE_PORT);
	iRet = connect(sHost, (LPSOCKADDR)&(this->servAddr), sizeof(this->servAddr));
	int iErr = WSAGetLastError();
	if (SOCKET_ERROR == iRet)
	{

		//cout << "connect failed!" << endl;
		closesocket(sHost); //�ر��׽���  
		WSACleanup();       //�ͷ��׽�����Դ  
		return iRet;
	}
	return iRet;
}
int CSocketPackage::sendBuff(char* szSend)
{
	int iRet = 0;
	
	//���������������  
	//cout << " ���������������:  ";
	iRet = send(sHost, szSend, strlen(szSend), 0);
	if (SOCKET_ERROR == iRet)
	{
		//cout << "send failed!" << endl;
		closesocket(sHost); //�ر��׽���  
		WSACleanup();       //�ͷ��׽�����Դ  
		return -1;
	}
	closesocket(sHost); //�ر��׽���  
	WSACleanup();       //�ͷ��׽�����Դ  
	return 0;
}

int CSocketPackage::receiveBuff(char* szReceive)
{

	int iRet = 0;
	while (true)
	{
		//�ӷ�������������  
		iRet = recv(sHost, szReceive, 1024, 0);     // ���շ������˵�����
		if (SOCKET_ERROR == iRet)
		{
			closesocket(sHost); //�ر��׽���  
			WSACleanup();       //�ͷ��׽�����Դ  
			return iRet;
		}

	}
	return 0;
}
CSocketPackage::~CSocketPackage()
{
}
