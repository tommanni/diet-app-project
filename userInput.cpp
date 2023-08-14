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