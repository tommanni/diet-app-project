#pragma once

#include "userInput.h"
#include "userDatabase.h"
#include "login.h"
#include "userProfile.h"
#include "calorieCalculator.h"

namespace Register
{
	void getUserInfo(User& user);
	void getUserData(database& db, User& user);
	void registration(database& db);
}