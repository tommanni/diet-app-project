#include <iostream>
#include "userInterface.h"

//TODO: implement user inteface functionality

namespace UserInterface
{
	void printAuthScreen()
	{
		std::cout << '\n';
		std::cout << "===========================================\n";
		std::cout << "         THE AUTHENTICATION SCREEN\n";
		std::cout << "===========================================\n";
		std::cout << '\n';
	}

	void printMainMenuScreen()
	{
		std::cout << '\n';
		std::cout << "===========================================\n";
		std::cout << "           THE MAIN MENU SCREEN\n";
		std::cout << "===========================================\n";
		std::cout << '\n';
	}

	void printAuthOptions()
	{
		std::cout << '\n';
		std::cout << "Register to:\n";
		std::cout << "- Gain access to a calorie calculator\n";
		std::cout << "- Gain ability to save your meal plans\n";
		std::cout << '\n';
		std::cout << "Enter 1 to log in\n";
		std::cout << "Enter 2 to register\n";
		std::cout << "Enter 3 to continue as a guest\n";
		std::cout << "Enter 4 to exit the program\n";
		std::cout << '\n';
	}

	//TODO: implement exit
	int getAuthCommand()
	{
		printAuthOptions();

		int command{ 0 };

		while (command > 4 || command < 1)
		{
			std::cout << "Enter your choice: ";
			std::cin >> command;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		std::cout << '\n';
		return command;
	}

	void printMenuOptions()
	{
		std::cout << '\n';
		std::cout << "Enter 1 to edit meals\n";
		std::cout << "Enter 2 to edit user info\n";
		std::cout << "Enter 3 to edit user goals\n";
		std::cout << "Enter 4 to use calorie calculator\n";
		std::cout << "Enter 5 to log out\n";
		std::cout << '\n';
	}

	int getMenuOption()
	{
		int option{};

		while (option < 1 || option > 5)
		{
			std::cout << "Enter your choice: ";
			std::cin >> option;

			if (std::cin.fail())
				ignoreInput();
		}

		std::cout << '\n';
		return option;
	}

	void mainMenu(database& db, bool loggedIn)
	{
		//TODO: implement main menu features
		while (true)
		{
			printMainMenuScreen();
			printMenuOptions();
			int option{ getMenuOption() };

			switch (option)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				return;
			default:
				break;
			}
		}
	}

	void loginScreenChoice()
	{
		while (true)
		{
			printAuthScreen();

			sqlite::database db{ initDatabase() };

			int loginCommand{ getAuthCommand() };

			bool loggedIn{ false };

			switch (loginCommand)
			{
			case 1:
				loggedIn = Login::login(db);
				break;
			case 2:
				Register::registration(db);
				break;
			case 3:
				mainMenu(db, loggedIn);
				break;
			case 4:
				return;
			default:
				break;
			}

			if (loggedIn)
			{
				mainMenu(db, loggedIn);
			}
		}

	}
}