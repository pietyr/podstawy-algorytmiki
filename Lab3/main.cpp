#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student {
	string firstName;
	string lastName;
	int score;
};

/**
 * Function sorts array of students (by score) with quick sort algorithm
 * @param array
 * @param size
 * @param mode 0 - ascending sorting, other number - descending sorting
 */
void quickSort(student *&array, int size, int mode);

/**
 * Allocate array memory
 * @param array
 * @param size
 */
void loadStudents(student *&array, int *size);

/**
 * Delete array from memory
 * @param array
 */
void deleteStudentsArray(student *&array);

/**
 * Print content of students array
 * @param array
 * @param size
 */
void printStudents(student *&array, int size);

int main() {
	return 0;
}

void loadStudents(student *&array, int *size) {
	string line;
	ifstream file;
	char semicolons;
	string src = "../students.csv";

	file.open(src);
	file >> *size;

	for(int i = 0; i < *size; i++) {
		file >> line;
		istringstream ss(line);
		getline(ss, array[i].firstName, ';');
		getline(ss, array[i].lastName, ';');

		string scoreString;
		getline(ss, scoreString);

		// Conversion from string to int
		array[i].score = stoi(scoreString);
	}
	file.close();
}
