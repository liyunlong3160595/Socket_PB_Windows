#include "Person.h"


CPerson::CPerson()
{

}

tutorial::Person CPerson::Pack()
{
	tutorial::Person MsgPerson;
	MsgPerson.set_name(this->name);
	MsgPerson.set_id(this->id);
	MsgPerson.set_email(this->email);
	return MsgPerson;
}

CPerson::~CPerson()
{
}
