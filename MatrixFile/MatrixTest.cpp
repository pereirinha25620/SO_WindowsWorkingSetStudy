#include "MatrixFile.h"

MatrixFile createTestMatrix(DWORD lines, DWORD columns) {
	DWORD mDim = lines * columns;

	DWORD *values = (DWORD *)malloc(sizeof(DWORD) * mDim);

	for (DWORD i = 0; i < mDim; i++) *(values + i) = i;
	
	MatrixFile matrix = { lines, columns, values };

	return matrix;
}


