#ifndef MODEL_H
#define MODEL_H


class Model
{
    public:
        Model();
        virtual ~Model();

        void drawModel();
        void modelInit();

        float rotateX;
        float rotateY;
        float rotateZ;

        //zoom in zoom out move pos
        float zoom;
        float posX;
        float posY;

    protected:

    private:
};

#endif // MODEL_H
