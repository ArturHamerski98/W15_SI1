#include "DbManager.h"

void DbManager::addEntry(std::string studentName, int grade)
{
	if (students.count(studentName))
		std::cerr << "There is that student in DB already\n";
	else
		students[studentName] = grade;
}

void DbManager::removeEntry(std::string studentName)
{
	if (students.count(studentName))
		students.erase(studentName);
	else
		std::cerr << "Not found that student in DB\n";
}

void DbManager::modifyEntry(std::string studentName, int grade)
{
	if (students.count(studentName))
		students[studentName] = grade;
	else
		std::cerr << "Cannot find that student in DB\n";
}

std::vector<DbManager::database_entry> DbManager::getEntries()
{
	std::vector<database_entry> studentsVector(students.size());
	std::transform(students.begin(), students.end(), studentsVector.begin(), [](auto temp) {return database_entry{ temp.first,temp.second };});
	return studentsVector;
}

void DbManager::load() {

	std::string fname = "studentsDB.csv";
	std::vector<std::vector<std::string>> content;
	std::vector<std::string> row;
	std::string line, word;

	std::fstream file(fname, std::ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			std::stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		std::cout << "Could not open the file\n";

	for (int i = 0; i < content.size(); i++)
	{
		addEntry(content[i][0], std::stoi(content[i][1]));
	}
}

void DbManager::store()
{
	std::ofstream myFile("studentsDB.csv");
	int temp = 0;
	for (auto it = students.cbegin(); it != students.cend(); ++it)
	{
		if (temp != 0)
			myFile << "\n";
		myFile << it->first << "," << it->second;
		temp++;
	}

	myFile.close();

}

std::ostream& operator<<(std::ostream& os, const DbManager::database_entry& dt)
{
	os << "Name:"<<std::setw(12)<<dt.studentName << "  Grade: " << dt.grade<<"\n";
	return os;
}

std::istream& operator>>(std::istream& is, const DbManager::database_entry& dt)
{
	return is;//Nie potrafie znalezc zastosowania w moim programie
}
