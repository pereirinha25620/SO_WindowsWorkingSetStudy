#include "MatrixFile.h"

MatrixFile createTestMatrix(DWORD lines, DWORD columns) {
	MatrixHeader mh = { lines, columns };
	DWORD mDim = lines * columns;

	PMatrixValue values = (PMatrixValue)malloc(sizeof(MatrixValue) * mDim);

	INT32 *m = (INT32 *)values;

	for (INT32 i = 0; i < mDim; i++) *(m + i) = i;
	
	MatrixFile matrix = { mh, values };

	return matrix;
}


