#pragma once
#include "DbManager.h"
#include <functional>
class UiDbContext
{
	public:
	std::function<bool(const DbManager::database_entry)> filterPassGrade
			= [](const DbManager::database_entry xD) { return xD.grade > 1; };
	std::function<bool(const DbManager::database_entry)> filterNoPassGrade
		= [](const DbManager::database_entry xD) { return xD.grade < 2; };
	std::function<bool(const DbManager::database_entry, const DbManager::database_entry)> sortByName
		= [](const DbManager::database_entry& a, const DbManager::database_entry& b) {return a.studentName < b.studentName; };
	std::function<bool(const DbManager::database_entry, const DbManager::database_entry)> sortDecByName
		= [](const DbManager::database_entry& a, const DbManager::database_entry& b) {return a.studentName > b.studentName; };
	std::function<bool(const DbManager::database_entry, const DbManager::database_entry)> sortByGrade
		= [](const DbManager::database_entry& a, const DbManager::database_entry& b) {return a.grade < b.grade; };
	std::function<bool(const DbManager::database_entry, const DbManager::database_entry)> sortDecByGrade
		= [](const DbManager::database_entry& a, const DbManager::database_entry& b) {return a.grade > b.grade; };

	std::vector<DbManager::database_entry> filteringPassingGrades(DbManager obj1);
	std::vector<DbManager::database_entry> filteringNonPassingGrades(DbManager obj1);
	std::vector<DbManager::database_entry> sortIncreasingByGrade(DbManager obj1);
	std::vector<DbManager::database_entry> sortIncreasingByName(DbManager obj1);
	std::vector<DbManager::database_entry> sortDecreasingByGrade(DbManager obj1);
	std::vector<DbManager::database_entry> sortDecreasingByName(DbManager obj1);

};

