# Własne funkcje.

Rozdział ten jest rozszerzeniem rozdziału 7. Rozszerzone zostanie tutaj pojęcie funkcji o przekazywanie parametrów przez wartość, referencję i wskaźnik. 

## Przekazywanie argumentu funkcji przez wartość

Przekazywanie argumentu przez wartość jest nam znane z rozdziału 7. Tam pisaliśmy funkcje, które przekazywały wartość jako parametr funkcji. Przekazanie parametru przez wartość definiuje się poprzez deklarację funkcji wraz z argumentami – zmiennymi. Taka deklaracja powoduje, że w momencie wywołania funkcji, skopiuje ona wartość podaną jako parametr do argumentu liczba, więc wartość zmiennej podanej jako parametr nie ulegnie zmianie.

*Przykład (13.1) tworzenie funkcji z argumentami przekazywanymi przez wartość.*

```
#include <stdio.h>
#include <stdlib.h>

int dodaj5(int liczba)
{
	liczba += 5;
	return liczba;
}

int main() 
{
	int licz = 5;
	int wynik;
	
	wynik = dodaj5(licz);
	
	printf("licz = %d ; wynik = %d", licz, wynik);
	return 0;
}
```

*Wynik działania programu:*

>licz = 5 ; wynik = 10

## Przekazywanie argumentu funkcji przez wskaźnik

Tytuł podrozdziału jest w tym momencie troszę przkłamany, bo jest to formalnie przekazanie wskaźnika. Jak zostało to wyjaśnione w rozdziale 12 wskaźnik jest normalną zmienną, tylko specyficznego typu. Kiedy takiego wskaźnika użyjemy jako parametr funkcji, to będziemy mogli dostać się do wartości, która kryje sie pod zawartym w wartości wskaźnika adresie. Za pomocą operatora dereferencji będziemy mogli więc wpływać na wartość zmiennej która znajduje się poza funkcją.

Aby zadeklarować funkcję z parametrem – wskaźnikiem, należy zadeklarować parametr jako wskaźnik.

*Przykład (13.2.1) tworzenie funkcji z argumentami przekazywanymi przez wskaźnik.*

```
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
```

*Przykład (13.2.2) tworzenie funkcji z argumentami przekazywanymi przez wskaźnik.*

```
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

```

*Wynik działania programów:*

>licz = 10 ; wynik = 10

## Przekazywanie tablicy jako argument funkcji

Przekazywanie tablicy w argumecie funkcji jest niczym innym jak przekazaniem wskaźnika na pierwszy element tablicy. Mając już wiedzę o wskaźnikach łatwo jest już wytłumaczyć dlaczego tablica przekazywana do funkcji zmieniała swoją zawartość po wykonaniu kodu funkcji, kiedy parametry przekazywane w formie innej niż tablica nie ulegały zmianie. Powodem jest omawiana już wyżej dereferancja wskaźnika, czyli zmiana oryginalnej wartości spod danego adresu. 

*Przykład (13.3) funkcja obsługująca tablicę za pomocą arytmetyki wskaźników*

```
#include <stdio.h>
#include <stdlib.h>

void printArrayOfInt(int* array, int size)
{
	int* ptrArray;
	for(ptrArray = array; ptrArray-array < size; ptrArray++)
	{
		printf("%d ", *ptrArray);
	}

}

int main()
{
	int array[6] = {1,2,3,4,5,6};
	printArrayOfInt(array,6);
	return 0;
}

```

*Wynik działania programu*

>1 2 3 4 5 6

Sprawa jest bardziej skomplikowana jeśli chodzi o tablicę wielowymiarową. Taką tutaj przekazując tablicę przez wskaźnik należy skorzystać z własności, że tablica jest spójnym blokiem w pamięci i operować na niej za pomocą wskaźnika do pojedynczego elementu.

*Przykład (13.4) funkcja obsługująca tablicę wielowymiarową za pomocą arytmetyki wskaźników*

```
#include <stdio.h>
#include <stdlib.h>

void printArray2DimOfInt(int* array, int size_x, int size_y)
{
	int* ptrArray;
	int lastElement = size_x*size_y-1;
	int i;

    for(ptrArray=array,i=0; ptrArray <= &array[lastElement]; ptrArray++, i++)
	{
		if(i%size_y==0)
		{
			printf("\n");
		}
		printf(" %d", *ptrArray);
	}


}

int main()
{
	int array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	printArray2DimOfInt(array,3,3);
	return 0;
}
```

*Wynik działania programu*

>1 2 3
>
>4 5 6
>
>7 8 9

W praktyce jednak, statycznych tablic – szczególnie wielowymiarowych nie używa się. Zastępują je tablice dynamicze, oraz funkcje obsługi takich tablic. Funkcje takie opierają się na zasadach przekazywania argumentów funkcji przez wskaźnik. Jest to opisane w kolejnym rozdziale.

## Przekazywanie argumentu funkcji przez referencję (C++)

Taka deklaracja nie jest możliwa w ANSI C, jednak jej istnienie jest istotne w kontekście początków nauki o programowaniu. Kod z przykładów tego podrozdziału można skompilować przy użyciu kompilatora C++.

Przekazywanie argumentu przez referencję, jest podobne w działaniu jak przekazanie parametru funkcji przez wskaźnik. Taka funkcja, już może wpłynąć na wartość zmiennej którą do niej przekazujemy. Argumenty funkcji przekazywane przez referencje deklaruje się poprzez podanie zmiennej z operatorem referencji. Taka deklaracja powoduje, że w momencie przekazywania argumentu, zmienna parametru liczba stanie się jednoznaczna z argumentem. Każda wykonana operacja na zmiennej wewnątrz funkcji, wpłynie na wartość zmiennej podanej podczas jej wywoływania. 

*Przykład (13.5) tworzenie funkcji z argumentami przekazywanymi przez referencję*

```
#include <stdio.h>
#include <stdlib.h>

int dodaj5(int &liczba)  
{
	liczba += 5;
	return liczba;
}

int main() 
{
	int licz = 5;
	int wynik;
	
	wynik = dodaj5(licz);
	
	printf("licz = %d ; wynik = %d", licz, wynik);
	return 0;
}
```

*Wynik działania programu:*

>licz = 10 ; wynik = 10

## Zadania do samodzielnego wykonania:

1. Napisz funkcję, która zwróci adres większej liczby z pośród dwóch liczb przekazywanych przez wskaźniki
1. Napisz funkcję, która porównuje dwie liczby, następnie mniejszą z nich nadpisuje sumą obu liczb. Zmienne muszą być zadeklarowane i zainicjalizowane przed wywołaniem tej funkcji. Wykorzystaj wskaźniki jako parametry wejściowe, funkcja nie może zwracać wartości.
1. Wykonaj następujące kroki:
   1. zadeklaruj i zainicjalizuj tablice o rozmiarze 10 elementów oraz wskaźnik na tą tablicę
   1. napisz i wywołaj funkcję wyświetlania tablicy
   1. napisz i wywołaj funkcję służącą do pomownego wprowadzenia elementów tablicy
   1. napisz i wywołaj funkcje zliczające: sumę elenentów, średnią, wartość największą, wartość najmniejszą w tablicy
   1. zaimplementuj rozwiązanie typu menu wyboru zawierające wybór powyższych funkcjonalności.



***
[Poprzednia część](https://github.com/CyberMALab/Wprowadzenie-do-wskaznikow.git) | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Comming-Soon.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory
