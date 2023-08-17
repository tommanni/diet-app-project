#include <string>
#include "initDatabase.h"

//TODO: implement SQLite interactions

database initDatabase()
{
	try
	{
		database db("dietDB.db");

		db <<
			"CREATE TABLE IF NOT EXISTS user ("
			"   id INTEGER PRIMARY KEY,"
			"   username TEXT,"
			"   password TEXT"
			");";

		db <<
			"CREATE TABLE IF NOT EXISTS userInfo ("
			"   id INTEGER PRIMARY KEY,"
			"   userId INTEGER,"
			"   age INTEGER,"
			"   height INTEGER,"
			"   weight INTEGER,"
			"   activityLevel INTEGER,"
			"   gender TEXT,"
			"   FOREIGN KEY(userId) REFERENCES user(id)"
			");";

		db <<
			"CREATE TABLE IF NOT EXISTS userGoal ("
			"	id INTEGER PRIMARY KEY,"
			"	userId INTEGER,"
			"	calorieGoal INTEGER,"
			"	fatPercentage INTEGER,"
			"	carbPercentage INTEGER,"
			"	proteinPercentage INTEGER,"
			"   mealsPerDay INTERGER,"
			"   FOREIGN KEY(userId) REFERENCES user(id)"
			");";

		db <<
			"CREATE TABLE IF NOT EXISTS meal ("
			"	id INTEGER PRIMARY KEY,"
			"	userId INTEGER,"
			"	name TEXT,"
			"	totalCalories INTEGER,"
			"   FOREIGN KEY(userId) REFERENCES user(id)"
			");";

		db << "CREATE TABLE IF NOT EXISTS food ("
			"   id INTEGER PRIMARY KEY,"
			"	userId INTEGER,"
			"	mealId INTEGER,"
			"	name TEXT,"
			"	grams INTEGER,"
			"   FOREIGN KEY(userId) REFERENCES user(id),"
			"   FOREIGN KEY(mealId) REFERENCES meal(id)"
			");";

		/*db <<
			"CREATE TABLE IF NOT EXISTS microNutrient ("
			"	id INTEGER PRIMARY KEY,"
			"	name TEXT"
			");";

		db <<
			"CREATE TABLE IF NOT EXISTS userMicronutrientGoal ("
			"   id INTEGER PRIMARY KEY,"
			"	userId INTEGER,"
			"	micronutrientId INTEGER,"
			"	microNutrientGoal INTEGER,"
			"   FOREIGN KEY(userId) REFERENCES user(id)"
			");";*/

		return db;
	}
	catch (std::exception& ex)
	{
		std::cerr << "Initializing database failed: " << ex.what() << '\n';
		return database("");
	}
}