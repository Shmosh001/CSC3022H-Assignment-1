#include <iostream>
#include "StudentDatabase.h"




int main()
{

	using namespace SHMOSH001;
	using namespace std;
	//all possible variables that the user may enter about a student
	string name;
	string surname;
	string StudentNumber;
	string ClassRecord;

	while (true)
	{
		//char used for user selection
		char c;
		cout << "Enter a number (or 'q' to quit) followed by enter (return key):\n";
		cout << "1: Add student\n2: Read database\n3: Save database\n4: Display given student data\n5: Grade student\n";
		cout << "q: Quit\n";
		cin >> c;

		//This lets the user add a student to the database
		if(c == '1')
		{

			cout << "Enter student first name:\n";
			cin >> name;
			cout << "Enter student surname:\n";
			cin >> surname;
			cout << "Enter student number:\n";
			cin >> StudentNumber;
			cout << "Enter student grades seperated by a space:\n";
			cin.ignore(); //ignores the new line as an input
			getline(cin, ClassRecord); //reads the whole line input instead of up to a whitespace


			cout << "function addStudent() called\n";
			//method addStudent called
			addStudent(name,surname,StudentNumber,ClassRecord);


		}

		//reads the database
		else if(c == '2')
		{

			cout << "function readDatabase() called\n";
			readDatabase();
		}

		//saves changes to database
		else if(c == '3')
		{

			cout << "function saveDatabase() called\n";
			saveDatabase();
		}

		//displays a particular student based on student number
		else if(c == '4')
		{

			string StudentNumber;
			cout << "function displayStudent() called\n";
			cout << "Enter student number(uppercase):\n";
			cin >> StudentNumber;
			displayStudent(StudentNumber);

		}

		//gets average grade of student based on student number
		else if(c == '5')
		{

			string StudentNumber;
			cout << "function gradeStudent() called\n";
			cout << "Enter student number(uppercase):\n";
			cin >> StudentNumber;
			gradeStudent(StudentNumber);
		}

		//quits program
		else if(c == 'q')
		{
			break;
		}

	}

	return 0;
}
