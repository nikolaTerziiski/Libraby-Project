#include <iostream>
#include "User.h"
#include "Vector.h"
#include "Validator.h"

class Session {
public :
	Session();

	Validator validator;
	Vector<User> allUsers;
	User user;
	bool isUserLoggedIn;

	void LogInUser();
	void LogoutUser();

	bool isLoggedUserAdministrator() { return this->user.isAdministrator(); };
private:
};