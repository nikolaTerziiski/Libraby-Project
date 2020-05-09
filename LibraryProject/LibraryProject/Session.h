#include <iostream>
#include "User.h"
#include "Vector.h"
#include "Validator.h"
#pragma once
class Session {
public :
	Session();
	User user;
	Vector<User> allUsers;


	Validator validator;

	bool isUserLoggedIn;

	void LogInUser();
	void LogoutUser();
	void AdminUsersControl();

	void RestartUsers();
	void BookSplit();

private:
	void AdminAddUser();
	void AdminRemoveUser();
};