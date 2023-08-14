#pragma once

#include <string>

class UserInfo
{
public:
	UserInfo(const std::string& gender, int age, int height, int weight, int activityLevel )
		:m_gender{ gender }, m_age{ age }, m_height{ height }, m_weight {weight},
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
	UserGoals(int calorieGoal, int fatPercentage, int carbPercentage, int proteinPercentage)
		:m_calorieGoal{calorieGoal}, m_fatpercentage{fatPercentage},
		m_carbPercentage{carbPercentage}, m_proteinPercentage{proteinPercentage}
	{}

	int getCalorieGoal() const { return m_calorieGoal; }
	int getFatPercentage() const { return m_fatpercentage; }
	int getCarbPercentage() const { return m_carbPercentage; }
	int getproteinPercentage() const { return m_proteinPercentage; }

	void setCalorieGoal(int goal) { m_calorieGoal = goal; }
	void setFatPercentage(int fatPercentage) { m_fatpercentage = fatPercentage; }
	void setCarbPercentage(int carbPercentage) { m_carbPercentage = carbPercentage; }
	void setProteinPercentage(int proteinPercentage) { m_proteinPercentage = proteinPercentage; }

private:
	int m_calorieGoal{};
	int m_fatpercentage{};
	int m_carbPercentage{};
	int m_proteinPercentage{};
};

class User
{
public:
	User(
		const std::string& username, const std::string& password,
		const std::string& gender="", int age=0, int height=0, int weight=0, int activityLevel=0,
		int calorieGoal=0, int fatPercentage=0, int carbPercentage=0, int proteinPercentage=0
	)
		:m_username{ username }, m_password{ password },
		m_info{gender, age, height, weight, activityLevel},
		m_goals{calorieGoal, fatPercentage, carbPercentage, proteinPercentage}
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