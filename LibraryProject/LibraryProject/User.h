#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "String.h"
#pragma once
class User {
public:
	User();
	User(String name, String password);
	User(const User& other);
	
	String getName() { return name; }
	String getPassword() { return password; }
	bool isAdministrator() { return name == "admin" ? true : false; }

	User& operator= (const User& other);

	friend std::istream& operator>> (std::istream&, User &user);
	

private:
	String name;
	String password;
};
#endif