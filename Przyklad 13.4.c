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