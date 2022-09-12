#pragma once

// Include default libary's
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Third party libary's
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// Our own libary's
#include "engine/render/shader.hpp"

// Initiate values
bool GameLoop = true;

int main()
{	
	if(!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		glfwTerminate();
		return -1;
	}
	
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For MacOS
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We want the new OpenGL
	
	GLFWwindow* window;
	window = glfwCreateWindow(
		1024,                // Window width
		768,                 // Window height
		"Beldas adventure",  // Window title
		NULL,                // Use glfwGetPrimaryMonitor() if you want the window to be fullscreen
		NULL);               
	
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.");
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	
	GLuint programID = LoadShaders("Shaders\\SimpleVertexShader.vertexshader", "Shaders\\SimpleFragmentShader.fragmentshader");
	
	GLuint matrixID = glGetUniformLocation(programID, "MVP");
	
	
	// Projection matrx: 45 FOV, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) 4.0f / (float) 3.0f, 0.1f, 100.0f);
	
	// Camera matrix
	glm::mat4 View = glm::lookAt
	(
		glm::vec3(4, 3, 3), // Camera is at (4, 3, 3) in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0, -1, 0 to look upside-down)
	);
	
	// Model matrix: an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	
	// Our ModelViewProjection: multiplication of our 3 matrices
	glm::mat4 mvp = Projection * View * Model;
	
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		
	};
	
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	GameLoop = false;
	
	double lastTime = glfwGetTime();
	int nbFrames = 0;

	do
	{
		// Measure speed
		double currentTime = glfwGetTime();
		nbFrames++;
		
		if ( currentTime - lastTime >= 1.0 ){ // If last prinf() was more than 1 sec ago
			// printf and reset timer
			printf("%f ms/frame\n", 1000.0/double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;
		}
		
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//Use our shader
		glUseProgram(programID);
		
		// Send our tranformation to the currently bound shader, in the "MVP" uniform
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
		
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,         // attribute 0
			3,         // size
			GL_FLOAT,  // type
			GL_FALSE,  // normalized?
			0,         // stride
			(void*)0   // array buffer offset
		);
		
		// Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
