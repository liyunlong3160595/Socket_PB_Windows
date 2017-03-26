#pragma once
#include<string>
using namespace std;
#include"Person.pb.h"
class CPerson
{
public:
	string name;
	int id;  // Unique ID number for this person.
	string email;

	/*enum  PhoneType{
		MOBILE = 0,
		HOME = 1,
		WORK = 2,
	}*/
	tutorial::Person  Pack();
	CPerson();
	~CPerson();
};

