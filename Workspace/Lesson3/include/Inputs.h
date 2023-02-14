#ifndef INPUTS_H
#define INPUTS_H
#include <windows.h>
#include <Model.h>

class Inputs
{
    public://can change to private and use getters and setters this is SAFER
        Inputs();
        virtual ~Inputs();

        //1 pressing key
        void keyPressed(Model*);
        //2 releasing key
        void keyUp();

        //four mouse functions
        //1
        void mouseBtnDwn(Model* , double,double);
        //2
        void mouseBtnUp();
        //3
        void mouseWheel(Model* , double);
        //4
        void mouseMovel(Model* , double,double);

        WPARAM wParam;

        double prev_Mx;
        double prev_My;

        bool Mouse_transalate;
        bool Mouse_Rotate;

        //Model *mdl = new Model();//call model and link instance

    protected:

    private:
};

#endif // INPUTS_H
