#include <fstream>
#include "Session.h"
#include "Book.h"
#include "TextData.h"


Session::Session(String& path) {
	this->allUsers = data::allUsersFromData(this->allUsers);
	this->allBooksFromFile = data::allBooksFromData(this->allBooksFromFile, path);
	this->isUserLoggedIn = false;
	this->filePath = path;
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
		std::cout << "Welcome, " << this->user.getName() << '!' << std::endl;
		this->isUserLoggedIn = true;
		return;
	}
	std::cout << "Invalid username or password!" << std::endl;
}

void Session::AdminUsersControl(String& path)
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

	outfile.open("users.txt", std::ios_base::app); // append instead of overwrite
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
	out.open("users.txt", std::ios::out);

	
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
		String genre;
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

		//Adding genre
		std::cout << "Enter genre: ";
		std::cin >> genre;
		while (genre == "")
		{
			std::cout << "Genre must be atleast 1 character long!" << std::endl;
			std::cout << "Enter genre: ";
			std::cin >> genre;
		}
		bookToAdd.genre = genre;

		//Adding description
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
		
		//Adding date
		DateTime date;
		bookToAdd.year = data::inputYear(date);
		std::cin.ignore();
		//Adding some key words
		std::cout << "Write some key words for the movie(Example: great actors, nice animations): ";
		std::cin >> keyWords;
		while (keyWords == "")
		{
			std::cout << "You must input at least one key word for the movie!!" << std::endl;
			std::cout << "Write some key words for the movie(Example: great actors, nice animations): ";
			std::cin >> keyWords;
		}
		bookToAdd.keyWords = keyWords;

		//Adding rating
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

		this->booksWaitingToSave.push_back(bookToAdd);
		std::cout << "Book \"" << bookToAdd.title << "\" succesfully added to the waiting list. If you want to keep it, you have to save it" << std::endl;

		std::cin.ignore();
		return;
	}
	else if (command == "info")
	{
		int id;
		std::cin >> id;
		Book bookToFind;
		for (int i = 0; i < this->allBooksFromFile.length(); i++)
		{
			if (this->allBooksFromFile[i].id == id)
			{
				bookToFind = this->allBooksFromFile[i];
			}
		}
		if (bookToFind.id == 0)
		{
			std::cout << "The book with this Id does not exist" << std::endl;
			std::cin.ignore();
			return;
		}
		bookToFind.PrintBookInformation();
		std::cin.ignore();
		return;
	}
	else if (command == "find")
	{
		String criteria;
		std::cin >> criteria;
		StringWS toSearch;
		std::cin >> toSearch;

		if (!(criteria == "author" || criteria == "title" || criteria == "tag"))
		{
			std::cout << "Invalid criteria, please try again." << std::endl;
			return;
		}
		if (this->allBooksFromFile.length() == 0)
		{
			std::cout << "There are no books to search for." << std::endl;
			return;	
		}

		Vector<Book> booksToPrint;
		if (toSearch == "")
		{
			std::cout << "You havent entered any information ot search for. Try again." << std::endl;
			return;
		}
		if (criteria == "author")
		{
			for (int i = 0; i < this->allBooksFromFile.length(); i++)
			{
				if (this->allBooksFromFile[i].author == toSearch)
				{
					booksToPrint.push_back(this->allBooksFromFile[i]);
				}
			}
		}
		else if (criteria == "title")
		{
			for (int i = 0; i < this->allBooksFromFile.length(); i++)
			{
				if (this->allBooksFromFile[i].title == toSearch)
				{
					booksToPrint.push_back(this->allBooksFromFile[i]);
				}
			}
		}
		else
		{
			for (int i = 0; i < this->allBooksFromFile.length(); i++)
			{
				if (this->allBooksFromFile[i].keyWords.Contains(toSearch))
				{
					booksToPrint.push_back(this->allBooksFromFile[i]);
				}
			}
		}

		data::PrintBooks(booksToPrint);

	}
	else if (command == "all")
	{
		data::PrintBooks(this->allBooksFromFile);
	}
	else if(command == "remove")
	{
		StringWS titleToRemove;
		std::cin >> titleToRemove;
		if (!this->validator.DoesBookExist(titleToRemove, this->allBooksFromFile))
		{
			std::cout << "There is no book with this title" << std::endl;
			return;
		}
		Vector<Book> result;
		for (int i = 0; i < this->allBooksFromFile.length(); i++)
		{
			if (this->allBooksFromFile[i].title == titleToRemove)
			{
				continue;
			}
			result.push_back(this->allBooksFromFile[i]);
		}
		this->allBooksFromFile = result;
		std::cout << "Successfully removed the book! If you want to delete it from file save the file." << std::endl;
	}
	else if (command == "sort")
	{
		
		String option, way;
		std::cin >> option;
		std::cout << "Type the way you want to sort the books - ascending or descending: ";
		std::cin >> way;
		if (this->allBooksFromFile.length() == 0)
		{
			std::cout << "There are no books to sort" << std::endl;
			return;
		}
		if (!(option == "title" || option ==  "author" || option == "year" || option == "rating"))
		{
			std::cout << "Invalid way to sort! Try again" << std::endl;
			return;
		}
		//asc
		if (way == "ascending")
		{
			if (option == "title")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].title > this->allBooksFromFile[j + 1].title) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
			else if (option == "author")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].author > this->allBooksFromFile[j + 1].author) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
			else if (option == "rating")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].rating > this->allBooksFromFile[j + 1].rating) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
			else if (option == "year")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].year > this->allBooksFromFile[j + 1].year) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
		}
		//desc
		else if(way == "descending")
		{
			if (option == "title")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].title < this->allBooksFromFile[j + 1].title) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
			else if (option == "author")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].author < this->allBooksFromFile[j + 1].author) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
			else if (option == "rating")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].rating < this->allBooksFromFile[j + 1].rating) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
			else if (option == "year")
			{
				for (int i = 0; i < this->allBooksFromFile.length() - 1; i++)
				{
					// Last i elements are already in place  
					for (int j = 0; j < this->allBooksFromFile.length() - i - 1; j++)
						if (this->allBooksFromFile[j].year < this->allBooksFromFile[j + 1].year) {
							Book temp = this->allBooksFromFile[j];
							this->allBooksFromFile[j] = this->allBooksFromFile[j + 1];
							this->allBooksFromFile[j + 1] = temp;
						}
				}
			}
		}
		else
		{
			std::cout << "Invalid way of ordering. Please try again!" << std::endl;
			return;
		}
		data::PrintBooks(this->allBooksFromFile);
	}
	else
	{
		std::cout << "Invalid command for books!" << std::endl;
		return;
	}
}

void Session::SaveBooks(String &path)
{
	std::ofstream out;
	out.open(path.data, std::ios::in | std::ios::trunc);
	if (!out.is_open())
	{
		std::cout << "Invalid path to save. Please enter correct path" << std::endl;
		return;
	}
	for (int i = 0; i < this->booksWaitingToSave.length(); i++)
	{
		this->allBooksFromFile.push_back(this->booksWaitingToSave[i]);
	}
	this->booksWaitingToSave = Vector<Book>();
	if (this->allBooksFromFile.length() == 0)
	{
		out.close();

	}
	else {
		out << '\n';
		for (int i = 0; i < this->allBooksFromFile.length(); i++)
		{
			if (this->allBooksFromFile.length() - 1 == i)
			{
				out << this->allBooksFromFile[i].id << '\n' << this->allBooksFromFile[i].title << '\n' << this->allBooksFromFile[i].author << '\n' << this->allBooksFromFile[i].description << '\n' << this->allBooksFromFile[i].genre << '\n' << this->allBooksFromFile[i].year <<
					'\n' << this->allBooksFromFile[i].keyWords << '\n' << this->allBooksFromFile[i].rating;

			}
			else
			{
				out << this->allBooksFromFile[i].id << '\n' << this->allBooksFromFile[i].title << '\n' << this->allBooksFromFile[i].author << '\n' << this->allBooksFromFile[i].description << '\n' << this->allBooksFromFile[i].genre << '\n' << this->allBooksFromFile[i].year <<
					'\n' << this->allBooksFromFile[i].keyWords << '\n' << this->allBooksFromFile[i].rating << '\n';
			}
		}
		out.close();
	}
	std::cout << "Unsaved books successfully saved" << std::endl;
}
