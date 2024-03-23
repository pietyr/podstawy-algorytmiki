#include <iostream>

using namespace std;

/**
 * Function sorts 1D array ascending/descending (depending on the mode),
 * using bubble sort algorithm
 * @param array array to sort
 * @param size size of the array
 * @param mode 0 (default) - ascending, 1 - descending
 */
void bubbleSort(int *array, int size, int mode = 0);

/**
 * Function sorts 1D array ascending/descending (depending on the mode),
 * using selection sort algorithm
 * @param array array to sort
 * @param size size of the array
 * @param mode 0 (default) - ascending, 1 - descending
 */
void selectionSort(int *array, int size, int mode = 0);

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
void bubbleSort2D(int **array, int sizeX, int sizeY, int mode = 0, int column);

int main()
{
    return 0;
}
