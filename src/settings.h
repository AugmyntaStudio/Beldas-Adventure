#include <stdio.h>

#include <windows.h>

//
// Here we have multiple settings so we dont have to retrace all of this. It's way easier to just put these settings in a header file
//

#define EXTENDED_WINDOW_STYLE WS_EX_CLIENTEDGE           // The extended window style
#define GAME_NAME "The legend Of Belda"                  // What our window title is
#define WINDOW_STYLE WS_OVERLAPPEDWINDOW | WS_VISIBLE    // Our normal window style
#define HORIZONTAL_POSITION CW_USEDEFAULT                // The horizontal position of our window
#define VERTICAL_POSITION CW_USEDEFAULT                  // The vertical position of our window
#define WINDOW_WIDTH CW_USEDEFAULT                       // The width of our window
#define WINDOW_HEIGHT CW_USEDEFAULT                      // The height of our window