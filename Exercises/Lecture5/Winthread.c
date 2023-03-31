#include <windows.h>
#include <stdio.h>

DWORD Sum;

DWORD WINAPI Summation(LPVOID Param){
    DWORD Upper = *(DWORD*) Param;
    for (DWORD i = 0; i <= Upper; i++) {
        Sum += i;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    DWORD ThreadId;
    HANDLE ThreadHandle;
    int Param;

    if (argc != 2) {
        fprintf(stderr, "An integer parameter is required\n");
        return -1;
    }
    Param = atoi(argv[1]);
    if (Param < 0) {
        fprintf(stderr, "An integer >= 10 is required\n");
        return -1;
    }

    /* create the thread */
    ThreadHandle = CreateThread(
        NULL,
        0,
        Summation,
        &Param,
        0,
        &ThreadId
    );

    if (ThreadHandle != NULL) {
        WaitForSingleObject(ThreadHandle, INFINITE);
        CloseHandle(ThreadHandle);
        printf("sum = %d\n", Sum);
    }

}