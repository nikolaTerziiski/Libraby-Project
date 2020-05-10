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

void Book::PrintBook()
{
	std::cout << "Book author: " << this->author << std::endl;
	std::cout << "Book title: " << this->title << std::endl;
	std::cout << "Book description: " << this->description << std::endl;
	std::cout << "Book genre: " << this->genre << std::endl;
	std::cout << "Book key words: " << this->keyWords << std::endl;
	std::cout << "Book rating: " << this->rating << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << "Book author: " << book.author << std::endl;
	os << "Book title: " << book.title << std::endl;
	os << "Book description: " << book.description << std::endl;
	os << "Book genre: " << book.genre << std::endl;
	os << "Book key words: " << book.keyWords << std::endl;
	os << "Book rating: " << book.rating << std::endl;

	return os;
}

