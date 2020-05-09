#include <fstream>
#include <iostream>
#include "Vector.h"
#include "User.h"

#pragma once
namespace data {
	Vector<User>& allUsersFromData(Vector<User>& vector) {
		Vector<User> result;
		std::ifstream in;
		Vector<User> allUsers;
		in.open("newUsers.txt", std::ios::in);
		if (!in)
		{
			std::cout << "There are no users in the file" << std::endl;
			return result;
		}
		User temp;
		in >> temp;
		while (!(temp.getName() == "" && temp.getPassword() == ""))
		{
			result.push_back(temp);
			temp = User();
			in >> temp;
		}
		in.close();
		vector = result;
		return vector;
	};
	String insertUsername(String& username) {
		while (username.length() == 0)
		{
			username = "";
			std::cout << "Enter username: ";
			std::cin >> username;
			if (username.length() == 0)
			{
				std::cout << "Invalid username! Username must be atleast 1 character!" << std::endl;
				continue;
			}
		}
		return username;
	}
	String insertPassword(String& password) {
		while (password.length() == 0)
		{
			password = "";
			std::cout << "Enter password: ";
			std::cin >> password;
			if (password.length() == 0)
			{
				std::cout << "Invalid password! Password must be atleast 1 character!"<<std::endl;
				continue;
			}
		}
		return password;
	}
}