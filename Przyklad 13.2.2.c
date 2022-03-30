#include <stdio.h>
#include <stdlib.h>

int dodaj5(int* liczba)
{
	*liczba += 5;
	return *liczba;
}

int main() 
{
	int licz = 5;
	int wynik;
    int *wsk = &licz;
	
	wynik = dodaj5(wsk);
	
	printf("licz = %d ; wynik = %d", licz, wynik);
	return 0;
}
