#include <Windows.h>
#include <Psapi.h>
#include <stdio.h>

#define SUCCESS		0
#define PROCESS_ID	1676

VOID leaks_analyser(DWORD pid, DWORD threshold_in_bytes);

/*
 * To read: http://blogs.microsoft.co.il/sasha/2016/01/05/windows-process-memory-usage-demystified/
 */

int main() {
	leaks_analyser(11276, 10000);
	
	return SUCCESS;
}

VOID leaks_analyser(DWORD pid, DWORD threshold_in_bytes) {
	/* Get a handle to the process */
	HANDLE hProc = OpenProcess(
		PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
		FALSE,
		pid
	);
	if (hProc == NULL) return;

	SYSTEM_INFO pSi;
	GetSystemInfo(&pSi);

	DWORD pageSz = pSi.dwPageSize;
	printf("*** System page size: %u bytes ***\n", pageSz);

	while (true) {
		PSAPI_WORKING_SET_INFORMATION procInfo;
		QueryWorkingSet(hProc, &procInfo, sizeof(procInfo));
		DWORD procWorkingSetSize = procInfo.NumberOfEntries * pageSz;
		if (procWorkingSetSize > threshold_in_bytes)
			printf("Leak: %d: %d\n", pid, procWorkingSetSize);
		Sleep(5000);
	}
}