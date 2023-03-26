#include "GLScene.h"
#include "GLLight.h"
#include <GL/freeglut.h>

GLScene::GLScene()
{
	// Constructor
}

GLScene::~GLScene()
{
	// Destructor
}

bool GLScene::InitGL()
{
	// Initialize OpenGL
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Initialize Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	GLLight Light(GL_LIGHT0);
	Light.setLight(GL_LIGHT0);
	
	return true;
}

bool GLScene::DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);

	glTranslatef(0.0f, 0.0f, -5.0f);

	glPushMatrix();
		glutSolidTeapot(1.5);
	glPopMatrix();
	
	return true;
}

void GLScene::ResizeGLScene(GLsizei width, GLsizei height)
{
	float ratio = (float)width / (float)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, ratio, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
