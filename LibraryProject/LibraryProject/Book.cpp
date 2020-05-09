#include "Book.h"


Book::Book()
{
	std::ifstream in;
	in.open("id.txt", std::ios::in);

	//Generating id
	String temp;
	in >> temp;
	this->id = temp.MakeItInt();
	in.close();

	//Writing the id 
	std::ofstream out;
	out.open("id.txt", std::ios::out);
	out << 1 + this->id << '\n';
	out.close();
}

Book::Book(const Book& other)
{
	this->id = other.id;
	this->author = other.author;
	this->description = other.description;
	this->genre = other.genre;
	this->keyWords = other.keyWords;
	this->rating = other.rating;
	this->title = other.title;
	this->year = other.year;
}
