/*
 * StudentDatabase.h
 *
 *  Created on: Feb 25, 2015
 *      Author: Osher
 */

#ifndef STUDENTDATABASE_H_
#define STUDENTDATABASE_H_

#include <string>
#include <vector>


namespace SHMOSH001
{

	void addStudent(std::string name, std::string surname, std::string StudentNumber, std::string ClassRecord);
	void readDatabase();
	void saveDatabase();
	void displayStudent(std::string StudentNumber);
	void gradeStudent(std::string StudentNumber);
}

#endif /* STUDENTDATABASE_H_ */
