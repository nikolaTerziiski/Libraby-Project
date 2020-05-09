#include <iostream>
#include "String.h"
#include "Vector.h"
#include "User.h"
#pragma once
class Validator {
public:
	Validator();

	bool DoesUserExists(String& name, Vector<User>& allPeople);

	bool DoesMovieExists(String& name);
};