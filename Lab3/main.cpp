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
void printStudents(student *&array, int *size);

int main() {
	student *array = nullptr;
	int *size = new int;
	loadStudents(array, size);
	printStudents(array, size);
	delete size;
	return 0;
}

void loadStudents(student *&array, int *size) {
	string line;
	ifstream file;
	char semicolons;
	string src = "students.csv";

	file.open(src);
	file >> *size;
	array = new student[*size];

	for (int i = 0; i < 2; i++) {
		file >> semicolons;
	}

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


void printStudents(student *&array, int *size) {
	cout << "Imię Nazwisko - Liczba punktów" << endl;
	cout << "[" << endl;
	for(int i = 0; i < *size; i++) {
		cout << "\t" << array[i].firstName << " " << array[i].lastName << " - " << array[i].score;
		if(i != *size - 1) {
			cout << ",";
		}
		cout << endl;
	}
	cout << "]" << endl;
}