#include <iostream>
#include <fstream>
#include <cmath>

int log2n;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void selectionSort(int tab[], int n)
{
	int min_val;

	for (int i = 0; i < n - 1; i++)
	{
		min_val = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tab[j] < tab[min_val])
				min_val = j;
		}
		swap(&tab[min_val], &tab[i]);
	}
}

void heapify(int tab[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && tab[l] > tab[largest])
		largest = l;

	if (r < n && tab[r] > tab[largest])
		largest = r;

	if (largest != i)
	{
		std::swap(tab[i], tab[largest]);
		heapify(tab, n, largest);
	}
}

void heapSort(int tab[], int n)
{
	if (n <= 4)
	{
		selectionSort(tab, n);
	}
	else
	{
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(tab, n, i);

		for (int i = n - 1; i >= 0; i--)
		{
			std::swap(tab[0], tab[i]);
			heapify(tab, i, 0);
		}
	}
}

int partition(int tab[], int low, int high)
{
	int pivot = tab[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (tab[j] <= pivot)
		{
			i++;
			swap(&tab[i], &tab[j]);
		}
	}
	swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void quickSort(int tab[], int low, int high, int zagniezdzenie)
{
	if (low < high)
	{
		int pi = partition(tab, low, high);
		if (zagniezdzenie >= log2n)
		{
			int n = (high - low) + 1;
			int *temp = new int[n];

			for (int i = 0; i <= n; i++)
				temp[i] = tab[low + i];

			heapSort(temp, n);

			for (int i = 0; i <= n; i++)
				tab[low + i] = temp[i];
		}
		else
		{
			zagniezdzenie++;
			quickSort(tab, low, pi - 1, zagniezdzenie);
			quickSort(tab, pi + 1, high, zagniezdzenie);
		}
	}
}

int main()
{
	std::string sciezka, linia;
	std::fstream wejscie, wyjscie;
	int ilosc = 0;
	int i = 0;
    int zagniezdzenie = 0;

	std::cout << "Sciezka do pliku, ktory chcesz sortowac: ";
	std::cin >> sciezka;

	// OTWARCIE PLIKU, ZLICZENIE ILOSCI WIERSZY, ZAMKNIECIE PLIKU
	wejscie.open(sciezka, std::ios::in);

	while (std::getline(wejscie, linia))
		ilosc++;

	wejscie.close();

	// DEKLARACJA TABLICY(O WIELKOSCI ROWNEJ ILOSCI WIERSZY) I PRZYPISSANIE POZIOMU
	int *tab = new int[ilosc];
	log2n = log2(ilosc);

	// OTWARCIE PLIKU, POBRANIE WARTOSCI WIERSZA DO TABLICY, ZAMKNIECIE PLIKU
	wejscie.open(sciezka, std::ios::in);

	while (std::getline(wejscie, linia))
	{
		tab[i] = atoi(linia.c_str());
		i++;
	}

	wejscie.close();

	// SORTOWANIE
	quickSort(tab, 0, ilosc - 1, zagniezdzenie);

	//WYPISANIE POSORTOWANEJ TABLICY DO PLIKU
	wyjscie.open(sciezka + ".out", std::ios::out);

	for (int i = 0; i < ilosc; i++)
	{
		wyjscie << tab[i] << std::endl;
	}

	wyjscie.close();

	// ZWOLNIENIE PAMIECI
	delete[] tab;

	return 0;
}
