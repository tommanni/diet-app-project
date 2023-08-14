#include "calorieCalculator.h"

//TODO: implement calorie calculator functionality

void printCalorieNeeds(int calories)
{
	std::cout << '\n';
	std::cout << "ESTIMATED CALORIES FOR DIFFERENT GOALS:\n";
	std::cout << "Weight gain:      " << static_cast<int>(calories * 1.18) << '\n';
	std::cout << "mild weight gain: " << static_cast<int>(calories * 1.09) << '\n';
	std::cout << "Maintain weight:  " << calories << '\n';
	std::cout << "Mild weight loss: " << static_cast<int>(calories * 0.91) << '\n';
	std::cout << "Weight loss:      " << static_cast<int>(calories * 0.82) << '\n';
	std::cout << '\n';
}

double getActivityLevelFactor(User& user)
{
	bool factor{};

	switch (user.getUserInfo().getActivityLevel())
	{
	case 1:
		return 1.2;
	case 2:
		return 1.375;
	case 3:
		return 1.55;
	case 4:
		return 1.725;
	case 5:
		return 1.9;
	default:
		std::cerr << "Error getting activityLevelFactor\n";
		return 0;
	}
}

// Mifflin-St Jeor formula for males
int MifflinStJeorMale(User& user)
{
	UserInfo userInfo{ user.getUserInfo() };

	return 10 * userInfo.getWeight() + 6.25 * userInfo.getHeight() - 5 * userInfo.getAge() + 5;
}

// Mifflin-St jeor formula for females
int MifflinStJeorFemale(User& user)
{
	UserInfo userInfo{ user.getUserInfo() };

	return 10 * userInfo.getWeight() + 6.25 * userInfo.getHeight() - 5 * userInfo.getAge() - 161;
}

int calorieCalculator(User& user)
{
	double activityLevelFactor{ getActivityLevelFactor(user) };

	if (user.getUserInfo().getGender() == "male")
		return static_cast<int>(MifflinStJeorMale(user) * activityLevelFactor);

	return static_cast<int>(MifflinStJeorFemale(user) * activityLevelFactor);
}
