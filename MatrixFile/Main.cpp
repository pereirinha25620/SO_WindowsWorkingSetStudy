#include "MatrixFile.h"
#include "MatrixTest.h"
#include <stdio.h>

#define MATRIX_WIDTH	2
#define MATRIX_HEIGHT	2

int main() {
	MatrixFile mFile = createTestMatrix(2, 2);
	DWORD result = -1;

	for (int l = 0; l < MATRIX_WIDTH + 1; l++ )
		for (int c = 0; c < MATRIX_HEIGHT + 1; c++) {
			if (GetMatrixValue(&mFile, l, c, &result))
				printf("Matrix value at (%d,%d) = %d\n", l, c, result);
			else
				printf("Value (%d, %d) out of Matrix\n", l, c);
		}

	getchar();
	return 0;
}