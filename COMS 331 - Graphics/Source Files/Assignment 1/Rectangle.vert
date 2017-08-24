/************************************************************************
*																		*
*	Program:	Rectangle.vert											*
*																		*
*	Author:		Robb T. Koether											*
*																		*
*	Date:		Mon, Aug 21, 2017										*
*																		*
*	Purpose:	This is a pass-through shader that will pass the		*
*				position and color of the vertex						*
*																		*
************************************************************************/

//	Version of GLSL

#version 450 core

//	Input variables

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vColor;

//	Output variables

out vec4 color;

/************************************************************************
*																		*
*	Function:	main													*
*																		*
************************************************************************/

void main()
{
	gl_Position = vec4(vPosition, 1.0f);
	color = vec4(vColor, 1.0f);
}