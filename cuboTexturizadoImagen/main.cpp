
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
//#include "./header/stb_image.h"

#include "./header/ventana.h"
#include "./header/shader.h"

Ventana *ventana;
Model *model;

void finish(){
    glfwTerminate();
    delete(model);
    delete(ventana);
    
}

void init(){
    ventana = new Ventana(600,600);
    // Inicializar GLFW
    ventana->initGLFW();
    // Inicializar GLEW
    ventana->initGLEW();
    
    model = new Model();
    ventana->initModels(model);
    ventana->initViewProyection();

}

int main() {
    
    init();
    ventana->render();
    finish();

    return 0;
}
