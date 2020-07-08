//#include "User.h"
#pragma once
#include <fstream>
#include <iostream>
#include <conio.h>
//#include "Vector.h"

namespace data {
	Vector<User>& allUsersFromData(Vector<User>& allUsers) {
		Vector<User> result;
		std::ifstream in;
		in.open("users.txt", std::ios::in);
		if (!in)
		{
			std::cout << "There are no users in the file" << std::endl;
			return result;
		}
		User temp;
		in >> temp;
		while (!(temp.getName() == "" && temp.getPassword() == ""))
		{
			result.push_back(temp);
			temp = User();
			in >> temp;
		}
		in.close();
		allUsers = result;
		return allUsers;
	};
	Vector<Book>& allBooksFromData(Vector<Book>& allBooksFromFile, String& path) {
		std::ifstream in;
		in.open(path.data, std::ios::in);
		Vector<Book> result;
		
		in.ignore();
		while (!in.eof() || in.get() != -1)
		{
			Book book;
			in >> book.id;
			in.ignore();
			in >> book.title;
			in >> book.author;
			in >> book.description;
			in >> book.genre;
			in >> book.year.day; in >> book.year.month, in >> book.year.year;
			in.ignore();
			in >> book.keyWords;
			in >> book.rating;
			result.push_back(book);
		}
		in.close();
		allBooksFromFile = result;
		return allBooksFromFile;
	};
	int generateBookId(int& id) {
		std::ifstream in;
		in.open("id.txt", std::ios::in);

		//Generating id
		String temp;
		in >> temp;
		id = temp.MakeItInt();
		in.close();

		//Writing the id 
		std::ofstream out;
		out.open("id.txt", std::ios::out);
		out << 1 + id << '\n';
		out.close();
		return id;
	};

	String insertUsername(String& username) {
		while (username.length() == 0)
		{
			username = "";
			std::cout << "Enter username: ";
			std::cin >> username;
			if (username.length() == 0)
			{
				std::cout << "Invalid username! Username must be atleast 1 character!" << std::endl;
				continue;
			}
		}
		return username;
	}
	String insertPassword(String& password) {
		while (password.length() == 0)
		{
			password = "";
			std::cout << "Enter password: ";
			/*char s = 'a';
			while (true)
			{
				s = _getch(); _putch('*');
				if (s == 13)
				{
					break;
				}
				password = password + s;
			}*/
			std::cin >> password;
			if (password.length() == 0)
			{
				std::cout << "Invalid password! Password must be atleast 1 character!"<<std::endl;
				continue;
			}
		}
		return password;
	}
	void PrintBooks(Vector<Book>& allBooksFromFile) {
		std::cout << "-----" << std::endl;
		if (true)
		{
			if (allBooksFromFile.length() == 0)
			{
				std::cout << "There are no books registered." << std::endl;
				return;
			}
		}
		int counter = 1;
		for (int i = 0; i < allBooksFromFile.length(); i++)
		{
			std::cout << counter << ". " <<allBooksFromFile[i].title << ", " << allBooksFromFile[i].author << ", " << allBooksFromFile[i].genre << ", personal number: " << allBooksFromFile[i].id << std::endl;
			counter++;
		}
	}
	void AddUserToFile(String& username, String& password) {
		std::ofstream outfile;

		outfile.open("users.txt", std::ios_base::app); // append instead of overwrite
		outfile << username << " " << password << "\n";
		outfile.close();
		std::cout << username << " successfully registered." << std::endl;
	}
	void RemoveUserFromFile(String& usernameToRemove, Vector<User>& allUsers) {

		std::ofstream out;
		out.open("users.txt", std::ios::out);
		Vector<User> result;

		for (int i = 0; i < allUsers.length(); i++)
		{
			if (!(allUsers[i].getName() == usernameToRemove))
			{
				result.push_back(allUsers[i]);
			}
		}
		allUsers = result;

		for (int i = 0; i < allUsers.length(); i++)
		{
			out << allUsers[i].getName() << " " << allUsers[i].getPassword() << '\n';
		}
		out.close();
		std::cout << usernameToRemove << " succesfully removed." << std::endl;
	}
	bool isLeap(int year)
	{
		return (((year % 4 == 0) &&
			(year % 100 != 0)) ||
			(year % 400 == 0));
	}
	DateTime inputYear(DateTime& date) {
		int day, month, year;
		std::cout << '\n';
		std::cout << "-- Enter day: ";
		std::cin >> day;
		std::cout << "-- Enter month: ";
		std::cin >> month;
		std::cout << "-- Enter year: ";
		std::cin >> year;

		bool isValidDate = false;
		while (!isValidDate)
		{
			if (month < 1 || month > 12 || day < 1 || day > 31 || (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) || (!isLeap(year) && day == 29 && month == 2))
			{
				std::cout << "Invalid date!";
				std::cout << "-- Enter day: ";
				std::cin >> day;
				std::cout << "-- Enter month: ";
				std::cin >> month;
				std::cout << "-- Enter year: ";
				std::cin >> year;
			}
			else
			{
				isValidDate = true;
			}
		}
		date.day = day;
		date.month = month;
		date.year = year;

		return date;
	}
}