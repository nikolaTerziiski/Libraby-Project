#include "Session.h"
#include "TextData.h"

Session::Session() {
	this->allUsers = data::allUsersFromData(this->allUsers);
	this->isUserLoggedIn = false;
};

void Session::LogoutUser()
{
	if (this->isUserLoggedIn == false)
	{
		std::cout << "You are not logged in to logout."<< std::endl;
		return;
	}
}

void Session::LogInUser()
{
	String name, password;
	std::cout << "Enter username: ";
	std::cin >> name;

	std::cout << "Enter password: ";
	std::cin >> password;

	if (this->isUserLoggedIn)
	{
		std::cout << "There is user already logged in!" << std::endl;
		return;
	}
	if (this->validator.DoesUserExists(name,password,this->allUsers))
	{
		this->user = User(name, password);
		std::cout << "User {" << this->user.getName() << "} succesfully logged in!" << std::endl;
		this->isUserLoggedIn = true;
		return;
	}
	std::cout << "Invalid username or password!" << std::endl;
}

