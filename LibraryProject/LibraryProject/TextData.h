//#include "User.h"
#pragma once
#include <fstream>
#include <iostream>
//#include "Vector.h"

namespace data {
	Vector<User>& allUsersFromData(Vector<User>& vector) {
		Vector<User> result;
		std::ifstream in;
		Vector<User> allUsers;
		in.open("newUsers.txt", std::ios::in);
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
		vector = result;
		return vector;
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
			std::cin >> password;
			if (password.length() == 0)
			{
				std::cout << "Invalid password! Password must be atleast 1 character!"<<std::endl;
				continue;
			}
		}
		return password;
	}
	void RestartProgramFiles(String& path)
	{
		std::ofstream out;
		out.open(path.data, std::ios::out | std::ios::trunc);
		out << "admin" << " " << "i<3c++\n";
		out.close();

		out.open("id.txt", std::ios::out);
		out << 1 << '\n';
		out.close();

		out.open("books.txt", std::ios::out | std::ios::trunc);
		out.close();
	}
	/*Book addBook() {

	}*/
	void PrintBooks(Vector<Book>& books) {
		std::cout << "-----" << std::endl;
		if (true)
		{
			if (books.length() == 0)
			{
				std::cout << "There are no books registered." << std::endl;
				return;
			}
		}
		int counter = 1;
		for (int i = 0; i < books.length(); i++)
		{
			std::cout << counter << ". " <<books[i].title << ", " << books[i].author << ", " << books[i].genre << ", personal number: " << books[i].id << std::endl;
			counter++;
			return;
		}
	}
}