// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "GLFW/glfw3.h"

// Our own libary's
#include "../debug.h"

double FpsToMspf(double fps)
{
	return(1000/fps);
}

double MspfToFps(double mspf)
{
	return(1000/mspf);
}

void PrintSystemSpecs()
{
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
}

