#include "Model.h"
#include <windows.h>
#include <GL/glut.h>

Model::Model()
{
    //ctor
    //rotations
    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;

    zoom = -8.0;
    posX = 0.0;
    posY = 0.0;

}

Model::~Model()
{
    //dtor
}
void Model::drawModel()
{//need to add call
    glTranslated(posX,posY,zoom);
    glRotated(rotateX,1,0,0);
    glRotated(rotateY,0,1,0);
    glRotated(rotateZ,0,0,1);

    glutSolidTeapot(1.5);

}

void Model::modelInit()
{

}
