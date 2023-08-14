#include "login.h"

namespace Login
{
	void validatePassword(std::string& password, std::string pass)
	{
		if (bcrypt::validatePassword(password, pass))
		{

		}
		else
			std::cout << "Wrong password, try again.\n";
	}

	void login(database& db)
	{
		while (true)
		{
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
					UserInterface::loginScreenChoice();
			}
			else
				validatePassword(password, pass);	
		}
	}
}