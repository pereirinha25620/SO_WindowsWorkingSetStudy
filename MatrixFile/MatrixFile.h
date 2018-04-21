#include <windows.h>

#pragma once

typedef struct _MatrixHeader {
	USHORT lines;
	USHORT columns;
} MatrixHeader, *PMatrixHeader;

typedef struct _MAtrixValue {
	BYTE b0;
	BYTE b1;
	BYTE b2;
	BYTE b3;
} MatrixValue, *PMatrixValue;

typedef struct _MatrixFile {
	MatrixHeader header;
	PMatrixValue values;
} MatrixFile, *PMatrixFile;



