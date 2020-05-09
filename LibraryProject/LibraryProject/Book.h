#include <iostream>
#include "String.h"
#include "StringWS.h"

#pragma once
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
};