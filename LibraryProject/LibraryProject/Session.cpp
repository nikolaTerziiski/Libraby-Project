#include <fstream>
#include "Session.h"
#include "Book.h"
#include "TextData.h"


Session::Session() {
	this->allUsers = data::allUsersFromData(this->allUsers);
	this->isUserLoggedIn = false;
};

void Session::LogoutUser()
{
	if (this->isUserLoggedIn == false)
	{
		std::cout << "You are not logged in to logout."<< std::endl;
		return;
	}
	this->user = User();
	this->isUserLoggedIn = false;
	std::cout << "Succesfully logout :)" << std::endl;
}
void Session::LogInUser()
{
	if (this->isUserLoggedIn)
	{
		std::cout << "You are already logged in." << std::endl;
		return;
	}
	String name, password;
	name = data::insertUsername(name);
	password = data::insertPassword(password);

	if (this->validator.DoesUserExistsLogIn(name,password,this->allUsers))
	{
		this->user = User(name, password);
		std::cout << "User {" << this->user.getName() << "} succesfully logged in!" << std::endl;
		this->isUserLoggedIn = true;
		return;
	}
	std::cout << "Invalid username or password!" << std::endl;
}

void Session::AdminUsersControl()
{
	String command;
	std::cin >> command;
	if (this->isUserLoggedIn == false)
	{
		std::cout << "You are not logged in to make these actions!" << std::endl;
		return;
	}
	if (!this->user.isAdministrator())
	{
		std::cout << "You dont have permission to make these actions!"<<std::endl;
		return;
	}
	if (command == "add")
	{
		this->AdminAddUser();
	}
	else if (command == "remove")
	{
		this->AdminRemoveUser();
	}
	else
	{
		std::cout << "The action you are trying to make does't exists :)" << std::endl;
	}
}
void Session::AdminAddUser()
{
	String username, password;
	username = data::insertUsername(username);
	password = data::insertPassword(password);

	std::ofstream outfile;
	this->allUsers.push_back(User(username, password));

	outfile.open("newUsers.txt", std::ios_base::app); // append instead of overwrite
	outfile << username << " " << password << "\n";
	outfile.close();

	std::cout << username << " successfully registered." << std::endl;
}

void Session::AdminRemoveUser()
{
	String usernameToRemove;
	Vector<User> result;

	std::cout << "Enter username to remove: ";
	std::cin >> usernameToRemove;
	if (!this->validator.DoesUserExistsByName(usernameToRemove, this->allUsers))
	{
		std::cout << "The user you are trying to remove does not exists!" << std::endl;
		return;
	}
	if (usernameToRemove == "admin")
	{
		std::cout << "You can't remove yourself!" << std::endl;
		return;
	}

	std::ofstream out;
	out.open("newUsers.txt", std::ios::out);

	
	for (int i = 0; i < this->allUsers.length(); i++)
	{
		if (!(this->allUsers[i].getName() == usernameToRemove))
		{
			result.push_back(this->allUsers[i]);
		}
	}
	
	this->allUsers = result;

	for (int i = 0; i < this->allUsers.length(); i++)
	{
		out << this->allUsers[i].getName() << " " << this->allUsers[i].getPassword() << '\n';
	}
	out.close();
	std::cout << usernameToRemove << " succesfully removed." << std::endl;
}

void Session::BookSplit()
{
	String command;
	std::cin >> command;
	if (this->isUserLoggedIn == false)
	{
		std::cout << "You have to be logged in to make operations with the books." << std::endl;
		return;
	}
	if (!this->user.isAdministrator() && (command =="add" || command =="remove"))
	{
		std::cout << "You don't permission to add or remove books!" << std::endl;
		return;
	}
	
	if (command == "add")
	{
		StringWS author, title, description, keyWords;
		//Ako iskame nqkolko genre moje i StringWS, no go napravih samo s 1
		String date, genre;
		float rating = 0.0;

		Book bookToAdd;

		bookToAdd.id = data::generateBookId(bookToAdd.id);
		std::cout << "Enter author name: ";
		std::cin >> author;
		while (author == "")
		{
			std::cout << "Author name must be atleast 1 character long!" << std::endl;
			std::cout << "Enter author name: ";
			std::cin >> author;
		}
		bookToAdd.author = author;
		std::cout << "Enter the Title of the movie: ";
		std::cin >> title;
		while (title == "")
		{
			std::cout << "Title of the movie must be atleast 1 character long!" << std::endl;
			std::cout << "Enter author name: ";
			std::cin >> title;
		}

		//Proverqvame dali ima takuv film s ime Title i avtor Author
		//TO DO

		bookToAdd.title = title;
		std::cout << "Enter genre: ";
		std::cin >> genre;
		while (genre == "")
		{
			std::cout << "Genre must be atleast 1 character long!" << std::endl;
			std::cout << "Enter genre: ";
			std::cin >> genre;
		}
		bookToAdd.genre = genre;
		std::cout << "Enter some description for the movie: ";
		std::cin >> description;
		while (description == "" || description.length() > 300)
		{
			std::cout << "Description must be in range [1-300] characters long!" << std::endl;
			std::cout << "Enter some description for the movie: ";
			std::cin >> description;
		}
		bookToAdd.description = description;
		std::cout << "Enter when the movie came out (in format DD/MM/YYYY): ";
		std::cin >> date;
		while (date == "")
		{
			std::cout << "You must input date!" << std::endl;
			std::cout << "Enter when the movie came out (in format DD/MM/YYYY): ";
			std::cin >> date;
		}
		bookToAdd.year = date;
		std::cout << "Write some key words for the movie(Example: great actors, nice animations): ";
		std::cin >> keyWords;
		while (keyWords == "")
		{
			std::cout << "You must input at least one key word for the movie!!" << std::endl;
			std::cout << "Write some key words for the movie(Example: great actors, nice animations): ";
			std::cin >> keyWords;
		}
		bookToAdd.keyWords = keyWords;
		std::cout << "Give some rating for the movie in range [1.0 - 10.0]: ";
		std::cin >> rating;
		while (rating < 1.0 || rating > 10.0)
		{
			rating = 0.0;
			std::cout << "Rating must be in range [1.0 - 10.0]!" << std::endl;
			std::cout << "Give some rating for the movie in range [1.0 - 10.0]: ";
			std::cin >> rating;
		}
		bookToAdd.rating = rating;

		std::ofstream out;
		out.open("books.txt", std::ios::app);

		out << bookToAdd.id << '\n' << bookToAdd.title << '\n' << bookToAdd.author << '\n' << bookToAdd.description << '\n' << bookToAdd.genre << '\n' << bookToAdd.year <<
			'\n' << bookToAdd.keyWords << '\n' << bookToAdd.rating << '\n';
		this->books.push_back(bookToAdd);
		out.close();

		std::cout << "Book: " << bookToAdd.title << " succesfully added!" << std::endl;

		//Poradi nqkakva prichina mi dava prazen red na sledvashtiq input v main-a i zatova pravq tuk edin String, koito poema tozi input i ne se zabelqzva
		String spaceProblem; std::cin >> spaceProblem;
		return;
	}
	else if (command == "info")
	{
		int id;
		std::cin >> id;
		Book bookToFind;
		for (int i = 0; i < this->books.length(); i++)
		{
			if (this->books[i].id == id)
			{
				bookToFind = this->books[i];
			}
		}
		bookToFind.PrintBook();
		String spaceProblem; std::cin >> spaceProblem;
		return;
	}
	else if (command == "find")
	{
		String criteria;
		std::cin >> criteria;

		if (!(criteria == "author" || criteria == "title" || criteria == "tag"))
		{
			std::cout << "Invalid criteria, please try again." << std::endl;
			return;
		}
		if (this->books.length() == 0)
		{
			std::cout << "There are no books to search for." << std::endl;
			return;	
		}

		Vector<Book> booksToPrint;
		StringWS toSearch;
		std::cin >> toSearch;
		if (toSearch == "")
		{
			std::cout << "You havent entered any information ot search for. Try again." << std::endl;
			return;
		}
		if (criteria == "author")
		{
			for (int i = 0; i < this->books.length(); i++)
			{
				if (this->books[i].author == toSearch)
				{
					booksToPrint.push_back(this->books[i]);
				}
			}
		}
		else if (criteria == "title")
		{
			for (int i = 0; i < this->books.length(); i++)
			{
				if (this->books[i].title == toSearch)
				{
					booksToPrint.push_back(this->books[i]);
				}
			}
		}
		else
		{
			for (int i = 0; i < this->books.length(); i++)
			{
				if (this->books[i].keyWords.Contains(toSearch))
				{
					booksToPrint.push_back(this->books[i]);
				}
			}
		}

		data::PrintBooks(booksToPrint);

	}
	else if (command == "all")
	{
		data::PrintBooks(this->books);
	}
	else if(command == "remove")
	{
		StringWS titleToRemove;
		std::cin >> titleToRemove;
		if (!this->validator.DoesBookExist(titleToRemove, this->books))
		{
			std::cout << "There is no book with this title" << std::endl;
			return;
		}
		Vector<Book> result;
		for (int i = 0; i < this->books.length(); i++)
		{
			if (this->books[i].title == titleToRemove)
			{
				continue;
			}
			result[i] = this->books[i];
		}
		this->books = result;
		std::ofstream out;
		out.open("books.txt", std::ios::out | std::ios::trunc);
		for (int i = 0; i < this->books.length(); i++)
		{
			out << books[i].id << '\n' << books[i].title << '\n' << books[i].author << '\n' << books[i].description << '\n' << books[i].genre << '\n' << books[i].year <<
				'\n' << books[i].keyWords << '\n' << books[i].rating << '\n';
		}
		out.close();
	}
	else if (command == "sort")
	{

	}
}

void Session::RestartProgramFiles(String& path)
{
	data::RestartProgramFiles(path);
}
