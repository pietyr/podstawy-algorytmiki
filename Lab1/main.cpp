#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// Zadanie 1.1 Funkcje typu void
// Zadanie 1.2 Minimalny element
// Zadanie 1.3 Zliczanie elementów tablicy
// Zadanie 1.4 Maksymalny element
// Zadanie 1.5 Średnia

/**
 * Allocate memory for one dimension array
 * @param array Reference to the array
 * @param size Size of the array
 */
void allocateMemory1D(int *&array, int size);

/**
 * Allocate memory for two dimension array
 * @param array Reference to the array
 * @param sizeX Size of the array in first dimension
 * @param sizeY Size of the array in second dimension (size of the subarrays)
 */
void allocateMemory2D(int **&array, int sizeX, int sizeY);

/**
 * Fill the one dimension array with numbers from <a,b> range
 * @param array Reference to target array
 * @param size Size of the target array
 * @param min Lowest fill value (including)
 * @param max Highest fill value (including)
 */
void randomFill1DArray(int *array, int size, int min, int max);

/**
 * Fill the two dimension array with numbers from <a,b> range
 * @param array Reference to target array
 * @param sizeX Size of the array in first dimension
 * @param sizeY Size of the array in second dimension (size of the subarrays)
 * @param min Lowest fill value (including)
 * @param max Highest fill value (including)
 */
void randomFill2DArray(int **array, int sizeX, int sizeY, int min, int max);

/**
 * Free memory of the one dimension array
 * @param array Target array
 */
void deleteArray1D(int *&array);

/**
 * Free memory of the two dimension array
 * @param array Target array
 * @param sizeX Size of the array in first dimension
 */
void deleteArray2D(int **&array, int sizeX);

/**
 * Print content of the one dimension array
 * @param array Target array
 * @param size Size of the array
 */
void print1D(int* array, int size);

/**
 * Print content of the two dimension array
 * @param array Target array
 * @param sizeX Size of the array in first dimension
 * @param sizeY Size of the array in second dimension (size of the subarrays)
 */
void print2D(int** array, int sizeX, int sizeY);

/**
 * Function read size of the 1D array and <min, max> range to generate random numbers.
 * Function fills table with random numbers.
 * Function then prints lowest number in array and checks if that number is prime
 */
void minElement();

/**
 * Returns boolean indicating if number is prime
 * @param number Checked number
 * @return True if number is prime
 */
bool isPrime(int number);

int main() {
	int menu_selection = -1;

	cout << "Laboratorium 1" << endl;

	while(menu_selection != 5) {
		cout << "==================== MENU ====================" << endl;
		cout << "1. Minimalny element (Zadanie 1.2)" << endl;
		cout << "2. Zliczanie elementów w tablicy (Zadanie 1.3)" << endl;
		cout << "3. Zliczanie elementów w tablicy (Zadanie 1.4)" << endl;
		cout << "4. Zliczanie elementów w tablicy (Zadanie 1.5)" << endl;
		cout << "5. Wyjście z programu" << endl;
		cout << "==================== MENU ====================" << endl;
		cout << "Wybierz program (1-5): ";
		cin >> menu_selection;

		switch (menu_selection) {
		case 1:
			minElement();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}
	return 0;
}


void allocateMemory1D(int *&array, int size) {
	array = new int[size];
}

void allocateMemory2D(int **&array, int sizeX, int sizeY) {
	array = new int*[sizeX];

	for(int i = 0; i < sizeX; i++) {
		allocateMemory1D(array[i], sizeY);
	}
}

void randomFill1DArray(int *array, int size, int min, int max) {
	srand(time(nullptr));

	for(int i = 0; i < size; i++) {
		int randomNumber = rand() % (max - min + 1) + min;
		array[i] = randomNumber;
	}
}

void randomFill2DArray(int **array, int sizeX, int sizeY, int min, int max) {
	for(int i = 0; i < sizeX; i++) {
		randomFill1DArray(array[i], sizeY, min, max);
	}
}

void deleteArray1D(int *&array) {
	delete []array;
}

void deleteArray2D(int **&array, int sizeX) {
	for(int i = 0; i < sizeX; i++) {
		deleteArray1D(array[i]);
	}
	delete []array;
}

void print1D(int* array, int size) {
	cout << "[";

	for(int i = 0; i < size; i++) {
		cout << array[i];
		if(i < size - 1) {
			cout << ", ";
		}
	}

	cout << "]" << endl;
}

void print2D(int** array, int sizeX, int sizeY) {
	cout << "[";

	for(int i = 0; i < sizeX; i++) {
		cout << "    ";
		print1D(array[i], sizeY);
		if(i < sizeX - 1) {
			cout << ",";
		}
	}

	cout << "]" << endl;
}

bool isPrime(int number) {
	if(number == 2 || number == 3) {
		return true;
	}

	if(number <= 1 || number % 2 == 0 || number % 3 == 0) {
		return false;
	}

	for(int i = 5; i * i <= number; i += 6) {
		if(number % i == 0 || number % (i + 2) == 0) {
			return false;
		}
	}

	return true;
}

void minElement() {
	/*
 * Function read size of the 1D array and <min, max> range to generate random numbers.
 * Function fills table with random numbers.
 * Function then prints lowest number in array and checks if that number is prime
 */
	int size, min, max;
	int *array;

	cout << "Podaj rozmiar tablicy: ";
	cin >> size;
	cout << "Podaj dolny zakres wartości tablicy: ";
	cin >> min;
	cout << "Podaj górny zakres wartości tablicy: ";
	cin >> max;

	allocateMemory1D(array, size);
	randomFill1DArray(array, size, min, max);

	int lowest = array[0];
	for(int i = 1; i < size; i++) {
		if(array[i] < lowest) {
			lowest = array[i];
		}
	}

	bool prime = isPrime(lowest);

	cout << "Najmniejsza wartość tablicy: " << lowest << endl;
	if(prime) {
		cout << "Liczba " << lowest << " jest liczbą pierwszą" << endl;
	}else {
		cout << "Liczba " << lowest << " nie jest liczbą pierwszą" << endl;
	}

	deleteArray1D(array);
}