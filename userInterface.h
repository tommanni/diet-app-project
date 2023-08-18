#pragma once

#include <sqlite_modern_cpp.h>
#include "initDatabase.h"
#include "login.h"
#include "register.h"

namespace UserInterface
{
	void printAuthScreen();

	void printAuthOptions();

	void printMenuOptions();

	int getAuthCommand();

	void loginScreenChoice();
}
