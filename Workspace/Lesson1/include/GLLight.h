#ifndef GLLIGHT_H
#define GLLIGHT_H
#include<GLScene.h>

class GLLight:GLScene //pulls all methods from glscene
{
    public:
        GLLight();
        virtual ~GLLight();

     /*    GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
         GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
         GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
         GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

         GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
         GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
         GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
         GLfloat high_shininess[] = { 100.0f };

        void setLight(enum);
*/
    protected:

    private:
};

#endif // GLLIGHT_H
