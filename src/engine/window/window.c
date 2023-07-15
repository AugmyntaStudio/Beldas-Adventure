// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#ifdef _WIN32
	#include <winuser.h>
#endif

// Our own libary's
#include "../window.h"
#include "../io.h"

// Initialize values
RENDER Render;

GLFWwindow *NewWindow(int WindowWidth, int WindowHeight, char* WindowTitle, bool VSync, bool FullScreen, int Samples)
{
	Render.Width = WindowWidth;
	Render.Height = WindowHeight;
	Render.Title = WindowTitle;
	Render.VSync = VSync;
	Render.FullScreen = FullScreen;
	Render.Samples = Samples;
	
	if(!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		glfwTerminate();
		return NULL;
	}
	
	glfwWindowHint(GLFW_SAMPLES, Render.Samples);                  // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                 // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                 // OpenGL 3.3
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // For MacOS
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We want the new OpenGL (GLFW_OPENGL_CORE_PROFILE)

	if (Render.FullScreen == true)
	{
		#ifdef _WIN32
			Render.Width = GetSystemMetrics(SM_CXSCREEN);
			Render.Height = GetSystemMetrics(SM_CYSCREEN);
		#endif
		
		Render.Window = glfwCreateWindow(
		Render.Width,             // Window width
		Render.Height,            // Window height
		Render.Title,             // Window title
		glfwGetPrimaryMonitor(),  // We want the window to be fullscreen
		NULL);
	}
	else if (Render.FullScreen == false)
	{	
		Render.Window = glfwCreateWindow(
		Render.Width,   // Window width
		Render.Height,  // Window height
		Render.Title,   // Window title
		NULL,           // We dont want the window to be fullscreen
		NULL);
	}
	else
	{
		printf("%s", "You need to use a boolean when defining wether or not to use fullscreen mode");
	}
	
	if (Render.Window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.");
		glfwTerminate();
		return NULL;
	}
	
	glfwMakeContextCurrent(Render.Window);
	
	if (Render.VSync == true)
	{
		glfwSwapInterval(1); // Enable vsync
	}
	else if (Render.VSync == false)
	{
		glfwSwapInterval(0); // Disable vsync
	}
	
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	
	glfwSetInputMode(Render.Window, GLFW_STICKY_KEYS, GL_TRUE);

	//File GameIconLarge = ReadFile("Assets\\Icon\\Game_Icon_Large.png");
	//File GameIconSmall = ReadFile("Assets\\Icon\\Game_Icon_Small.png");

	//GLFWimage images[1];
	
	//images[0] = GameIconLarge.data;
	//images[1] = GameIconSmall.data;

	//glfwSetWindowIcon(Render.Window, 1, images);
	
	return (Render.Window);
}

