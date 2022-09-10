#include "Application.h"

void Application::displayMainMenu()
{
    std::cout << "1. Modify database\n";
    std::cout << "2. Load/Store database\n";
    std::cout << "3. Filter database\n";
    std::cout << "4. Set sorting order\n";
    std::cout << "5. Visualize database\n";
    std::cout << "6. Exit\n";
}

int Application::run()
{
    int choice;

    do {
        displayMainMenu();

        std::cout << "\nCHOICE:";
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1) {
            modifyDatabase();
        }
        else if (choice == 2) {
            loadStoreDatabase();
        }
        else if (choice == 3) {
            displayFilteringOptions();
        }
        else if (choice == 4) {
            displaySortingOptions();
        }
        else if (choice == 5) {
            visualize();
        }

    } while (choice != 6);

    return 0;
}

void Application::modifyDatabase()
{
    int choice;

    do {
        displayModifyDatabase();
        std::cout << "\nCHOICE:";
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1) {

            std::string tempName;
            int tempGrade;
            std::cout << "Enter name: ";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> tempName;

            std::cout << "Enter grade: ";
            std::cin >> tempGrade;

            obj1.addEntry(tempName,tempGrade);
        }
        else if (choice == 2) {
            std::string tempName;
            std::cout << "Enter student's name to remove: ";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> tempName;

            obj1.removeEntry(tempName);
            break;
        }
        else if (choice == 3) {
            std::string tempName;
            int tempGrade;
            std::cout << "Enter student's name: ";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> tempName;

            std::cout << "Enter new grade: ";
            std::cin >> tempGrade;

            obj1.modifyEntry(tempName,tempGrade);
            break;
        }

    } while (choice != 4);

}

void Application::displayModifyDatabase()
{
    std::cout << "1. Add student \n";
    std::cout << "2. Remove student \n";
    std::cout << "3. Modify student \n";
    std::cout << "4. Back ";
}
void Application::loadStoreDatabase()
{
    std::cout << "Load: 1\n";
    std::cout << "Save: 2\n";

    std::cout << "\nCHOICE:";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        obj1.load();
        break;
    case 2:
        obj1.store();
        break;
    }

}

void Application::displayFilteringOptions()
{
    std::cout << "\n1. Passing grades\n";
    std::cout << "2. Non passing grades\n";
    std::cout << "3. All grades\n";
    std::cout << "4. Back\n";

    std::cout << "\nCHOICE:";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        visualize(obj2.filteringPassingGrades(obj1));
        break;
    case 2:
        visualize(obj2.filteringNonPassingGrades(obj1));
        break;
    case 3:
        visualize();
        break;
    case 4:
        displayMainMenu();
        break;
    }
}
void Application::displaySortingOptions()
{
    std::cout << "\n1. Incresing by name\n";
    std::cout << "2. Decreasing by name\n";
    std::cout << "3. Increasing by grade\n";
    std::cout << "4. Decreasing by grade\n";
    std::cout << "5. Back\n\n>> ";

    std::cout << "\nCHOICE:";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        visualize(obj2.sortIncreasingByName(obj1));
        break;
    case 2:
        visualize(obj2.sortDecreasingByName(obj1));
        break;
    case 3:
        visualize(obj2.sortIncreasingByGrade(obj1));
        break;
    case 4:
        visualize(obj2.sortDecreasingByGrade(obj1));
        break;
    case 5:
        displayMainMenu();
        break;
    }
}

void Application::visualize()
{
    std::vector<DbManager::database_entry>records=obj1.getEntries();
    for (auto record : records)
    {
        std::cout << record;
    }
}
void Application::visualize(std::vector<DbManager::database_entry> records)
{
    for (auto record : records)
    {
        std::cout << record;
    }
}

