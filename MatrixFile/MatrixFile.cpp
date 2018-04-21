#include "MatrixFile.h"

BOOL GetMatrixValue(void *mFile, DWORD line, DWORD column, DWORD *value) {
	PMatrixFile pMatrixFile = (PMatrixFile)mFile;
	
	if (COORD_IS_OUT_OF_BOUNDS(line, column)) return FALSE;

	DWORD *pValues = pMatrixFile->values;

	*value = *(pValues + line * pMatrixFile->columns + column);

	return TRUE;
}