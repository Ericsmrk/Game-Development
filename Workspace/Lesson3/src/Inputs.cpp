#include "Inputs.h"
//Note not using glut anymore
//use mouse/keyboard
//make a global model

Inputs::Inputs()
{
    //ctor
}

Inputs::~Inputs()
{
    //dtor
}

//NEED TO TELL MODEL WHAT TO DO
void Inputs::keyPressed(Model* mdl)
{
    //pass message to wparam
    switch(wParam)
    {
    case VK_LEFT:
        mdl->rotateY -=1.0;
        break;


    case VK_RIGHT:
        mdl->rotateY +=1.0;
        break;

    case VK_DOWN:
        mdl->rotateX -=1.0;
        break;

    case VK_UP:
        mdl->rotateX +=1.0;
        break;

    //case VK_OEM_:
    case 0xBD:
        mdl->zoom -=1.0;
        break;

    case 0xBB:
        mdl->zoom +=1.0;
        break;
    }
}

void Inputs::keyUp()
{
    switch(wParam){

    }
}

void Inputs::mouseBtnDwn(Model* mdl, double x, double y)
{
    prev_Mx = x;
    prev_My = y;

    //need to know how much movement for action at least 10-15
    switch(wParam){
        case MK_LBUTTON: Mouse_Rotate = true; break;
        case MK_RBUTTON: Mouse_transalate = true; break;
        case MK_MBUTTON: break;


    }
}

void Inputs::mouseBtnUp()
{
    Mouse_Rotate = false;
    Mouse_transalate = false;
}

void Inputs::mouseWheel(Model* mdl, double delta)
{
    mdl->zoom += delta/100.0;
}

void Inputs::mouseMovel(Model* mdl, double x, double y)
{
    if(Mouse_transalate){
        //change positions of mouse
        mdl->posX += (x - prev_Mx)/100.0;
        mdl->posY -= (y - prev_My)/100.0;

        prev_Mx = x;
        prev_My = y;
    }

    if(Mouse_Rotate){
        //change positions of mouse
        mdl->rotateX += (x - prev_Mx)/3.0;
        mdl->rotateY -= (y - prev_My)/3.0;

        prev_Mx = x;
        prev_My = y;
    }

}

