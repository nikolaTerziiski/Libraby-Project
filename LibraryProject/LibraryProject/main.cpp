#include <iostream>
#include "fstream"
#include "Vector.h"
#include "String.h"
#include "User.h"
#include "Session.h"

int main() {
	Session session;
	String path = "newUsers.txt";
	session.RestartProgramFiles(path);

	std::cout << "If you want the program to end write : \"exit\"" << std::endl;
	int actualIndex = 0;
	String command;
	do
	{
		command = "";
		std::cout << "Enter command: ";
		std::cin >> command;
		if (command == "")
		{
			continue;
		}/*
		String command = takeArgument(actualIndex, )*/
		if (command == "login")
		{
			session.LogInUser();
		}
		else if (command == "logout")
		{
			session.LogoutUser();
		}
		else if (command == "users")
			session.AdminUsersControl();
		else if (command == "books") 
			session.BookSplit();
		

	} while (!(command == "exit"));
}