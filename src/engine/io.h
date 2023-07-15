#pragma once

// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// Initialize values
#define ChunkSize 2097152
// #define READALL_CHUNK 262144

typedef struct FILE {
    char* data;
	size_t len;
	bool is_valid;
} File;

File ReadFile(const char* FilePath);

