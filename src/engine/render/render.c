// Include default libary's
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "linmath.h"

// Our own libary's
#include "../render.h"
#include "../window.h"
#include "../shader.h"

// Initialize values
RENDER Render;
BUFFER Buffer;

static const GLfloat TriangleVertexBufferData[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f,
};

float QuadVertices[] = {
	0.5, 0.5, 0, 0, 0,
	0.5, -0.5, 0, 0, 1,
	-0.5, -0.5, 0, 1, 1,
	-0.5, 0.5, 0, 1, 0
};

uint32_t QuadIndices[] = {
	0, 1, 3,
	1, 2, 3
};

void RenderBegin()
{
	glClearColor(0.08, 0.1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderEnd()
{
	glfwSwapBuffers(Render.Window);
	glfwPollEvents();
}

void RenderInitTriangle()
{
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &Buffer.VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, Buffer.VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TriangleVertexBufferData), TriangleVertexBufferData, GL_STATIC_DRAW);
}

void RenderTriangle()
{
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

void RenderInitQuad()
{
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &Buffer.VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, Buffer.VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(QuadVertices), QuadVertices, GL_STATIC_DRAW);
}

void RenderQuad()
{
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		5 * sizeof(float),
		NULL
	);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

	glDisableVertexAttribArray(0);
}

