#include "GLScene.h"
//#include "<GLLight.h>
#include "GLLight.h"
#include "Model.h"
#include<Inputs.h>

//make the teapot
Model *myFirstModel = new Model();
Inputs *KbMs = new Inputs();     //what is an instance?

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
        myFirstModel->drawModel();
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

    //KbMs->mdl =myFirstModel; // copy model to ndl

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



int GLScene::winMsg(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    KbMs->wParam = wParam;
    switch(uMsg)
    {
    case WM_KEYDOWN:
        //KbMs->wParam = wParam; //moved up
        KbMs->keyPressed(myFirstModel);
        break;

    case WM_KEYUP:
        KbMs->keyUp();
        break;

    case WM_LBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam), HIWORD(lParam));//these are keyboard signals
        break;

    case WM_RBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam), HIWORD(lParam));//these are keyboard signals
        break;

    case WM_MBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam), HIWORD(lParam));//these are keyboard signals
        break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KbMs->mouseBtnUp();
        break;

    case WM_MOUSEMOVE:
        KbMs->mouseMovel(myFirstModel, LOWORD(lParam), HIWORD(lParam));//these are keyboard signals
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(myFirstModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;

    }
}


//create player class
