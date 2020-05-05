#include <iostream>
#include <cstring>
#include <fstream>

#pragma once
class String {
public:
	char *data;
	String();
	String(const char* character);
	String(const String &other);
	String(char character);
	~String();


	void create(const char *s);
	void print() const;
	int length() const;

	String& operator= (const String &other);
	String operator+ (String &other);
	String operator+ (char c);
	char operator[] (int index);
	bool operator== (String &other);
	bool operator== (const char* other);
	bool operator== (const char other);

	bool CheckIfInt(String &input);
	int MakeItInt();
	float MakeItDecimal();

	friend std::istream& operator>>(std::istream&, String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
};