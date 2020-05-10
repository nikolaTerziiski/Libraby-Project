#pragma once
#include <iostream>
#include "String.h"
class DateTime {
public:
	int day, month, year;
	DateTime();

	DateTime(int& day, int& month, int& year);

	DateTime(const DateTime& other);

	friend std::ostream& operator<<(std::ostream&, const DateTime&);

	bool operator> (const DateTime& other);
	bool operator< (const DateTime& other);

};

