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

// zwolnienie pamięci w tablicy jednowymiarowej
void usunTablice1D(int *&tab);

// zwolnienie pamięci w tablicy dwuwymiarowe
void usunTablice2D(int **&tab, int w);

// wyświetlenie zawartości tablicy jednowymiarowej
void wyswietl1D(int* tab, int n);

//wyświetlenie zawartości tablicy dwuwymiarowej
void wyswietl2D(int** tab, int w, int k);

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