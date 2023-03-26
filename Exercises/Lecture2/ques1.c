#include <stdio.h>
#include <windows.h>

int main(VOID) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

		/* Allocate memory */
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));

		/* Create child process */ 
		char programLocation[] = "C:\\Windows\\System32\\notepad.exe";

		if (!CreateProcess(NULL, /* use command line */
			programLocation, /* command */
			NULL, /* don't inherit process handle */
			NULL, /* don't inherit thread handle */
			FALSE,	/* disable handle inheritance */ 
			0,	/* no creation flags */
			NULL,	/* use parent's environment block */
			NULL,	/* use parent's existing directory */
			&si,
			&pi)) {

			fprintf(stderr, "Create Process Failed");
			return -1;
		}

		/* Parent will wait for the child to complete */
		WaitForSingleObject(pi.hProcess, INFINITE);
		printf("Child Complete");

		/* Close handles */
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
}