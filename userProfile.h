#pragma once

#include <string>
#include <iostream>

class UserInfo
{
public:
	UserInfo(const std::string& gender, int age, int height, int weight, int activityLevel)
		:m_gender{ gender }, m_age{ age }, m_height{ height }, m_weight{ weight },
		m_activityLevel{ activityLevel }
	{}

	const std::string& getGender() const { return m_gender; }
	int getAge() const { return m_age; }
	int getHeight() const { return m_height; }
	int getWeight() const { return m_weight; }
	int getActivityLevel() const { return m_activityLevel; }

	void setAge(int age) { m_age = age; }
	void setHeight(int height) { m_height = height; }
	void setWeight(int weight) { m_weight = weight; }
	void setActivityLevel(int activityLevel) { m_activityLevel = activityLevel; }
	void setGender(const std::string& gender) { m_gender = gender; }

	friend std::ostream& operator<< (std::ostream& out, const UserInfo& u)
	{
		std::cout << '\n';
		out << "Gender:        " << u.getGender() << '\n';
		out << "Age:           " << u.getAge()<< '\n';
		out << "Height:        " << u.getHeight() << '\n';
		out << "Weight:        " << u.getWeight() << '\n';
		out << "activityLevel: " << u.getActivityLevel() << '\n';
		std::cout << '\n';

		return out;
	}

private:
	std::string m_gender{};
	int m_age{};
	int m_height{};
	int m_weight{};
	int m_activityLevel{};
};

class UserGoals
{
public:
	UserGoals(int calorieGoal, int fatPercentage, int carbPercentage, int proteinPercentage, int mealsPerDay)
		:m_calorieGoal{ calorieGoal }, m_fatpercentage{ fatPercentage },
		m_carbPercentage{ carbPercentage }, m_proteinPercentage{ proteinPercentage },
		m_mealsPerDay{mealsPerDay}
	{}

	const int getCalorieGoal() const { return m_calorieGoal; }
	const int getFatPercentage() const { return m_fatpercentage; }
	const int getCarbPercentage() const { return m_carbPercentage; }
	const int getproteinPercentage() const { return m_proteinPercentage; }
	const int getMealsPerDay() const { return m_mealsPerDay; }

	void setCalorieGoal(int goal) { m_calorieGoal = goal; }
	void setFatPercentage(int fatPercentage) { m_fatpercentage = fatPercentage; }
	void setCarbPercentage(int carbPercentage) { m_carbPercentage = carbPercentage; }
	void setProteinPercentage(int proteinPercentage) { m_proteinPercentage = proteinPercentage; }
	void setMealsPerDay(int mealsPerDay) { m_mealsPerDay = mealsPerDay; }

	friend std::ostream& operator<< (std::ostream& out, const UserGoals& u)
	{
		std::cout << '\n';
		out << "Calorie goal:            " << u.getCalorieGoal() << '\n';
		out << "Fat percentage:          " << u.getFatPercentage() << '\n';
		out << "Protein percentage:      " << u.getproteinPercentage() << '\n';
		out << "Carbohydrate percentage: " << u.getCarbPercentage() << '\n';
		out << "Meals per day:           " << u.getMealsPerDay() << '\n';
		std::cout << '\n';

		return out;
	}

private:
	int m_calorieGoal{};
	int m_fatpercentage{};
	int m_carbPercentage{};
	int m_proteinPercentage{};
	int m_mealsPerDay{};
};

class User
{
public:
	User(
		const std::string& username="", const std::string& password="",
		const std::string& gender = "", int age = 0, int height = 0, int weight = 0, int activityLevel = 0,
		int calorieGoal = 0, int fatPercentage = 0, int carbPercentage = 0, int proteinPercentage = 0,
		int mealsPerDay = 0
	)
		:m_username{ username }, m_password{ password },
		m_info{ gender, age, height, weight, activityLevel },
		m_goals{ calorieGoal, fatPercentage, carbPercentage, proteinPercentage, mealsPerDay}
	{}

	const std::string& getUsername() const { return m_username; }
	const std::string& getPassword() const { return m_password; }
	UserInfo& getUserInfo() { return m_info; }
	UserGoals& getUserGoals() { return m_goals; }

	void setUsername(const std::string& username) { m_username = username; }
	void setPassword(const std::string& password) { m_password = password; }

private:
	std::string m_username{};
	std::string m_password{};
	UserInfo m_info;
	UserGoals m_goals;
};