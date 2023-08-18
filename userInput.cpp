#include "userInput.h"

void ignoreInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void getUsername(std::string& username)
{
	while (username.length() < 1)
	{
		std::cout << "Username: ";
		std::cin >> username;

		if (std::cin.fail())
			ignoreInput();

	}
}

void getPassword(std::string& password)
{
	while (password.length() < 1)
	{
		std::cout << "Password: ";
		std::cin >> password;

		if (std::cin.fail())
			ignoreInput();
	}
}

char getCommand()
{
	char c{};

	while (c != 'y' && c != 'n')
	{
		std::cout << "Command: ";
		std::cin >> c;

		if (std::cin.fail())
			ignoreInput();
	}

	return c;
}

int getCalorieGoal()
{
	int calorieGoal{ 0 };

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

int getCarbPercentage()
{
	int percentage{ 0 };

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
	int percentage{ 0 };

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



void getUserGoals(User& user)
{
	UserGoals& goals{ user.getUserGoals() };

	std::cout << "Lets set up your goals!\n\n";

	goals.setCalorieGoal(getCalorieGoal());
	goals.setMealsPerDay(getMealsPerDay());

	std::cout << "Enter 1 to set custom carbohydrate/protein/fat goal percentages.\n";
	std::cout << "Enter 2 to use default values 40/30/30.\n\n";

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