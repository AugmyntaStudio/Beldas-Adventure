#include <stdio.h>

#include <windows.h>

#include "main.h"

#include "settings.h"

//
// Here we have the main function, this handles all the functions and creates a infinite loop
//

int APIENTRY WinMain(HINSTANCE Instance, HINSTANCE PreviousInstance, PSTR LongPointerCommandLine, int CommandPromptShow)
{
    //
    // Some parameters we need
    //

    UNREFERENCED_PARAMETER(Instance);

    UNREFERENCED_PARAMETER(PreviousInstance);

    UNREFERENCED_PARAMETER(LongPointerCommandLine);

    UNREFERENCED_PARAMETER(CommandPromptShow);

    //
    // Checking if the game is running
    //

    if (GameIsAlreadyRunning() == TRUE)
    {
        return (0);
    }

    //
    // Checking if the making of the window was succesful
    //

    if (CreateMainGameWindow() != ERROR_SUCCESS)
    {
        printf("Window Creation Failed");
        return (0);
    }

    MSG Message = {0};

    //
    // A loop so the window never closes untill you click on the close button or the escape key
    //

    while (GameIsRunning == TRUE)
    {
        while (PeekMessageA(&Message, GameWindow, 0, 0, PM_REMOVE))
        {
            DispatchMessageA(&Message);
        }

        ProcessPlayerInput();

        Sleep(1);
    }

    return(0);
}

//
// This is the Main Window Procedure Function
//

LRESULT CALLBACK MainWindowProcedureFunction(
    HWND WindowHandle,       // Handle to window
    UINT Message,            // Message identifier
    WPARAM ParameterOne,     // First message parameter
    LPARAM ParameterTwo)     // Second message parameter

{
    LRESULT Result = 0;
    

    switch (Message)
    {
        case WM_CLOSE:
        {
            GameIsRunning = FALSE;

            PostQuitMessage(0);

            break;
        }
        
        default:
        {
            Result = DefWindowProcA(WindowHandle, Message, ParameterOne, ParameterTwo);
        }
    }

    return (Result); // here we return the message and other parameters that are necessary
}

DWORD CreateMainGameWindow(void)
{
    //
    // Some parameters we need
    //

    DWORD Result = ERROR_SUCCESS;

    WNDCLASSEXA WindowClass = {0};

    //
    // Setting up the window with the right settings
    //

    WindowClass.cbSize = sizeof(WNDCLASSEX);                    // Declare the right window size
    WindowClass.style = 0;                                      // Declare the window style
    WindowClass.lpfnWndProc = MainWindowProcedureFunction;      // A pointer to the Window Procedure Function
    WindowClass.cbClsExtra = 0;                                 // The number of extra bytes to allocate following the window-class structure
    WindowClass.cbWndExtra = 0;                                 // The number of extra bytes to allocate following the window instance
    WindowClass.hInstance = GetModuleHandleA(NULL);             // A handle to the instance that contains the window procedure function for the class
    WindowClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);       // What image you want the icon to be
    WindowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);         // What image you want the mouse cursor to be
    WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);     // Change the color of everything
    WindowClass.lpszMenuName = NULL;                            // Pointer to a null-terminated character string that specifies the resource name of the class menu
    WindowClass.lpszClassName = "GAME_WINDOWCLASS";             // The name of the game window class
    WindowClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);     // A handle to a small icon that is associated with the window class

    //
    // Checking if the window registered correctly
    //

    if (!RegisterClassExA(&WindowClass))
    {
        Result = GetLastError();

        MessageBoxA(NULL, "Window Regsitration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OKCANCEL);
        
        return (Result);
    }

    //
    // Setting up the looks of the window
    //

    GameWindow = CreateWindowExA(
        EXTENDED_WINDOW_STYLE,               // The extended window style of the window being created
        WindowClass.lpszClassName,           // The class name of the game window
        GAME_NAME,                           // The window name
        WINDOW_STYLE,                        // The style of the window
        HORIZONTAL_POSITION,                 // The horizontal position of the window
        VERTICAL_POSITION,                   // The vertical position of the window
        WINDOW_WIDTH,                        // The width of the window
        WINDOW_HEIGHT,                       // The height of the window
        NULL,                                // The parent of the window being created
        NULL,                                // The identifier for a child window
        WindowClass.hInstance,               // A handle to the instance that contains the window procedure function for the class
        NULL                                 // Pointer to a value to be passed to the window through the CREATESTRUCT structure pointed to by the lParam param of the WM_CREATE message 
    );

    //
    // Checking if the window creation was succesful
    //

    if (GameWindow == NULL)
    {
        Result = GetLastError();

        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OKCANCEL);
        
        return (Result);
    }

    return (Result);
}

//
// Now there comes a function that will return a true or false value for wether our program is already running or not
//

BOOL GameIsAlreadyRunning(void)
{
    HANDLE Mutex = NULL;

    Mutex = CreateMutexA(NULL, FALSE, GAME_NAME "_GameMutex");

    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        return(TRUE);
    }
    else
    {
        return FALSE;
    }
}

//
// This function is for processing the input of the player
//

void ProcessPlayerInput(void)
{
    SHORT EscapeKeyIsDown = GetAsyncKeyState(VK_ESCAPE);

    if (EscapeKeyIsDown)
    {
        printf("Escape key down");
        SendMessageA(GameWindow, WM_CLOSE, 0, 0);
    }
}