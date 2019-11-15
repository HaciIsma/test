#pragma once
#include <string>

class Question
{
public:
	std::string getQuestion();
	std::string getVariant(std::size_t index);
	char getCorrectVariant();

	void setQuestion(std::string question);
	void setVariant(std::string variant, std::size_t index);
	void setCorrectVariant(char correctVariant);

private:
	std::string question;
	std::string variant[4];
	char correctVariant;
};
