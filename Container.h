#pragma once
#include "Test.h"
class Container
{
public:
	Container() = default;

	Test& operator[](std::size_t index);
	void addTest();

	void goToTest(std::size_t index);
	void chooseTest();

private:
	std::vector<Test>Tests;
};
