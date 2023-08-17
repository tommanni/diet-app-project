#include "login.h"

namespace Login
{
	void printLoginScreen()
	{
		std::cout << '\n';
		std::cout << "===========================================\n";
		std::cout << "              THE LOG IN SCREEN\n";
		std::cout << "===========================================\n";
	}

	bool validatePassword(std::string& password, std::string pass)
	{
		if (bcrypt::validatePassword(password, pass))
			return true;
		else
		{
			std::cout << "Wrong password, try again.\n";
			return false;
		}
	}

	bool login(database& db)
	{
		while (true)
		{
			printLoginScreen();

			std::string pass{""};

			std::string username{};
			getUsername(username);

			std::string password{};
			getPassword(password);

			findUser(db, username, pass);

			if (pass.length() < 1)
			{
				std::cout << "Try again? (y/n)\n";
				char cmd{ getCommand() };

				if (cmd == 'n')
					return false;
			}
			else
				if (validatePassword(password, pass))
					return true;
		}
	}
}