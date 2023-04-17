#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include <string.h>


void GetRows(int* rows)
{
	do {
		printf_s("Enter rows: ");
		scanf_s("%d", rows);
		if (*rows <= 0)
			printf_s("Invalid value! Try again.\n");
		else
			break;
	} while (true);
}

void MainMalloc(int*** array1, int** columnsCount, int rows)
{
	*array1 = (int**)malloc(sizeof(int*) * rows);
	if (*array1 == 0)
	{
		printf_s("Can't add memmory!\n");
		exit(1);
	}

	*columnsCount = (int*)malloc(sizeof(int) * rows);
	if (*columnsCount == 0)
	{
		printf_s("Can't add memmory!\n");
		exit(1);
	}
}

void ManualArrayFilling(int** array1, int* columnsCount, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		while (true)
		{
			printf_s("Enter count of columns in %d line: ", i + 1);
			scanf_s("%d", &columnsCount[i]);
			if (columnsCount[i] <= 0)
				printf_s("Invalid value!\n");
			else
				break;
		}
		array1[i] = (int*)malloc(sizeof(int) * columnsCount[i]);
		if (array1[i] == 0)
		{
			printf_s("Can't add memmory!\n");
			exit(1);
		}
		for (int j = 0; j < columnsCount[i]; j++)
		{
			printf_s("Enter array[%d][%d]: ", i + 1, j + 1);
			scanf_s("%d", &array1[i][j]);
		}
	}
}

void ArrayPrinting(int** array1, int* columnsCount, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columnsCount[i]; j++)
			printf_s("%5d\t", array1[i][j]);
		printf_s("\n");
	}
}

void MemoryFree(int** array1, int* columnsCount, int rows)
{
	for (int i = 0; i < rows; i++)
		free(array1[i]);
	free(array1);
	free(columnsCount);
}

void GetFileName(char fileName[])
{
	printf_s("Enter file name('file.txt'): ");
	while (getchar() != '\n');
	gets_s(fileName, 20);
}

void ArraySaveTextFile(int** array1, int* columnsCount, int rows)
{
	FILE* f;
	char fileName[20];

	GetFileName(fileName);
	if (fopen_s(&f, fileName, "w") != 0)
	{
		printf_s("Error opening file.\n");
		return;
	}

	fprintf_s(f, "%d\n", rows);

	for (int i = 0; i < rows; i++)
	{
		fprintf_s(f, "%d ", columnsCount[i]);
		for (int j = 0; j < columnsCount[i]; j++)
			fprintf_s(f, "%d ", array1[i][j]);
		fprintf_s(f, "\n");
	}

	fclose(f);
}

void TextFileArrayFilling(int*** array1, int** columnsCount, int* rows)
{
	FILE* f;
	char fileName[20];

	GetFileName(fileName);
	if (fopen_s(&f, fileName, "r") != 0)
	{
		printf_s("Error opening file.\n");
		return;
	}

	fscanf_s(f, "%d", rows);

	MainMalloc(array1, columnsCount, *rows);

	for (int i = 0; i < *rows; i++)
	{
		fscanf_s(f, "%d", &(*columnsCount)[i]);
		(*array1)[i] = (int*)malloc(sizeof(int) * (*columnsCount)[i]);
		if ((*array1)[i] == 0)
		{
			printf_s("Can't add memmory!\n");
			exit(1);
		}
		for (int j = 0; j < (*columnsCount)[i]; j++)
		{
			fscanf_s(f, "%d", &(*array1)[i][j]);
		}
	}

	fclose(f);

	printf_s("Succesful filling.\n");
}

void ArraySaveBinFile(int** array1, int* columnsCount, int rows)
{
	FILE* f;
	char fileName[20];

	GetFileName(fileName);
	if (fopen_s(&f, fileName, "wb") != 0)
	{
		printf_s("Error opening file.\n");
		return;
	}

	fwrite(&rows, sizeof(int), 1, f);

	for (int i = 0; i < rows; i++)
	{
		fwrite(&columnsCount[i], sizeof(int), 1, f);

		fwrite(array1[i], sizeof(int), columnsCount[i], f);
	}

	fclose(f);
}

void BinFileArrayFilling(int*** array1, int** columnsCount, int* rows)
{
	FILE* f;
	char fileName[20];

	GetFileName(fileName);
	if (fopen_s(&f, fileName, "rb") != 0)
	{
		printf_s("Error opening file.\n");
		return;
	}

	fread(rows, sizeof(int), 1, f);

	MainMalloc(array1, columnsCount, *rows);

	for (int i = 0; i < *rows; i++)
	{
		fread(&(*columnsCount)[i], sizeof(int), 1, f);
		(*array1)[i] = (int*)malloc(sizeof(int) * (*columnsCount)[i]);
		if ((*array1)[i] == 0)
		{
			printf_s("Can't add memmory!\n");
			exit(1);
		}

		fread((*array1)[i], sizeof(int), (*columnsCount)[i], f);
	}

	fclose(f);

	printf_s("Succesful filling.\n");
}