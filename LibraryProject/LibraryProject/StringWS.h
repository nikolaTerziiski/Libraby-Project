#include <iostream>
#include <cstring>
#include <fstream>

#pragma once
class StringWS {
public:
	char* data;
	StringWS();
	StringWS(const char* character);
	StringWS(const StringWS& other);
	StringWS(char character);
	~StringWS();


	void create(const char* s);
	void print() const;
	int length() const;

	StringWS& operator= (const StringWS& other);
	StringWS operator+ (StringWS& other);
	StringWS operator+ (char c);
	char operator[] (int index);
	bool operator== (StringWS& other);
	bool operator== (const char* other);
	bool operator== (const char other);
	bool operator> (StringWS& other);
	bool operator< (StringWS& other);


	bool Contains(StringWS& input);
	bool CheckIfInt(StringWS& input);
	int MakeItInt();
	float MakeItDecimal();

	friend std::istream& operator>>(std::istream&, StringWS&);
	friend std::ostream& operator<<(std::ostream&, const StringWS&);
};