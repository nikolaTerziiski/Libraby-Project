#include "Validator.h"

Validator::Validator(){}

bool Validator::DoesUserExistsLogIn(String& name,String& password,Vector<User>& allUsers)
{
	for (int i = 0; i < allUsers.length(); i++)
	{
		if (allUsers[i].getName() == name && allUsers[i].getPassword() == password)
		{
			return true;
		}
	}
	return false;
}

bool Validator::DoesUserExistsByName(String& name, Vector<User>& allUsers)
{
	for (int i = 0; i < allUsers.length(); i++)
	{
		if (allUsers[i].getName() == name)
		{
			return true;
		}
	}
	return false;
}

bool Validator::DoesBookExist(StringWS& name, Vector<Book>& allBooksFromFile)
{
	for (int i = 0; i < allBooksFromFile.length(); i++)
	{
		if (allBooksFromFile[i].title == name)
		{
			return true;
			
		}
	}
	return false;
}
