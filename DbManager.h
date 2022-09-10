#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iomanip>


class DbManager
{
public:
	struct database_entry {
		std::string studentName;
		int grade;
	};
	DbManager() = default;
	~DbManager() = default;
	std::unordered_map<std::string, int> students;
	void addEntry(std::string, int);
	void removeEntry(std::string);
	void modifyEntry(std::string,int);
	std::vector<database_entry>getEntries();
	void load();
	void store();

	friend std::ostream& operator<<(std::ostream& os, const DbManager::database_entry& dt);
	friend std::istream& operator>>(std::istream& is, const DbManager::database_entry& dt);

};

