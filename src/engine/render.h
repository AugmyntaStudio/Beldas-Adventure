#pragma once

// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "linmath.h"

void RenderBegin();
void RenderEnd();
void RenderInitTriangle(); //int *vao, int *vbo, int *ebo
void RenderTriangle();
void RenderInitQuad();
void RenderQuad();

