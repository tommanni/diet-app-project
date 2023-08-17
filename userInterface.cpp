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
	}
	//TODO: implement exit
	int getLoginCommand()
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
	//TODO: impelement exit
	void loginScreenChoice()
	{
		while (true)
		{
			printAuthScreen();

			sqlite::database db{ initDatabase() };

			int loginCommand{ getLoginCommand() };

			bool loggedIn{ false };

			switch (loginCommand)
			{
			case 1:
				loggedIn = Login::login(db);
				break;
			case 2:
				Register::registration(db);
				loggedIn = Login::login(db);
				break;
			case 3:
				//TODO: implement contienue as a guest
			case 4:
				return;
			default:
				break;
			}

			if (loggedIn)
			{

			}
		}

	}
}