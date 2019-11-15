#include "AccountManager.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <string.h>
#include "User.h"

std::string AccountManager::Password()
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

void AccountManager::SignUp()
{
	std::fstream fout("Account.txt", std::ios_base::out);
	if (fout.is_open()) {
		User temp;
		temp.SetInfo();

		std::string username;
		//std::string password;

		std::cout << "Username: ";
		std::getline(std::cin, username);
		temp.setUsername(username);
		fout << username << "\n";


		//std::pair<std::string, std::string>pair(username, password);
		//account.insert(pair);

		if (!account.count(username))
		{
			std::string password = Password();
			temp.setPassword(password);
			account[username] = password;
			fout << password << "\n";
			std::cout << '\n';
		}

		else
		{
			std::cout << "this username is worked" << '\n';
		}
		Users.push_back(temp);
	}
	fout.close();
}

std::size_t AccountManager::find(std::pair<std::string, std::string>pair)
{
	std::size_t len = Users.size();
	for (size_t i = 0; i < len; i++)
	{
		if (Users[i].getUsername() == pair.first)
		{
			return i;
		}
	}
}

void AccountManager::edit()
{
	std::pair<std::string, std::string>pair = SignIn();
	std::size_t index = find(pair);
	int choose = 0;
	std::cout << "Choose:\n1.Name\n2.Surname\n3.Telephone\n4.Username\n5.Password\n";
	std::cin >> choose;
	if (choose == Name)
	{
		std::string name1;
		std::getline(std::cin, name1);
		Users[index].setName(name1);
	}
	else if (choose == Surname)
	{
		std::string surname1;
		std::getline(std::cin, surname1);
		Users[index].setSurname(surname1);
	}
	else if (choose == Telephone)
	{
		std::string tell;
		std::getline(std::cin, tell);
		Users[index].setTelephone(tell);
	}
	else if (choose == Username)
	{
		std::string username1;
		std::getline(std::cin, username1);
		Users[index].setUsername(username1);
		account.clear();
		account[username1] = Users[index].getPassword();

	}
	else if (choose == Password_)
	{
		std::string pass = Password();
		account[Users[index].getUsername()] = pass;
		Users[index].setPassword(pass);
	}
}

std::pair<std::string, std::string> AccountManager::SignIn()
{
	std::string checkUsername;
	std::string checkPassword;
	std::cout << "Username: ";
	std::getline(std::cin, checkUsername);

	if (account.count(checkUsername))
	{
		std::string checkPassword = Password();
		std::cout << '\n';
		if (account[checkUsername] == checkPassword)
		{
			std::cout << "Welcome system" << '\n';
		}
		else
		{
			std::cout << "Password wrong" << '\n';
		}
	}
	else
	{
		std::cout << "Username wrong" << '\n';
	}
	std::pair<std::string, std::string>pair(checkUsername, checkPassword);
	return pair;
}