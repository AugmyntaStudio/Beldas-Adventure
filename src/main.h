#include <stdio.h>

#include <windows.h>

//
// This header file is made for all of our global variables or undefined functions
//

LRESULT CALLBACK MainWindowProcedureFunction(
    HWND WindowHandle,       // Handle to window
    UINT Message,            // Message identifier
    WPARAM ParameterOne,     // First message parameter
    LPARAM ParameterTwo      // Second message parameter
);

DWORD CreateMainGameWindow(void);

BOOL GameIsAlreadyRunning(void);

HANDLE GameWindow;

BOOL GameIsRunning = TRUE;

void ProcessPlayerInput(void);