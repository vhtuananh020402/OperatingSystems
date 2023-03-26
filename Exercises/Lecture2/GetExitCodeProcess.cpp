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

    // Get the process exit code
    DWORD exitCode = 0;
    if (!GetExitCodeProcess(pi.hProcess, &exitCode)) {
        std::cerr << "Failed to get exit code: " << GetLastError() << std::endl;
        return 1;
    }
    std::cout << "Process exit code: " << exitCode << std::endl;

    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
