#pragma once
#include "User.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

enum { Name, Surname, Telephone, Username, Password_ };

class AccountManager
{
public:
	AccountManager() = default;
	/*~AccountManager()
	{
	}*/
	std::string Password();
	std::size_t find(std::pair<std::string, std::string>pair);
	void SignUp();
	std::pair<std::string, std::string> SignIn();
	void edit();
private:
	std::vector<User>Users;
	std::unordered_map<std::string, std::string>account;
};
