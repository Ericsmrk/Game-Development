#include "GLScene.h"
//#include "<GLLight.h>
#include "GLLight.h"
#include "Model.h"

//make the teapot
Model *myFirstTeapot = new Model();

GLScene::GLScene()
{
    //ctor
}

GLScene::~GLScene()
{
    //dtor
}
int GLScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //clear out color and depth
    glLoadIdentity();

    //glColor3f(1.0,0.0,0.0); //R, G B  //removed
    //glTranslated(0,0,-8);             //removed

    glPushMatrix();
        myFirstTeapot->drawModel();
    //glutSolidTeapot(1.5);             //removed
    glPopMatrix();
}

int GLScene::GLinit()
{
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL); //maybe disable and have just texture?
    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    return true;
    //return false;
}

void GLScene::GLReSize(GLsizei width, GLsizei height)
{
    float ratio = (float)width/(float)height;
    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0,ratio, 0.1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//create player class
