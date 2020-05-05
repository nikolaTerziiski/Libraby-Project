#include <fstream>
#include <iostream>
#include "Vector.h"
#include "User.h"

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
}