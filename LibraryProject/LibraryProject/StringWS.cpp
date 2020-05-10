#include <iostream>
#include <cstring>
#include <fstream>
#include "StringWS.h"

#pragma warning(disable:4996)

StringWS::StringWS() { create(""); }
StringWS::StringWS(const char* input) {
	create(input);
}
StringWS::StringWS(const StringWS& other)
{
	//Ползваме length, защото нямаме strlen за нашия String
	data = new char[other.length() + 1];
	strcpy(data, other.data);
}

StringWS::StringWS(char character) {
	data = new char[2];
	data[0] = character;
	data[1] = '\0';
}

StringWS::~StringWS()
{
	delete[]this->data;
}

void StringWS::print() const {
	std::cout << this->data << std::endl;
}

int StringWS::length() const
{
	return strlen(this->data);
}

StringWS& StringWS::operator=(const StringWS& other)
{
	/*String result;
	result.data = new char[strlen(other.data) + 1];

	strcpy(result.data, other.data);

	return result;*/

	this->data = new char[strlen(other.data) + 1];
	strcpy(this->data, other.data);
	return *this;
}

StringWS StringWS::operator+(StringWS& other)
{
	StringWS finalString;
	finalString.data = new char[strlen(this->data) + strlen(other.data) + 1];
	strcpy(finalString.data, this->data);
	strcpy(finalString.data, this->data);

	return finalString;
}

StringWS StringWS::operator+(char c)
{
	StringWS finalString;
	finalString.data = new char[length() + 1 + 1]; // +1 +1 заради терминиращата 0 и c
	strcpy(finalString.data, data);
	//Добавяме c на последно място където е била терминиращата нула
	finalString.data[this->length()] = c;
	finalString.data[this->length() + 1] = '\0';

	return finalString;
}

char StringWS::operator[](int index)
{
	return this->data[index];
}

bool StringWS::operator==(StringWS& other)
{
	//strcmp връща -1,0 , 1. Ако са равни съответно ще върне 0
	return strcmp(data, other.data) == 0;
}

bool StringWS::operator==(const char* other)
{
	return strcmp(this->data, other) ? false : true;
}

bool StringWS::operator==(const char other)
{
	if (this->length() == 1 && this->data[0] == other)
	{
		return true;
	}
	return false;
}

bool StringWS::operator>(StringWS& other)
{
	if (this->length() > other.length())
	{
		return true;
	}
	else if (this->length() < other.length())
	{
		return false;
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < this->length(); i++)
		{
			if (this->data[i] > other.data[i])
			{
				flag = true;
				return flag;
			}
			else if (this->data[i] < other.data[i])
			{
				return flag;
			}
		}
		return false;
	}
}

bool StringWS::operator<(StringWS& other)
{
	if (this->length() < other.length())
	{
		return true;
	}
	else if (this->length() > other.length())
	{
		return false;
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < this->length(); i++)
		{
			if (this->data[i] < other.data[i])
			{
				flag = true;
				return flag;
			}
			else if (this->data[i] > other.data[i])
			{
				return flag;
			}
		}
		return false;
	}
}

bool StringWS::Contains(StringWS& input)
{
	
	if (!(strstr(this->data, input.data) == NULL))
	{
		return true;
	}
	return false;
}

bool StringWS::CheckIfInt(StringWS& input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int StringWS::MakeItInt()
{
	int counter = 0;
	int number = 0;
	while (this->data[counter] != '\0')
	{
		number = number * 10;
		number = number + data[counter] - '0';
		counter++;
	}
	return number;
}

float StringWS::MakeItDecimal()
{
	int counter = 0;
	float number = 0;
	bool isAfterDecimal = false;;
	int counterForDecimal = 1;
	while (this->data[counter] != '\0')
	{
		if (this->data[counter] == '.')
		{
			isAfterDecimal = true;
			counter++;
			continue;
		}
		if (isAfterDecimal)
		{
			number = number + (data[counter] - '0') / pow(10, counterForDecimal);
			counterForDecimal++;
			counter++;
			continue;
		}
		number = number * 10;
		number = number + data[counter] - '0';
		counter++;
	}
	return number;
}



void StringWS::create(const char* s) {
	//Ползваме strlen, защото я имаме от cstring за char*
	data = new char[strlen(s) + 1];
	strcpy(data, s);
}

std::istream& operator>>(std::istream& in, StringWS& wholeString)
{
	char firstCharacter;
	firstCharacter = in.get();
	while (firstCharacter != '\n' && firstCharacter != 'я')
	{
		wholeString = wholeString + firstCharacter;
		firstCharacter = in.get();
	}

	return in;
}

std::ostream& operator<<(std::ostream& os, const StringWS& str)
{
	for (int i = 0; i < strlen(str.data) - 1; ++i) {
		os << str.data[i];
	}
	os << str.data[strlen(str.data) - 1];
	return os;
}
