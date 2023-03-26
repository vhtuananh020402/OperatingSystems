#include <windows.h>
#include <iostream>

int main() {
    // Create a process
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    if (!CreateProcess(NULL, "notepad.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "Failed to create process: " << GetLastError() << std::endl;
        return 1;
    }

    // Wait for the process to exit
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Terminate the process if it hasn't already exited
    DWORD exitCode = 0;
    if (!GetExitCodeProcess(pi.hProcess, &exitCode)) {
        std::cerr << "Failed to get exit code: " << GetLastError() << std::endl;
        return 1;
    }
    if (exitCode == STILL_ACTIVE) {
        if (!TerminateProcess(pi.hProcess, 1)) {
            std::cerr << "Failed to terminate process: " << GetLastError() << std::endl;
            return 1;
        }
    }

    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}