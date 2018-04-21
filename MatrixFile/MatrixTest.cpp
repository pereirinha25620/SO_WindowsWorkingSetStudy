#include "MatrixFile.h"

MatrixFile createTestMatrix(DWORD lines, DWORD columns) {
	MatrixHeader mh = { lines, columns };
	PMatrixValue values = (PMatrixValue)malloc(sizeof(MatrixValue) * lines * columns);



}
