#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include "StappedArray.h"



int main()
{
	int** array1 = 0;
	int rows = 0;
	int* columnsCount = 0;
	int type = 0;
	bool flug1 = 0, runing = 1;

	while (runing)
	{
		printf_s("\
0 - Exit\n\
1 - Manual array filling\n\
2 - Text file array filling\n\
3 - Bin file array filling\n");
		printf_s("Enter what you want to do: ");
		scanf_s("%d", &type);
		switch (type)
		{
		case 0:
			if (flug1)
				runing = 0;
			else
				printf_s("Need to filling Array!\n");
			break;

		case 1:
			GetRows(&rows);
			MainMalloc(&array1, &columnsCount, rows);
			ManualArrayFilling(array1, columnsCount, rows);
			flug1 = 1;
			break;
		
		case 2:
			TextFileArrayFilling(&array1, &columnsCount, &rows);
			flug1 = 1;
			break;

		case 3:
			BinFileArrayFilling(&array1, &columnsCount, &rows);
			flug1 = 1;
			break;

		default:
			printf_s("Invalid type! Try again.\n");
		}
	}

	runing = 1;
	while (runing)
	{
		printf_s("\
0 - Exit\n\
1 - Print array\n\
2 - Text file array save\n\
3 - Bin file array save\n");
		printf_s("Enter what you want to do: ");
		scanf_s("%d", &type);
		switch (type)
		{
		case 0:
			runing = 0;
			break;

		case 1:
			ArrayPrinting(array1, columnsCount, rows);
			break;

		case 2:
			ArraySaveTextFile(array1, columnsCount, rows);
			break;

		case 3:
			ArraySaveBinFile(array1, columnsCount, rows);
			break;

		default:
			printf_s("Invalid type! Try again.\n");
		}
	};

	MemoryFree(array1, columnsCount, rows);

	return 0;
}