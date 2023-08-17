#pragma once

#include <string>
#include <bcrypt.h>
#include <iostream>
#include "userDatabase.h"
#include "userInput.h"
#include "userInterface.h"

namespace Login
{
	void printLoginScreen();

	bool validatePassword(std::string& password, std::string pass);

	bool login(database& db);
}