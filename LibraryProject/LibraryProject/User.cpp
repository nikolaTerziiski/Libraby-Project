#include <iostream>
#include "User.h"

User::User() {
	this->name = "";
	this->password = "";
}

User::User(String name, String password)
{
	this->name = name;
	this->password = password;
}

User::User(const User& other)
{
	this->name = other.name;
	this->password = other.password;
}

User& User::operator=(const User& other)
{
	this->name = other.name;
	this->password = other.password;
	return *this;
}

std::istream & operator>>(std::istream &in, User & user)
{
	in >> user.name >> user.password;
	return in;
}
