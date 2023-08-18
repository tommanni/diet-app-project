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

	int getCarbPercentage()
	{
		int percentage{0};

		do
		{
			std::cout << "Enter the percentage of carbohydrates (0% - 65%): ";
			std::cin >> percentage;
			
			if (std::cin.fail())
				ignoreInput();

		} while (percentage < 0 || percentage > 65);

		std::cout << '\n';
		return percentage;
	}
	
	int getProteinPercentage()
	{
		int percentage{0};

		do
		{
			std::cout << "Enter the percentage of protein (10% - 35%): ";
			std::cin >> percentage;
			
			if (std::cin.fail())
				ignoreInput();

		} while (percentage < 10 || percentage > 35);

		std::cout << '\n';
		return percentage;
	}

	void setCustomMacronutrientGoals(User& user)
	{
		UserGoals& goals{ user.getUserGoals() };

		goals.setCarbPercentage(getCarbPercentage());
		goals.setProteinPercentage(getProteinPercentage());
		int fatPercentage{ 100 - goals.getCarbPercentage() - goals.getproteinPercentage() };
		goals.setFatPercentage(fatPercentage);

		std::cout << "Values set.\n";
		std::cout << "Carbohydrates: " << goals.getCarbPercentage() << "%\n";
		std::cout << "Protein:       " << goals.getproteinPercentage() << "%\n";
		std::cout << "Fat:           " << goals.getFatPercentage() << "%\n";
		std::cout << '\n';
	}

	int getCalorieGoal()
	{
		int calorieGoal{0};

		while (calorieGoal < 1500 || calorieGoal > 8000)
		{
			std::cout << "Enter your calorie goal (1500 - 8000): ";
			std::cin >> calorieGoal;

			if (std::cin.fail())
				ignoreInput();
		}

		std::cout << '\n';
		return calorieGoal;
	}

	int getCmd()
	{
		int cmd{ 0 };

		while (cmd != 1 && cmd != 2)
		{
			std::cout << "Enter your choice: ";
			std::cin >> cmd;

			if (std::cin.fail())
				ignoreInput();
		}

		std::cout << '\n';
		return cmd;
	}

	int getMealsPerDay()
	{
		int meals{ 0 };

		while (meals < 1 || meals > 10)
		{
			std::cout << "Enter the amount of meals you eat per day: ";
			std::cin >> meals;

			if (std::cin.fail())
				ignoreInput();
		}

		std::cout << '\n';
		return meals;
	}

	void getUserGoals(User& user)
	{
		UserGoals& goals{ user.getUserGoals() };
		
		goals.setCalorieGoal(getCalorieGoal());
		goals.setMealsPerDay(getMealsPerDay());

		std::cout << "Enter 1 to set custom carbohydrate/protein/fat goal percentages.\n";
		std::cout << "Enter 2 to use default values 40/30/30.\n";
		
		int cmd{ getCmd() };

		if (cmd == 2)
		{
			goals.setCarbPercentage(40);
			goals.setProteinPercentage(30);
			goals.setFatPercentage(30);
			return;
		}

		setCustomMacronutrientGoals(user);
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