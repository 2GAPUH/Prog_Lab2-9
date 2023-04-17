#pragma once

void GetRows(int* rows);
void MainMalloc(int*** array1, int** columnsCount, int rows);
void ManualArrayFilling(int** array1, int* columnsCount, int rows);
void ArrayPrinting(int** array1, int* columnsCount, int rows);
void MemoryFree(int** array1, int* columnsCount, int rows);
void GetFileName(char fileName[]);
void ArraySaveTextFile(int** array1, int* columnsCount, int rows);
void TextFileArrayFilling(int*** array1, int** columnsCount, int* rows);
void ArraySaveBinFile(int** array1, int* columnsCount, int rows);
void BinFileArrayFilling(int*** array1, int** columnsCount, int* rows);