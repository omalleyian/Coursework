/************************************************************************
*																		*
*	Program:	Rectangle.frag											*
*																		*
*	Author:		Robb T. Koether											*
*																		*
*	Date:		Mon, Aug 21, 2017										*
*																		*
*	Purpose:	This is a pass-through shader that will pass the		*
*				color of the vertex										*
*																		*
************************************************************************/

//	Version of GLSL

#version 430 core

//	Input variables

in vec4 color;

//	Output variables

out vec4 fragColor;

/************************************************************************
*																		*
*	Function:	main													*
*																		*
************************************************************************/

void main()
{
	fragColor = color;
}