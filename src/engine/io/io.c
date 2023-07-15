// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// Our own libary's
#include "../io.h"
#include "../debug.h"

File ReadFile(const char* FilePath)
{
    File file = {.is_valid = false};

    FILE* fp = fopen(FilePath, "rb");

    if (ferror(fp))
    {
        DebugPrint("Stream Error")
        exit(1);
    }

    char* data = NULL;
    char* temp;
    size_t size = 0;
    size_t used = 0;
    size_t n;

    if (fp == NULL)
    {
        DebugPrint("Invalid Parameters")
        exit(1);
    }

    while (1)
    {
        if (used + ChunkSize + 1 > size)
        {
            size = used + ChunkSize + 1;

            if (size <= used)
            {
                free(data);
                DebugPrint("Too much input")
                exit(1);
            }

            temp = realloc(data, size);

            if (temp == NULL)
            {
                free(data);
                DebugPrint("Out of memory")
                exit(1);
            }

            data = temp;
        }
        
        n = fread(data + used, 1, ChunkSize, fp);

        if (n == 0)
        {
            break;
        }

        used += n;
    }

    if (ferror(fp))
    {
        free(data);
        DebugPrint("Stream Error")
        exit(1);
    }

    temp = realloc(data, used + 1);

    if (temp == NULL)
    {
        free(data);
        DebugPrint("Out of memory")
        exit(1);
    }

    data = temp;
    data[used] = '\0';

    file.data = data;
    file.len = used;
    file.is_valid = true;

    return file;
}

