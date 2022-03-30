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
