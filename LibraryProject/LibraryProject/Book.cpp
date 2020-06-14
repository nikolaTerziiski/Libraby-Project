#include "Book.h"

Book::Book(){}

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

void Book::PrintBookInformation()
{
	std::cout << "----------------------------" << std::endl;
	std::cout << "Book author: " << this->author << std::endl;
	std::cout << "Book title: " << this->title << std::endl;
	std::cout << "Book description: " << this->description << std::endl;
	std::cout << "Book genre: " << this->genre << std::endl;
	std::cout << "Date published: " << this->year.day << "/" << this->year.month << "/" << this->year.year << std::endl;
	std::cout << "Book key words: " << this->keyWords << std::endl;
	std::cout << "Book rating: " << this->rating << std::endl;
	std::cout << "----------------------------" << std::endl;
}
