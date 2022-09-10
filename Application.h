#pragma once
#include <iostream>
#include "DbManager.h"
#include "UiDbContext.h"
#include <algorithm>

class Application
{
	DbManager obj1;
	UiDbContext obj2;

public:
	void displayMainMenu();
	int run();
	void modifyDatabase();
	void displayModifyDatabase();
	void loadStoreDatabase();
	void displayFilteringOptions();
	void displaySortingOptions();
	void visualize();
	void visualize(std::vector<DbManager::database_entry>);
	Application() = default;
};

