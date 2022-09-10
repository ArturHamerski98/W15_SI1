#include "UiDbContext.h"

std::vector<DbManager::database_entry> UiDbContext::filteringPassingGrades(DbManager obj1)
{
	

	std::vector<DbManager::database_entry> allRecords = obj1.getEntries();
	std::vector<DbManager::database_entry> filtredRecords;
	std::copy_if(allRecords.begin(), allRecords.end(), std::back_inserter(filtredRecords), filterPassGrade);
	return filtredRecords;
}

std::vector<DbManager::database_entry> UiDbContext::filteringNonPassingGrades(DbManager obj1)
{
	std::vector<DbManager::database_entry> allRecords = obj1.getEntries();
	std::vector<DbManager::database_entry> filtredRecords;
	std::copy_if(allRecords.begin(), allRecords.end(), std::back_inserter(filtredRecords), filterNoPassGrade);
	return filtredRecords;
}

std::vector<DbManager::database_entry> UiDbContext::sortIncreasingByGrade(DbManager obj1)
{
	std::vector<DbManager::database_entry> allRecords = obj1.getEntries();
	std::sort(allRecords.begin(), allRecords.end(), sortByGrade);
	return allRecords;
}

std::vector<DbManager::database_entry> UiDbContext::sortDecreasingByGrade(DbManager obj1)
{
	std::vector<DbManager::database_entry> allRecords = obj1.getEntries();
	std::sort(allRecords.begin(), allRecords.end(), sortDecByGrade);
	return allRecords;
}

std::vector<DbManager::database_entry> UiDbContext::sortIncreasingByName(DbManager obj1)
{
	std::vector<DbManager::database_entry> allRecords = obj1.getEntries();
	std::sort(allRecords.begin(), allRecords.end(), sortByName);
	return allRecords;
}

std::vector<DbManager::database_entry> UiDbContext::sortDecreasingByName(DbManager obj1)
{
	
	std::vector<DbManager::database_entry> allRecords = obj1.getEntries();
	std::sort(allRecords.begin(), allRecords.end(), sortDecByName);
	return allRecords;
}
