#include "./header/ventana.h"
#include "./header/shader.h"
#include <iostream>

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
