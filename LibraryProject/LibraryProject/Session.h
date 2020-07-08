#pragma once
#include <iostream>
#include "User.h"
#include "Vector.h"
#include "Validator.h"
#include "Book.h"
class Session {
public :
	String filePath;
	Session(String& path);
	User user;
	Vector<User> allUsers;
	Vector<Book> allBooksFromFile;

	Validator validator;

	bool isUserLoggedIn;

	void LogInUser();
	void LogoutUser();
	void AdminUsersControl(String& path);

	void BookSplit();

	void SaveBooks(String& path);
private:
	void AdminAddUser();
	void AdminRemoveUser();
};