#pragma once

#include <iostream>
#include <string>
//#include <windows.h>
#include "userProfile.h"

void ignoreInput();

void getUsername(std::string& username);

void getPassword(std::string& password);

char getCommand();

int getCalorieGoal();

int getMealsPerDay();

int getCmd();

int getCarbPercentage();

int getProteinPercentage();

void setCustomMacronutrientGoals(User& user);

void getUserGoals(User& user);