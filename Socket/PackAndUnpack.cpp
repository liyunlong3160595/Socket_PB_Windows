#include"PackAndUnpack.h"
//���ַ����м�����ͷ  buffΪ����ַ���
void PackHead(CCopHead copHead, char buff[1024])
{
	char buffHead[8];
	memset(buffHead, 0, 8);
	strncpy(buffHead, (char*)&copHead, strlen((char*)&copHead));
	strncpy(buff, buffHead, 8);
}

void UnPackHead(CCopHead &copHead, char *buff, char *buffBody)
{
	memset(buffBody, 0, sizeof(buffBody));
	//char *buffHeadPack = new char[8];
	//memset(buffHeadPack, 0, 8);
	//strncpy(buffHeadPack, buff, 8);
	strncpy((char*)(&copHead), buff, 8);
	strncpy(buffBody, buff + 8, strlen(buff + 8));
}