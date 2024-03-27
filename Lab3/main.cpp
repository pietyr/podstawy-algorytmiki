#include <iostream>

using namespace std;

struct student {

};

/**
 * Function sorts array of students (by points) with quick sort algorithm
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
void loadStudents(student *&array, int size);

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
