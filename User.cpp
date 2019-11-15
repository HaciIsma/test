#include "User.h"

void User::setUsername(std::string username)
{
	this->username = username;
}
void User::setPassword(std::string password)
{
	this->password = password;
}

std::string User::getUsername()
{
	return username;
}
std::string User::getPassword()
{
	return password;
}

void User::setName(std::string name)
{
	this->name = name;
}
void User::setSurname(std::string surname)
{
	this->surname = surname;
}
void User::setTelephone(std::string telephone)
{
	this->telephone = telephone;
}

std::string User::getName()
{
	return name;
}
std::string User::getSurname()
{
	return surname;
}
std::string User::getTelephone()
{
	return telephone;
}

void User::SetInfo()
{
	std::cout << "Name: ";
	std::getline(std::cin, name);
	std::cout << "Surname: ";
	std::getline(std::cin, surname);
	std::cout << "Telephone: ";
	std::getline(std::cin, telephone);
}

std::string User::Password()
{
	int ch;
	std::string pass = "";
	std::cout << "Password: ";
	while (ch = _getch())
	{
		if (ch == 13)
		{
			return pass;
			break;
		}
		else if (ch == 8)
		{
			if (pass.length() > 0)
			{
				std::cout << "\b \b";
				pass.erase(pass.length() - 1);
			}
		}
		else
		{
			std::cout << "*";
			pass += ch;
		}
	}
	return pass;
}