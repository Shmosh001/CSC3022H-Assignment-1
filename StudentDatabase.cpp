/*
 * StudentDatabase.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: Osher
 */

#include "StudentDatabase.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


//structure with attributes of the database
struct StudentRecord
{
	std::string name;
	std::string surname;
	std::string StudentNumber;
	std::string ClassRecord;
};

std::vector<StudentRecord> database;

//add student method. parameters receive needed data to add student
void SHMOSH001::addStudent(std::string name, std::string surname, std::string StudentNumber, std::string ClassRecord)
{
	using namespace std;
	bool duplicate = false; //checker for duplicate
	int position;
	int size = database.size();
	//searches vector database to see if student number already exists
	for(int i = 0; i < size; i++)
	{
		if(database[i].StudentNumber.compare(StudentNumber) == 0)
		{
			duplicate = true;
			position = i;
		}
	}

	//updates name, surname and grades
	if(duplicate == true)
	{
		database.at(position).name = name;
		database.at(position).surname = surname;
		database.at(position).ClassRecord = ClassRecord;


	}

	//inserts a new student with all relevant information at the end
	else
	{
		StudentRecord temp;
		temp.name = name;
		temp.surname = surname;
		temp.StudentNumber = StudentNumber;
		temp.ClassRecord = ClassRecord;
		database.push_back(temp);
	}

}

//reads information from text file into a vector
void SHMOSH001::readDatabase()
{
	using namespace std;

	string entry;
	ifstream file ("database.txt"); // used to read a file
	//reads each line of file
	while (getline(file,entry))
	{
		//vector to contain each attribute from split
		vector<string> record;
		stringstream section;
		section.str(entry);
		string split;
		//split by '#' for each attribute
		while(getline(section, split, '#'))
		{
			record.push_back(split);
		}

		//insert student into the vector database
		StudentRecord temp;
		temp.name = record[0];
		temp.surname = record[1];
		temp.StudentNumber = record[2];
		temp.ClassRecord = record[3];
		database.push_back(temp);

	}


}

//saves changes made to database vector and writes to a file
void SHMOSH001::saveDatabase()
{
	using namespace std;
	ofstream file; //used to write to a file
	file.open("database.txt");
	int length = database.size();

	//goes through each student in the vector and joins the data using a '#'
	for(int i = 0; i < length; i++)
	{
		cout << "Here";
		string entry = database[i].name + "#" + database[i].surname + "#" + database[i].StudentNumber + "#" + database[i].ClassRecord + "\n";
		file << entry;
	}

	file.close();

}

//displaces a certain student with the received student number
void SHMOSH001::displayStudent(std::string StudentNumber)
{
	using namespace std;
	int length = database.size();
	for (int i = 0; i < length; i++)
	{
		//searches through every student number in database
		string studentNo = database[i].StudentNumber;
		cout << studentNo << "\n";

		//compares current student number and given student number. If they match then student info is displayed
		if(StudentNumber.compare(studentNo) == 0)
		{
			cout << "Name: " << database[i].name << "\n";
			cout << "Surname: " << database[i].surname << "\n";
			cout << "Student Number: " << database[i].StudentNumber << "\n";
			cout << "Class Record: " << database[i].ClassRecord << "\n";
			break;

		}
	}
}

void SHMOSH001::gradeStudent(std::string StudentNumber)
{
	using namespace std;
	bool exist = false; //boolean to see if student exists
	int size = database.size();
	//iterate through database
	for (int i = 0; i < size; i++)
	{
		//check if student numbers match
		if(database[i].StudentNumber.compare(StudentNumber)==0)
		{
				vector<string> results; //stores the results of the split method
				stringstream grades;
				grades.str(database[i].ClassRecord);
				string grade;
				//splits grades by a whitespace
				while(getline(grades, grade, ' '))
				{
					results.push_back(grade);
				}

				int totalGrade;
				int length = results.size();

				//iterate through results vector to work out sum of all the grades
				for(int i = 0; i < length; i++)
				{
					string result = results[i];
					int num;
					istringstream (result) >> num;
					totalGrade += num;
				}

				//calculates average grade
				double averageGrade = totalGrade/length;
				cout << StudentNumber << " average grade: " << averageGrade << "\n";
				exist = true;
				break;
		}

		if(exist == false)
		{
			cout << "Student Number does not exist\n";
			break;
		}
	}



}
