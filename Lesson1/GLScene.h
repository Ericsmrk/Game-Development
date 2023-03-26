#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <iostream>

class GLScene
{
public:
	GLScene();
	virtual ~GLScene();
	bool InitGL();
	bool DrawGLScene();
	void ResizeGLScene(GLsizei width, GLsizei height);
};