// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// Our own libary's
#include "../shader.h"
#include "../debug.h"
#include "../io.h"

// TODO: Compile shaders and load shaders
GLuint LoadShaders(const char* VertexFilePath, const char* FragmentFilePath)
{
    // Read Vertex Shader
    File VertexShaderCode = ReadFile(VertexFilePath);
    
    if (!VertexShaderCode.is_valid)
    {
        DebugPrint("Error reading file");
        return 0;
    }

    // Read Fragment Shader
    File FragmentShaderCode = ReadFile(FragmentFilePath);
    
    if (!FragmentShaderCode.is_valid)
    {
        DebugPrint("Error reading file");
        return 0;
    }

    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Compile Vertex Shader
    printf("Compiling shader: %s\n", VertexFilePath);
    glShaderSource(VertexShaderID, 1, (const char* const *) &VertexShaderCode, NULL);
    glCompileShader(VertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0)
    {
        char VertexShaderErrorMessage[InfoLogLength + 1];
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, VertexShaderErrorMessage);
        printf("%s\n", VertexShaderErrorMessage);
    }

    // Compile Fragment Shader
    printf("Compiling shader: %s\n", FragmentFilePath);
    glShaderSource(FragmentShaderID, 1, (const char* const *) &FragmentShaderCode, NULL);
    glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0)
    {
        char FragmentShaderErrorMessage[InfoLogLength + 1];
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, FragmentShaderErrorMessage);
        printf("%s\n", FragmentShaderErrorMessage);
    }

    // Link the program
    printf("Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0)
    {
        char ProgramErrorMessage[InfoLogLength + 1];
        glGetShaderInfoLog(ProgramID, InfoLogLength, NULL, ProgramErrorMessage);
        printf("%s\n", ProgramErrorMessage);
    }

    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    glUseProgram(ProgramID);

    return ProgramID;
}

