#include "Test.h"
#include <string>
#include <iostream>
#include <conio.h>

void Test::addQuestion()
{
	Question temp;
	std::string question;
	char correctVariant;
	std::string variant[4];
	char op;
	do
	{
	std::cout << "Question: ";
		std::getline(std::cin, question);
		for (size_t i = 0; i < 4; i++)
		{
			std::cout << char(i + 65) << ".variant: ";
			std::getline(std::cin, variant[i]);
		}
		std::cout << "Correct Variant: ";
		/*std::cin.getline(correctVariant,1)*/
		std::cin >> correctVariant;
		std::cin.ignore();
		std::string choose;
		std::cout << "Save ? Yes or no(y/n)";
		std::getline(std::cin, choose);
		if (choose == "Y" || choose == "y")
		{
			temp.setQuestion(question);
			temp.setCorrectVariant(correctVariant);
			for (size_t i = 0; i < 4; i++)
			{
				temp.setVariant(variant[i], i);
			}
			quiz.push_back(temp);
		}
		else if (choose == "N" || choose == "n")
		{
		}
		else
		{
			//exception;
		}
		std::cout << "add(+): ";
		std::cin >> op;
		std::cin.ignore();
	} while (op == '+');

}

void Test::setName(std::string name)
{
	this->name = name;
}

void Test::setCategory(std::string category)
{
	this->category = category;
}

std::string Test::getName()
{
	return name;
}

std::string Test::getCategory()
{
	return category;
}

Question& Test::operator[](std::size_t index)
{
	return quiz[index];
}

int Test::getSize()
{
	return quiz.size();
}