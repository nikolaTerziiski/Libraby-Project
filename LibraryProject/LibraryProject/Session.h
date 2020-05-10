#pragma once
#include <iostream>
#include "User.h"
#include "Vector.h"
#include "Validator.h"
#include "Book.h"
class Session {
public :
	Session();
	User user;
	Vector<User> allUsers;
	Vector<Book> books;

	Validator validator;

	bool isUserLoggedIn;

	void LogInUser();
	void LogoutUser();
	void AdminUsersControl();

	void BookSplit();
	void RestartProgramFiles(String& path);
private:
	void AdminAddUser();
	void AdminRemoveUser();
};