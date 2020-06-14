#include "DateTime.h"

DateTime::DateTime() { this->day = 0; this->month = 0; this->year = 0; }

DateTime::DateTime(int& day, int& month, int& year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

DateTime::DateTime(const DateTime& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

bool DateTime::operator>(const DateTime& other)
{
	if (this->year < other.year)
		return true;
	if (this->year == other.year && this->month < other.month)
		return true;
	if (this->year == other.year && this->month == other.month &&
		this->day < other.day)
		return true;

	return false;
}

bool DateTime::operator<(const DateTime& other)
{
	if (this->year > other.year)
		return true;
	if (this->year == other.year && this->month > other.month)
		return true;
	if (this->year == other.year && this->month == other.month &&
		this->day > other.day)
		return true;

	return false;
}

std::ostream& operator<<(std::ostream& out, const DateTime& date)
{
	out << date.day << ' ' << date.month << ' ' << date.year;
	return out;
}
