/****************************************************************************
*																			*
*	Program:	PluSign.cpp												*
*																			*
*	Author:		Robb T. Koether												*
*																			*
*	Date:		Mon, Aug 21, 2017											*
*																			*
*	Purpose:	This program will draw a red square							*
*																			*
****************************************************************************/

//	Header files

#include <iostream>
#include "vgl.h"
#include "LoadShaders.h"

using namespace std;

//	Enumerated types

enum VAO_IDs { Rect, NumVAOs };
enum VBO_IDs { RectBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0, vColor = 1 };

//	Global variables

GLuint VAOs[NumVAOs];
GLuint VBOs[NumBuffers];

GLfloat red = 66.0f;
GLfloat green = 215.0f;
GLfloat blue = 244.0f;

//	Other functions

void init();
void createPlusSign();
void display();

/************************************************************************
*																		*
*	Function:	main													*
*																		*
************************************************************************/

int main(int argc, char* argv[])
{
	//	Initialize the glfw library

	glfwInit();

	//	Create a window

	GLFWwindow* window = glfwCreateWindow(800, 800, "Rectangle", NULL, NULL);
	glfwMakeContextCurrent(window);

	//	Initialize the gl3w library

	gl3wInit();

	//	Initialize various objects

	init();

	//	Render the scene until the window is closed

	while (!glfwWindowShouldClose(window))
	{
		display();					// Render the scene in back buffer
		glfwSwapBuffers(window);	// Move back buffer to front
		glfwPollEvents();			// Check for user input
	}

	//	Destroy the window and quit

	glfwDestroyWindow(window);
	glfwTerminate();
}

/************************************************************************
*																		*
*	Function:	init													*
*																		*
************************************************************************/

void init()
{
	//	Set the background color

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//	Create the buffers and arrays in the GPU

	glGenBuffers(NumBuffers, VBOs);
	glGenVertexArrays(NumVAOs, VAOs);

	//	Specify the vertex and fragment shader programs

	ShaderInfo shaders[] =
	{
		{ GL_VERTEX_SHADER, "PlusSign.vert" },
		{ GL_FRAGMENT_SHADER, "PlusSign.frag" },
		{ GL_NONE, NULL }
	};

	//	Load the shader programs

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	//	Store the retangle data in the GPU

	createPlusSign();

	cout << "Welcome to Rectangle" << endl << endl;

	return;
}

/************************************************************************
*																		*
*	Function:	display													*
*																		*
************************************************************************/

void display()
{
	//	Initialize the framebuffer with the background color

	glClear(GL_COLOR_BUFFER_BIT);

	//	Draw the rectangle

	glBindVertexArray(VAOs[Rect]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 12);

	return;
}

/************************************************************************
*																		*
*	Function:	createPlusSign											*
*																		*
************************************************************************/

void createPlusSign()
{
	//	Specify the corners of the square

	GLfloat rect_data[24] =
	{
		-0.25f,  0.25f	//Inner - Upper Left
		-0.5f, -0.25f,	//Left Strut - Upper
		-0.5f, 0.25f,	//Left Strut - Lower
		-0.25f, -0.25f,	//Inner - Lower Left
		-0.25f, -0.55f,	//Lower Strut - Left
		0.25f, -0.5f,	//Lower Strut - Right
		0.25f, -0.25f,	//Inner - Lower Right
		0.5f, 0.25f,	//Right Strut - Upper
		0.5f, -0.25f,	//Right Strut - Lower
		0.25f,  0.25f,	//Inner - Upper Right
		-0.25f, 0.5f,	//Upper Strut - Left
		0.25f, 0.5f,	//Upper Strut - Right		
	};

	//	Copy the coordinates into the buffer

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[RectBuffer]);
	glNamedBufferStorage(VBOs[RectBuffer], sizeof(rect_data), rect_data, 0);

	//	Set the pointer for the vertex attributes

	glBindVertexArray(VAOs[Rect]);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);

	//	Specify the color of the rectangle

	glVertexAttrib3f(vColor, red, green, blue);

	return;
}