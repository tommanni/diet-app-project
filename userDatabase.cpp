#include "userDatabase.h"
#include "userProfile.h"

void addUser(database& db, const User& user)
{
	try
	{
		db <<
			"INSERT INTO"
			"	user (username, password)"
			"VALUES"
			"	(? , ?);"
			<< user.getUsername()
			<< user.getPassword();
	}
	catch (std::exception& ex)
	{
		std::cerr << "Adding user failed:" << ex.what() << '\n';
	}
}

void addUserInfo(database& db, User& user)
{
	try {
		int id{};

		UserInfo& userInfo{ user.getUserInfo() };

		std::cout << userInfo;

		db << "SELECT id FROM user WHERE username = ?;" << user.getUsername() >> id;

		db <<
			"INSERT INTO"
			"  userInfo (userId, age, height, weight, activityLevel, gender)"
			"VALUES"
			"   (?, ?, ?, ?, ?, ?);"
			<< id
			<< userInfo.getAge()
			<< userInfo.getHeight()
			<< userInfo.getWeight()
			<< userInfo.getActivityLevel()
			<< userInfo.getGender();
	}
	catch (std::exception& ex)
	{
		std::cerr << "Adding user info failed: " << ex.what() << '\n';
	}
}

void addUserGoals(database& db, User& user)
{
	try
	{
		int id{};
		
		UserGoals userGoals{ user.getUserGoals() };

		db << "SELECT id FROM user WHERE username = ?;" << user.getUsername() >> id;

		std::cout << userGoals;

		db <<
			"INSERT INTO"
			"   userGoal (userId, calorieGoal, fatPercentage, carbPercentage, proteinPercentage, mealsPerDay)"
			"VALUES"
			"   (?, ?, ?, ?, ?, ?);"
			<< id
			<< userGoals.getCalorieGoal()
			<< userGoals.getFatPercentage()
			<< userGoals.getCarbPercentage()
			<< userGoals.getproteinPercentage()
			<< userGoals.getMealsPerDay();
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Adding user goals failed: " << ex.what() << '\n';
	}
}

void findUser(database& db, const std::string& username, std::string& pass)
{
	try
	{
		db << "SELECT password FROM user WHERE username = ?" << username >> pass;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Incorrect username or password" << '\n';
	}
}

bool findUsername(database& db, const std::string& username)
{
	int count{ 0 };

	db << "SELECT COUNT(*) FROM user WHERE username = ?" << username >> count;

	return count > 0;
}