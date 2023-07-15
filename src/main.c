// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "linmath.h"

// Our own libary's
#include "engine/debug.h"
#include "engine/io.h"
#include "engine/window.h"
#include "engine/render.h"
#include "engine/shader.h"

// Initialize values
RENDER Render;
bool QuitApplication = false;
void Update();
#define TARGET_FPS 240

int main()
{	
	NewWindow(1024, 768, "Belda's Adventure", false, false, 4);
	
	RenderInitTriangle();
	//RenderInitQuad();
	
	PrintSystemSpecs();
	
	GLuint ProgramID = LoadShaders("Shaders\\SimpleShader.vert", "Shaders\\SimpleShader.frag");

	double LastTimeDivided = glfwGetTime();
	double LastTime = glfwGetTime();
	double Frames;

	do
	{
		Update();

		double CurrentTime = glfwGetTime();

		Frames++;

		if (CurrentTime - LastTime >= 1.0)
		{
			printf("mspf: %f\n", 1000 / Frames);
			printf("fps: %f\n", MspfToFps(1000 / Frames));
			Frames = 0;
			LastTime += 1.0;
		}
		
		while (glfwGetTime() < LastTimeDivided + 1.0/TARGET_FPS) {
			// TODO: Put the thread to sleep, yield, or simply do nothing
		}
		
		LastTimeDivided += 1.0/TARGET_FPS;
	}

	while(QuitApplication == false && glfwWindowShouldClose(Render.Window) == 0);
}

void Update()
{
	RenderBegin();
	
	RenderTriangle();
	//RenderQuad();
	
	RenderEnd();
}

