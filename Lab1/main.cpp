#include <iostream>

// Zadanie 1.1 Funkcje typu void
// Zadanie 1.2 Minimalny element
// Zadanie 1.3 Zliczanie elementów tablicy
// Zadanie 1.4 Maksymalny element
// Zadanie 1.5 Średnia

//przydzielenie pamięci w tablicy  jednowymiarowej, n – rozmiar tablicy
void przydzielPamiec1D(int *&tab, int n);

// przydzielenie pamięci w tablicy dwuwymiarowej, w, k - wymiary tablicy
void przydzielPamiec2D(int **&tab, int w, int k);

// wypełnienie tablicy jednowymiarowej wygenerowanymi liczbami z zakresu <a,b>
void wypelnijTablice1D(int *tab, int n, int a, int b);

// wypełnienie tablicy dwuwymiarowej wygenerowanymi liczbami z zakresu <a,b>
void wypelnijTablice2D(int **tab, int w, int k, int a, int b);

// zwolnienie pamięci w tablicy jednowymiarowej
void usunTablice1D(int *&tab);

// zwolnienie pamięci w tablicy dwuwymiarowe
void usunTablice2D(int **&tab, int w);

// wyświetlenie zawartości tablicy jednowymiarowej
void wyswietl1D(int* tab, int n);

//wyświetlenie zawartości tablicy dwuwymiarowej
void wyswietl2D(int** tab, int w, int k);

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
