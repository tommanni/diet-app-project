#include "register.h"

namespace Register
{
	void printRegistrationScreen()
	{
		std::cout << '\n';
		std::cout << "===========================================\n";
		std::cout << "          THE REGISTRATION SCREEN\n";
		std::cout << "===========================================\n";
		std::cout << '\n';
	}

	int getActivityLevel()
	{
		int lvl{0};

		std::cout << '\n';
		std::cout << "1) Sedentary, little to no excercise\n";
		std::cout << "2) Light, excercise 1 - 3 times/week\n";
		std::cout << "3) Moderate, excerciser 4 - 5 times/week\n";
		std::cout << "4) Active, daily excercise or intense excercise 3 - 4 times/week\n";
		std::cout << "5) Very active, intense excercise 6 - 7 times/week\n";
		std::cout << '\n';

		while (lvl < 1 || lvl > 5)
		{
			std::cout << "Enter your activity level (1 - 5): ";
			std::cin >> lvl;

			if (std::cin.fail())
				ignoreInput();
		}

		return lvl;
	}

	int getHeight()
	{
		int height{0};

		while (height < 90 || height > 250)
		{
			std::cout << "Enter your height (90cm - 250cm): ";
			std::cin >> height;

			if (std::cin.fail())
				ignoreInput();
		}

		return height;
	}
	
	int getWeight()
	{
		int weight{0};

		while (weight < 30 || weight > 300)
		{
			std::cout << "Enter your weight (30kg - 300kg): ";
			std::cin >> weight;

			if (std::cin.fail())
				ignoreInput();
		}

		return weight;
	}

	void getGender(std::string& gender)
	{
		while (gender != "male" && gender != "female")
		{
			std::cout << "Enter your gender (male / female): ";
			std::cin >> gender;

			if (std::cin.fail())
				ignoreInput;
		}
	}

	int getAge()
	{
		int age{0};

		while (age < 15 || age > 80)
		{
			std::cout << "Enter you age (15 - 80): ";
			std::cin >> age;

			if (std::cin.fail())
				ignoreInput();
		}

		return age;
	}

	void getUserInfo(User& user)
	{
		UserInfo& userInfo{ user.getUserInfo() };
		userInfo.setAge(getAge());

		std::string gender{};
		getGender(gender);
		userInfo.setGender(gender);

		userInfo.setHeight(getHeight());
		userInfo.setWeight(getWeight());

		userInfo.setActivityLevel(getActivityLevel());
	}

	void getUserData(database& db, User& user)
	{
		std::cout << "\nLets set up your profile!\n";

		std::cout << "\nWould you like to use a calorie calculator to find out your caloric needs? (y/n): ";
		char cmd{ getCommand() };
		std::cout << '\n';

		getUserInfo(user);

		int calorieGoal{};
		if (cmd == 'y')
		{
			int calories{calorieCalculator(user)};
			printCalorieNeeds(calories);
		}

		getUserGoals(user);
	}

	void saveUserData(database& db, User& user)
	{
		addUser(db, user);
		addUserInfo(db, user);
		addUserGoals(db, user);
	}

	void registration(database& db)
	{
		printRegistrationScreen();
		while (true)
		{
			std::string username{};
			getUsername(username);
			std::string password{};
			getPassword(password);

			password = bcrypt::generateHash(password);

			if (findUsername(db, username))
				std::cout << "Username taken. Try again.\n";
			else
			{
				User user{username, password};
				getUserData(db, user);
				saveUserData(db, user);
				std::cout << "Registration succesfull!\n";
				return;
			}
		}
	}
}