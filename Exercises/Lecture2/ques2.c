#include <stdio.h>
#include <windows.h>
#include <tchar.h>

void _tmain(int argc, TCHAR* argv[]) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

		/* Allocate memory */
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));

        if (argc != 2) {
            printf("Usage: %s [cmdline]\n", argv[0]);
            return;
        }

		/* Create child process */ 
		if (!CreateProcess(NULL, /* No module name (use command line) */
			argv[1], /* Command line */
			NULL, /* don't inherit process handle */
			NULL, /* don't inherit thread handle */
			FALSE,	/* disable handle inheritance */ 
			0,	/* no creation flags */
			NULL,	/* use parent's environment block */
			NULL,	/* use parent's existing directory */
			&si,    /* Pointer to STARTUPINFO structure */
			&pi)    /* Pointer to PROCESS_INFORMATION structure */
            ){

			printf("Create Process Failed (%d).\n", GetLastError());
			return;
		}

		/* Parent will wait for the child to complete */
		WaitForSingleObject(pi.hProcess, INFINITE);
		printf("Child Complete");

		/* Close handles */
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
}