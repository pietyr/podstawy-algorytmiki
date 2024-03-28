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
 * Rearange array (Find the partition point) for quickSort
 * @param array
 * @param low
 * @param high
 * @param size
 * @param mode
 * @return
 */
int partition(student *&array, int *size, int mode, int low, int high);

/**
 * Function sorts array of students (by score) with quick sort algorithm
 * @param array
 * @param low
 * @param high
 * @param size
 * @param mode 0 - ascending sorting, other number - descending sorting
 */
void quickSort(student *&array, int *size, int mode, int low, int high);

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
	quickSort(array, size, 0, 0, *size - 1);
	printStudents(array, size);
	quickSort(array, size, 1, 0, *size - 1);
	printStudents(array, size);
	delete size;
	return 0;
}

void swap(student *a, student *b) {
	student temp = *a;
	*a = *b;
	*b = temp;
}

int partition(student *&array, int *size, int mode, int low, int high) {
	int pivot = array[high].score;
	int index = low - 1;

	// Compare every element of the array with pivot
	for(int i = low; i < high; i++) {
		// Swap if element is smaller than pivot
		if(mode == 0 && array[i].score <= pivot || mode != 0 && array[i].score >= pivot) {
			swap(array[++index], array[i]);
		}
	}

	swap(array[index + 1], array[high]);

	return index + 1;
}

void quickSort(student *&array, int *size, int mode, int low, int high) {
	if(low < high) {
		int pivot = partition(array, size, mode, low, high);

		quickSort(array, size, mode, low, pivot - 1);
		quickSort(array, size, mode, pivot + 1, high);

	}
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

void deleteStudentsArray(student *&array) {
	delete []array;
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