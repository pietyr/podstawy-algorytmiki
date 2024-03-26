#include <iostream>
#include <time.h>

using namespace std;


// SORTING ALGORITHMS

/**
 * Function swaps 2 integers
 * @param a
 * @param b
 */
void swap(int &a, int &b);

/**
 * Function sorts 1D array ascending/descending (depending on the mode),
 * using bubble sort algorithm
 * @param array array to sort
 * @param size size of the array
 * @param mode 0 (default) - ascending, 1 - descending
 */
void bubbleSort(int *&array, int size, int mode = 0);

/**
 * Function sorts 1D array ascending/descending (depending on the mode),
 * using selection sort algorithm
 * @param array array to sort
 * @param size size of the array
 * @param mode 0 (default) - ascending, 1 - descending
 */
void selectionSort(int *&array, int size, int mode = 0);

/**
 * Function sorts 1D array ascending/descending (depending on the mode),
 * using insert sort algorithm
 * @param array array to sort
 * @param size size of the array
 * @param mode 0 (default) - ascending, 1 - descending
 */
void insertSort(int *array, int size, int mode = 0);

/**
 * Function sorts 2D array[X][Y] ascending/descending (depending on the mode),
 * using bubble sort algorithm
 * by one selected column Y (values in rows are constant)
 * @param array 2D array to sort
 * @param sizeX size of the array (rows)
 * @param sizeY size of the array (columns)
 * @param mode 0 (default) - ascending, 1 - descending
 * @param column index of column (array [][column])
 */
void bubbleSort2D(int **array, int sizeX, int sizeY, int column, int mode = 0);


// EXERCISES WRAPPER FUNCTIONS

void zadanie2();
void zadanie3();

// UTILITY FUNCTIONS FROM Lab1

/**
 * Allocate memory for one dimension array
 * @param array Reference to the array
 * @param size Size of the array
 */
void allocateMemory1D(int *&array, int size);

/**
 * Fill the one dimension array with numbers from <a,b> range
 * @param array Reference to target array
 * @param size Size of the target array
 * @param min Lowest fill value (including)
 * @param max Highest fill value (including)
 */
void randomFill1DArray(int *&array, int size, int min, int max);

/**
 * Free memory of the one dimension array
 * @param array Target array
 */
void deleteArray1D(int *&array);

/**
 * Print content of the one dimension array
 * @param array Target array
 * @param size Size of the array
 */
void print1D(int *&array, int size);

int main(){
	srand(time(nullptr));
	int selection;
	do {
		cout << "Lab 2" << endl;
		cout << "1. Zadanie 2.2 - Sortowanie bąbelkowe" << endl;
		cout << "2. Zadanie 2.3 - Sortowanie przez wybór" << endl;
		cout << "5. Koniec programu" << endl;
		cout << "Podaj wybór: " << endl;
		cin >> selection;
		if(selection == 1) {
			zadanie2();
		}
		if(selection == 2) {
			zadanie3();
		}
	}while(selection != 5);
	return 0;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int *&array, int size, int mode){
	for(int i = size - 1; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			if(mode == 0 && array[j] > array[j + 1] || mode != 0 && array[j] < array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void selectionSort(int *&array, int size, int mode) {
	for(int i = 0; i < size - 1; i++) {
		int minElementIndex = i;
		for(int j = i + 1; j < size; j++) {
			if(mode == 0 && array[j] < array[minElementIndex] || mode != 0 && array[j] > array[minElementIndex]) {
				minElementIndex = j;
			}
		}
		swap(array[i], array[minElementIndex]);
	}
}

void zadanie2() {
	int size, min, max, mode;
	int *array = nullptr;
	cout << "Sortowanie bąbelkowe" << endl;
	cout << "Podaj rozmiar tablicy: ";
	cin >> size;
	cout << "Podaj dolny zakres możliwych wartości, którymi wypełnić tablicę: ";
	cin >> min;
	cout << "Podaj górny zakres możliwych wartości, którymi wypełnić tablicę: ";
	cin >> max;
	cout << "Wybierz kolejność sortowania. Wpisz 0 dla sortowania rosnącego lub dowolną inną liczbę dla sortowania malejącego" << endl;
	cin >> mode;

	allocateMemory1D(array, size);
	randomFill1DArray(array, size, min, max);

	cout << "Tablica przed posortowaniem: " << endl;
	print1D(array, size);
	cout << "Tablica po posortowaniu: " << endl;
	bubbleSort(array, size, mode);
	print1D(array, size);

	deleteArray1D(array);
}

void zadanie3() {
	int size, min, max, mode;
	int *array = nullptr;
	cout << "Sortowanie przez wybór" << endl;
	cout << "Podaj rozmiar tablicy: ";
	cin >> size;
	cout << "Podaj dolny zakres możliwych wartości, którymi wypełnić tablicę: ";
	cin >> min;
	cout << "Podaj górny zakres możliwych wartości, którymi wypełnić tablicę: ";
	cin >> max;
	cout << "Wybierz kolejność sortowania. Wpisz 0 dla sortowania rosnącego lub dowolną inną liczbę dla sortowania malejącego" << endl;
	cin >> mode;

	allocateMemory1D(array, size);
	randomFill1DArray(array, size, min, max);

	cout << "Tablica przed posortowaniem: " << endl;
	print1D(array, size);
	cout << "Tablica po posortowaniu: " << endl;
	selectionSort(array, size, mode);
	print1D(array, size);

	deleteArray1D(array);
}

void allocateMemory1D(int *&array, int size) {
	array = new int[size];
}

void randomFill1DArray(int *&array, int size, int min, int max) {
	for(int i = 0; i < size; i++) {
		int randomNumber = rand() % (max - min + 1) + min;
		array[i] = randomNumber;
	}
}

void deleteArray1D(int *&array) {
	delete []array;
}

void print1D(int *&array, int size) {
	cout << "[";

	for(int i = 0; i < size; i++) {
		cout << array[i];
		if(i < size - 1) {
			cout << ", ";
		}
	}

	cout << "]" << endl;
}