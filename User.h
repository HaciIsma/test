#pragma once
#include "Container.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <unordered_map>
#include <vector>

class User
{
public:
	User() = default;



	void setUsername(std::string username);
	void setPassword(std::string password);

	std::string getUsername();
	std::string getPassword();

	void setName(std::string name);
	void setSurname(std::string surname);
	void setTelephone(std::string telephone);

	std::string getName();
	std::string getSurname();
	std::string getTelephone();

	void SetInfo();
private:
	std::unordered_map<std::string, std::string>account;

	std::string name;
	std::string surname;
	std::string telephone;
	std::string username;
	std::string password;

	std::string Password();
	//////////////////////////////
};
