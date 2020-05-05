#include <iostream>
#include "String.h"
#include "Vector.h"
#include "User.h"
#pragma once
class Validator {
public:
	Validator();

	bool DoesUserExists(String& name, String& password, Vector<User>& allPeople);
};