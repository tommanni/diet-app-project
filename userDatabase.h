#pragma once

#include <iostream>
#include <sqlite_modern_cpp.h>
#include "userProfile.h"

using namespace sqlite;

void addUser(database& db, const User& user);

void addUserInfo(database& db, User& user);

void addUserGoals(database& db, User& user);

void findUser(database& db, const std::string& username, std::string& pass);

bool findUsername(database& db, const std::string& username);