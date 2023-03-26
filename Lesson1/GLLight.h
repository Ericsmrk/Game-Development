#pragma once
#include "GLScene.h"

class GLLight:GLScene
{
	public:
		GLLight(GLenum);
		virtual ~GLLight();

        GLfloat light_ambient[4] = { 0.0f, 0.0f, 0.0f, 1.0f }; //use diff value for environment SLIDE 6 191/LEC5
        GLfloat light_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; //shows the depth vr3d look
        GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; //the shininess
        GLfloat light_position[4] = { 2.0f, 5.0f, 5.0f, 0.0f };

        //changes tone of the brightness
        GLfloat mat_ambient[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
        GLfloat mat_diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
        GLfloat mat_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; //changes color of the dot
        GLfloat high_shininess[1] = { 100.0f };

        void setLight(GLenum);
};

