#pragma once

// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"

#define DEBUG 1
#define DebugPrint(message) if(DEBUG == 1) {fprintf(stderr, "%s:%d:%s(): " message, __FILE__, __LINE__, __FUNCTION__); printf("\n");}

double FpsToMspf(double fps);
double MspfToFps(double mspf);
void PrintSystemSpecs();

