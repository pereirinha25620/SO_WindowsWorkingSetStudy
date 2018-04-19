#include <Windows.h>
#include <Psapi.h>
#include <stdio.h>

#define SUCCESS		0
#define ERROR		1
#define PROCESS_ID	9052

void EndProgram();

/*
 * To read: http://blogs.microsoft.co.il/sasha/2016/01/05/windows-process-memory-usage-demystified/
 */

int main(int argc, char **argv) {
	/* Convert call argument to unsigned int PID */
	//UINT16 ProcessID = atoi(argv[1]);

	/* Get a handle to the process */
	HANDLE hProcess = OpenProcess(
		PROCESS_ALL_ACCESS,
		FALSE,
		PROCESS_ID
	);

	/* Initialize an object that will hold information about the process:
	 * typedef struct _PSAPI_WORKING_SET_INFORMATION {
	 *		ULONG_PTR               NumberOfEntries;
	 *		PSAPI_WORKING_SET_BLOCK WorkingSetInfo[1];
	 *	} 
	 */
	DWORD BufferSize = sizeof(PSAPI_WORKING_SET_INFORMATION);
	PPSAPI_WORKING_SET_INFORMATION pWorkingSetInfo =
		(PPSAPI_WORKING_SET_INFORMATION)malloc(BufferSize);

	memset(pWorkingSetInfo, 0, BufferSize);

	/* Get the WorkingSetInformation */
	while (QueryWorkingSet(hProcess, pWorkingSetInfo, BufferSize) == 0) {
		printf("Bad length\n");
		BufferSize = (pWorkingSetInfo->NumberOfEntries - 1) * sizeof(PSAPI_WORKING_SET_BLOCK) + sizeof(PSAPI_WORKING_SET_INFORMATION);
		realloc(pWorkingSetInfo, BufferSize);
	}

	EndProgram();
	return SUCCESS;
}

void EndProgram() {
	printf("Press any key to finish...");
	getchar();
}