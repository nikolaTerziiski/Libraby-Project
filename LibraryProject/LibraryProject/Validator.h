#include <iostream>
#include "String.h"
#include "Vector.h"
#include "User.h"
#include "Book.h"
#pragma once
class Validator {
public:
	Validator();

	bool DoesUserExistsLogIn(String& name,String& password ,Vector<User>& allPeople);

	bool DoesUserExistsByName(String& name, Vector<User>& allPeople);

	bool DoesBookExist(StringWS& name, Vector<Book>& allBooksFromFile);
};