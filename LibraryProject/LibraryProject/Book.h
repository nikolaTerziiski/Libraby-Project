#pragma once
#include <iostream>
#include "String.h"
#include "StringWS.h"
#include "DateTime.h"
class Book {
public:

	Book();
	Book(const Book& other);

	int id;
	StringWS author;
	StringWS title;
	String genre;
	StringWS description;
	DateTime year;
	StringWS keyWords;
	float rating;
	
	void PrintBookInformation();
private:
};