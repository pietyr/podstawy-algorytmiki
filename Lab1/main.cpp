#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

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


/**
 * Function gets size of the array and fill it with random numbers from <0-9> range
 * Function prints how many times each value had appeared
 */
void countArrayItems();

/**
 * Function returns digits sum of a natural number in a given number base
 * @param number 
 * @param base
 * @return 
 */
int sumOfDigits(int number, int base);

/**
 * Function read size of the 2D array and <min, max> range to generate random numbers.
 * Function fills table with random numbers.
 * Function then prints highest number in array and sum of its digits
 */
void maxElement();

/**
 * Function read size of the square 2D array
 * Function fills table with random numbers from <7; 122> range
 * Function then calculates:
 * The average of the elements above the main diagonal
 * The average of the elements below the main diagonal
 */
void average();

int main() {
	int menu_selection = -1;

	cout << "Laboratorium 1" << endl;

	while(menu_selection != 5) {
		cout << "==================== MENU ====================" << endl;
		cout << "1. Minimalny element (Zadanie 1.2)" << endl;
		cout << "2. Zliczanie elementów w tablicy (Zadanie 1.3)" << endl;
		cout << "3. Maksymalny element (Zadanie 1.4)" << endl;
		cout << "4. Średnia (Zadanie 1.5)" << endl;
		cout << "5. Wyjście z programu" << endl;
		cout << "==================== MENU ====================" << endl;
		cout << "Wybierz program (1-5): ";
		cin >> menu_selection;

		switch (menu_selection) {
		case 1:
			minElement();
			break;
		case 2:
			countArrayItems();
			break;
		case 3:
			maxElement();
			break;
		case 4:
			average();
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
	cout << "===========================================" << endl;
	cout << "[";

	for(int i = 0; i < sizeX; i++) {
		cout << "    ";
		print1D(array[i], sizeY);
		if(i < sizeX - 1) {
			cout << ",";
		}
	}

	cout << "]" << endl;
	cout << "===========================================" << endl;
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

void countArrayItems(){
	int size;
	int min = 0;
	int max = 9;
	int *array;
	int *numbers;

	cout << "Podaj rozmiar tablicy: ";
	cin >> size;

	allocateMemory1D(array, size);
	randomFill1DArray(array, size, min, max);

	allocateMemory1D(numbers, 10);

	for(int i = 0; i < 10; i++){
		numbers[i] = 0;
 	}

	for(int i = 0; i < size; i++){
		numbers[array[i]]++;
	}

	for(int i = 0; i < 10; i++){
		cout << "Ilość wystąpień liczby " << i << ": " << numbers[i] << endl;
	}

	deleteArray1D(array);
	deleteArray1D(numbers);
}

int sumOfDigits(int number, int base){
	int sum = 0;

	for(int j = number,  i = 0; j >= 1; j /= base, i++){
		sum += ((number % (int)pow(base, i + 1) - number % (int)pow(base, i)) / (int)pow(base, i));
	}

	return sum;
}

void maxElement(){
	int sizeX, sizeY, min, max;
	int **array;

	cout << "Podaj rozmiar X tablicy: ";
	cin >> sizeX;
	cout << "Podaj rozmiar Y tablicy: ";
	cin >> sizeY;
	cout << "Podaj dolny zakres wartości tablicy: ";
	cin >> min;
	cout << "Podaj górny zakres wartości tablicy: ";
	cin >> max;

	allocateMemory2D(array, sizeX, sizeY);
	randomFill2DArray(array, sizeX, sizeY, min, max);

	int highest = array[0][0];
	for(int i = 0; i < sizeX; i++) {
		for(int j = 0; j < sizeY; j++){
			if(array[i][j] > highest) {
				highest = array[i][j];
			}
		}
	}

	int sum = sumOfDigits(highest, 10);

	cout << "Największa wartość tablicy: " << highest << endl;
	cout << "Suma cyfr tej liczby: " << sum << endl;

	deleteArray2D(array, sizeX);
}

void average(){
	int size;
	int **array;
	int min = 7;
	int max = 122;

	cout << "Podaj rozmiar tablicy: ";
	cin >> size;

	allocateMemory2D(array, size, size);
	randomFill2DArray(array, size, size, min, max);
	print2D(array, size, size);

	int aboveSum = 0;
	int belowSum = 0;
	int numberOfElements = (size * size - size) / 2;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(j > i){
				// Above
				aboveSum += array[i][j];
			}
			if(i > j){
				// Below
				belowSum += array[i][j];
			}
		}
	}

	float aboveAvg = (float)aboveSum / numberOfElements;
	float belowAvg = (float)belowSum / numberOfElements;

	deleteArray2D(array, size);

	cout << "Średnia elementów znajdujących się powyżej przekątnej: " << aboveAvg << endl;
	cout << "Średnia elementów znajdujących się poniżej przekątnej: " << belowAvg << endl;
}
