#include "Container.h"
#include <string>
#include <iostream>
#include <io.h>
#include <sstream>
#include <fstream>
#include <conio.h>
Test& Container::operator[](std::size_t index)
{
	return Tests[index];
}

void Container::addTest()
{
	std::ofstream fout("TestList.txt", std::ios_base::out);
	if (fout.is_open()) {
		Test temp;
		std::string category;
		std::cout << "Test category: ";
		std::getline(std::cin, category);
		std::string name;
		std::cout << "Test name: ";
		std::getline(std::cin, name);


		std::string choose;
		std::cout << "Save ? Yes or no(y/n)";
		std::getline(std::cin, choose);
		if (choose == "Y" || choose == "y")
		{
			//std::pair<std::string, std::string>pair(category, name);
			//temp.categoryAndName.insert(pair);
			temp.setName(name);
			temp.setCategory(category);
			temp.addQuestion();
			Tests.push_back(temp);
			fout << /*"Test Choose: " <<*/ choose << "/n";
			fout << /*"Test Name: " << */ name << "/n";
			fout << /*"Test Category: " <<*/ category << "/n";
		}
		else if (choose == "N" || choose == "n")
		{
			std::cout << "Okay" << '/n';
		}
		else
		{
			//exception;
		}
	}
	else {
		// throw FileNotOpenException();
	}
	fout.close();

}

void Container::goToTest(std::size_t index)
{
	char ch;
	int len = Tests[index].getSize();
	for (size_t i = 0; i < len; i++)
	{
		std::cout << Tests[index][i].getQuestion() << '\n';
		for (size_t k = 0; k < 4; k++)
		{
			std::cout << Tests[index][i].getVariant(k) << '\n';
		}
		ch = _getch();
		//ne qeder duzdu?
		char a = Tests[index][i].getCorrectVariant();
		if (ch == a)
		{
			std::cout << "Correct" << '\n';
		}
		else
		{
			std::cout << "Incorrect" << '\n';
		}
	}
}

void Container::chooseTest()
{
	//exception
	std::size_t num;
	std::string category;
	std::size_t len = Tests.size();
	std::cout << "Choose: ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << i + 1 << '\n';
		std::cout << "Category: " << "." << Tests[i].getCategory() << '\n';
		std::cout << "Name: " << Tests[i].getName() << '\n';
	}
	std::cin >> num;
	goToTest(--num);
}

















//void Container::goToTest()
//{
//	std::string name;
//	std::string category;
//
//	std::cout << "Category: ";
//	std::getline(std::cin, category);
//	std::cout << "Name: ";
//	std::getline(std::cin, name);
//
//}