#include <iostream>
#include "fstream"
#include "Vector.h"
#include "String.h"
#include "User.h"
#include "Session.h"

void PrintCommandsForLibrary() {
	std::cout << "Here are the commands you can do:" << std::endl;
	std::cout << "You have to be logged in to make this operations:" << std::endl;
	std::cout << "You can add or remove users only if you are admin - users add | remove (name)" << std::endl;
	std::cout << "You can add or remove books only if you are admin" << std::endl;
	std::cout << "You can view all books, find one book and sort books by criteria \n" << std::endl;

	std::cout << "If you are not logged in or you dont have account - ask the administrator to create account for you.If you have \n account you can sign in by typing log in and writing the correct information" << std::endl;

}
int Engine(String& path) {
	Session session(path);

	//At the very beginning i check if the file exists. If it doesnt i made the function to return a int. So i return 1 if it doesnt exists
	std::ifstream in;
	in.open(path.data, std::ios::in);
	if (in.fail())
	{
		return 1;
	}
	session.RestartProgramFiles(path);
	std::cout << "If you want the program to end write : \"close\"" << std::endl;
	PrintCommandsForLibrary();
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
			session.AdminUsersControl(path);
		else if (command == "books")
			session.BookSplit();
		else
		{
			std::cout << "Invalid command! \n";
		}
	} while (!(command == "close"));
}
int main() {
	String command;
	do
	{
		command = "";
		std::cin >> command;
		if (command == "open")
		{
			String path;
			std::cin >> path;

			//Making local check if the file exists
			int result = Engine(path);
			if (result == 1)
			{
				std::cout << "The file with name " << path << " doesn't exist" << std::endl;
				return 0;
			}
		}
		else if (command == "help")
		{
			std::cout << "The following commands are supported" << std::endl;
			std::cout << "open <file>(supported only for users) - opens <file>" << std::endl;
			std::cout << "close		- closes the currently open file(for users)" << std::endl;
			std::cout << "exit		- closes the program" << std::endl;
			std::cout << "help		- prints the information about the commands" << std::endl;
		}
	} while (!(command == "exit"));
}