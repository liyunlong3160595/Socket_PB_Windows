#include"SocketPackage.h"
#include"Person.pb.h"
#include"DefineResouce.h"
#include<string>
#include"PackAndUnpack.h"
#include<iostream>
using namespace std;
using namespace tutorial;
int main()
{
	while (1)
	{
		AddressBook addressBookSend;
		Person *personSend = addressBookSend.add_people();
		string strEmail, strId, strName,strPhoneNumber;
		cout << "请输入邮箱" << endl;
		cin >> strEmail;
		cout << "请输入ID" << endl;
		cin >> strId;
		cout << "请输入姓名" << endl;
		cin >> strName;
		cout << "请输入电话" << endl;
		cin >> strPhoneNumber;
		personSend->set_email(strEmail.c_str());
		personSend->set_id(stoi(strId));
		personSend->set_name(strName.c_str());
		Person_PhoneNumber *PhoneNumber = personSend->add_phones();
		PhoneNumber->set_type(tutorial::Person::MOBILE);
		PhoneNumber->set_number(strPhoneNumber.c_str());
		int size = addressBookSend.ByteSize();
		bool bSerializeFlag;
		char buff[1024];
		memset(buff, 0, 1024);

		CCopHead copHead;
		copHead.m_cType = PersonType;
		copHead.m_ucStoreInqury = 1;
		copHead.m_ucAddDelete = 1;
		PackHead(copHead, buff);
		if (size<1024)
		{
			bSerializeFlag = addressBookSend.SerializeToArray((void*)(buff + 8), 1024);
		}
		if (!bSerializeFlag)
		{
			return -1;
		}
		//解码调试
		/*CCopHead copHeadPack;
		char buffBody[1016];
		memset(buffBody, 0, 1016);
		UnPackHead(copHeadPack, buff, buffBody);
		AddressBook  addressBookSend1;
		bool bParse1 = addressBookSend1.ParseFromArray((void*)(buffBody), strlen(buffBody));
		Person people1 = addressBookSend1.people(0);*/
		CSocketPackage SocketPackage;
		SocketPackage.initall();

		SocketPackage.sendBuff(buff);
		cout << "是否要继续录入,是请选Y，不是请选N" << endl;
		string strContinue;
		cin >> strContinue;
		if (strContinue =="Y" || strContinue == "y")
		{
			
		}
		else if (strContinue == "N" || strContinue == "n")
		{
			break;
		}
	}
	//业务处理
	//SocketPackage.receiveBuff(SocketPackage.cBuffReceive);
	////recv(sHost, SocketPackage.cBuffReceive, sizeof(cBuffReceive), 0); ///接收
	//CCopHead copHeadPack;
	//char buffBody[1016];
	//memset(buffBody, 0, 1016);
	//UnPackHead(copHeadPack, SocketPackage.cBuffReceive, buffBody);
	//switch (copHead.cType)
	//{
	//case PersonType:
	//{
	//	AddressBook  addressBookSend;
	//	bool bParse1 = addressBookSend.ParseFromArray((void*)(buffBody), strlen(buffBody));
	//	Person people1 = addressBookSend.people(0);
	//	if (copHead.ucStoreInqury == 1)
	//	{
	//		if (copHead.ucAddDelete == 1)
	//		{
	//			//存储到内存区
	//		}
	//		else
	//		{

	//		}
	//	}
	//	else
	//	{
	//		
	//	}
	//	break;
	//}

	//default:
	//	break;
	//}
	return 0;
}