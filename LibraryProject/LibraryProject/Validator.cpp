#include "Validator.h"

Validator::Validator(){}

bool Validator::DoesUserExists(String& name, String& password, Vector<User>& allUsers)
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
