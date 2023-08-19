#include "login.h"

namespace Login
{
	void printLoginScreen()
	{
		std::cout << '\n';
		std::cout << "===========================================\n";
		std::cout << "              THE LOG IN SCREEN\n";
		std::cout << "===========================================\n";
		std::cout << '\n';
	}

	bool login(database& db, int& userId)
	{
		printLoginScreen();
		while (true)
		{
			std::string pass{""};

			std::string username{};
			getUsername(username);

			std::string password{};
			getPassword(password);

			findUser(db, username, pass, userId);

			if (pass.length() < 1)
			{
				std::cout << "Try again? (y/n)\n\n";
				char cmd{ getCommand() };

				if (cmd == 'n')
					return false;
			}
			else
			{
				if (bcrypt::validatePassword(password, pass))
				{
					std::cout << "Log in succesfull!\n";
					return true;
				}
				else
				{
					std::cout << "Incorrect username or password\n";
					std::cout << "Try again? (y/n)\n\n";
					char cmd{ getCommand() };

					if (cmd == 'n')
						return false;
				}
			}
		}
	}
}