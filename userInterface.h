#pragma once

#include <sqlite_modern_cpp.h>
#include "initDatabase.h"
#include "login.h"
#include "register.h"

namespace UserInterface
{
	void printAuthScreen();

	int getLoginCommand();

	void loginScreenChoice();
}
