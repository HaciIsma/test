#pragma once
#include "User.h"

class Administrator:public User
{
public:
	Administrator(){}

	void addQuiz(Container& container);

private:

};