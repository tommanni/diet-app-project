#include <iostream>
#include "userInterface.h"

//TODO: implement user inteface functionality

namespace UserInterface
{
    void printLoginScreen()
    {
        std::cout << '\n';
        std::cout << "===========================================\n";
        std::cout << "              THE LOG IN SCREEN\n";
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
        std::cout << '\n';

        int command{ 0 };

        while (command > 3 || command < 1)
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
        UserInterface::printLoginScreen();

        sqlite::database db{ initDatabase() };

        int loginCommand{ UserInterface::getLoginCommand() };

        switch (loginCommand)
        {
        case 1:
            Login::login(db);
        case 2:
            Register::registration(db);
        default:
            break;
        }
    }
}