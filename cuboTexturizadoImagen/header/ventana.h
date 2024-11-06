#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../header/model.h"

class Ventana{
    public:
        GLuint width, height;
        GLFWwindow* window;
        glm::mat4 view, projection;

        Model *model;

        Ventana();
        Ventana(GLuint w, GLuint h);
        void initGLFW();
        void initGLEW();
        void initModels(Model* m);
        
        void initViewProyection();
        void render();
        void update();
        void idel();
        void finish();
};