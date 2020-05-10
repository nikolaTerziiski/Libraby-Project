#pragma once
#include <iostream>
#include "String.h"
#include "StringWS.h"

class Book {
public:

	Book();
	Book(const Book& other);

	int id;
	StringWS author;
	StringWS title;
	String genre;
	StringWS description;
	String year;
	StringWS keyWords;
	float rating;
	
	void PrintBook();

	friend std::ostream& operator<<(std::ostream&, const String&);
private:
};