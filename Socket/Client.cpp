
#include "winsock2.h"  
#include <iostream>  
#include<Windows.h>
#include"errno.h"

#pragma comment(lib, "ws2_32.lib")  
using namespace std;

//BOOL    RecvLine(SOCKET s, char* buf);  //��ȡһ������  
int main(int argc, char* argv[])
{
	//extern int errno;
	//Sleep(10000);
	const int BUF_SIZE = 1024;
	WSADATA         wsd;            //WSADATA����  
	SOCKET          sHost;          //�������׽���  
	SOCKADDR_IN     servAddr;       //��������ַ  
	char            buf[BUF_SIZE];  //�������ݻ�����  
	char            bufRecv[BUF_SIZE];
	int             retVal;         //����ֵ  

	//��ʼ���׽��ֶ�̬��  
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return -1;
	}

	//�����׽���  
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//�ͷ��׽�����Դ  
		return  -1;
	}
	perror("\n test");
	//���÷�������ַ  
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("192.168.1.100");
	servAddr.sin_port = htons(8887);
	int nServAddlen = sizeof(servAddr);
	//���ӷ�����  
	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr));
	int err = GetLastError();
	perror("\n connect");
	//errno = 2;
	if (SOCKET_ERROR == retVal)
	{
		cout << "connect failed!" << endl;
		closesocket(sHost); //�ر��׽���  
		WSACleanup();       //�ͷ��׽�����Դ  
		return -1;
	}
	while (true){
		//���������������  
		ZeroMemory(buf, BUF_SIZE);
		cout << " ���������������:  ";
		cin >> buf;
		retVal = send(sHost, buf, strlen(buf), 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "send failed!" << endl;
			closesocket(sHost); //�ر��׽���  
			WSACleanup();       //�ͷ��׽�����Դ  
			return -1;
		}
		//RecvLine(sHost, bufRecv);  
		//recv(sHost, bufRecv, 5, 0);     // ���շ������˵����ݣ� ֻ����5���ַ�  
		//cout << endl << "�ӷ������������ݣ�" << bufRecv;
	}
	//�˳�  
	closesocket(sHost); //�ر��׽���  
	WSACleanup();       //�ͷ��׽�����Դ  
	return 0;
}