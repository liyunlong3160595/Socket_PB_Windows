#pragma once
#include<string>
class CPhoneNumber
{
public:
	std::string number;
	enum PhoneType {
		MOBILE = 0,
		HOME = 1,
		WORK = 2,
	} enumPhoneType;
	CPhoneNumber();
	~CPhoneNumber();
};

