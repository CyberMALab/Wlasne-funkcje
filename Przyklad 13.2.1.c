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
	
	wynik = dodaj5(&licz);
	
	printf("licz = %d ; wynik = %d", licz, wynik);
	return 0;
}