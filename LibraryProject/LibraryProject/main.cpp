#include <iostream>
#include "fstream"
#include "Vector.h"
#include "String.h"
#include "User.h"
#include "Session.h"

int main() {
	std::cout << "If you want the program to end write : \"exit\"" << std::endl;
	int actualIndex = 0;
	String command;
	Session session;
	do
	{
		std::cin >> command;/*
		String command = takeArgument(actualIndex, )*/
		if (command == "login")
		{
			session.LogInUser();
		}
		else if (command == "logout")
		{
			session.LogoutUser();
		}
	} while (!(command == "exit"));
}