#pragma once

// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"

// TODO: Compile shaders and load shaders
GLuint LoadShaders(const char* VertexFilePath, const char* FragmentFilePath);

typedef struct BUFFER
{
    GLuint VertexBuffer;
} BUFFER;

