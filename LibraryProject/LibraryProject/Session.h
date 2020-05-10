#pragma once
#include <iostream>
#include "User.h"
#include "Vector.h"
#include "Validator.h"
#include "Book.h"
class Session {
public :
	Session(String& path);
	User user;
	Vector<User> allUsers;
	Vector<Book> books;

	Validator validator;

	bool isUserLoggedIn;

	void LogInUser();
	void LogoutUser();
	void AdminUsersControl(String& path);

	void BookSplit();
	void RestartProgramFiles(String& path);
private:
	void AdminAddUser(String& path);
	void AdminRemoveUser(String& path);
};