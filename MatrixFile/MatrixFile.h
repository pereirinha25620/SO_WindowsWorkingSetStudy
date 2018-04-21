#include <windows.h>

#pragma once

#define MATRIX_OFF	4
#define COORD_IS_OUT_OF_BOUNDS(l, c)	(l < 0 || l > (pMatrixFile->lines - 1) || c < 0 || c > (pMatrixFile->columns - 1))

typedef struct _MatrixHeader {
	
} MatrixHeader, *PMatrixHeader;

typedef struct _MatrixFile {
	USHORT lines;
	USHORT columns;
	DWORD *values;
} MatrixFile, *PMatrixFile;

BOOL GetMatrixValue(void *mFile, DWORD line, DWORD column, DWORD *value);

