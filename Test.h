#pragma once
#include <string>
#include <vector>
#include "question.h"
#include <unordered_map>
class Test
{
public:
	void setName(std::string name);
	void setCategory(std::string category);

	std::string getName();
	std::string getCategory();

	//
	int getSize();

	void addQuestion();

	Question& operator[](std::size_t index);

	//std::unordered_multimap<std::string, std::string>categoryAndName;
private:
	std::string name;
	std::string category;
	std::vector<Question>quiz;
};
