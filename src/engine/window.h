#pragma once

// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct RENDER
{
	GLFWwindow *Window;
	int Width;
	int Height;
	char* Title;
	bool VSync;
	bool FullScreen;
	int Samples;
} RENDER;

GLFWwindow *NewWindow(int WindowWidth, int WindowHeight, char* WindowTitle, bool VSync, bool FullScreen, int Samples);

