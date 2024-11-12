#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../header/shader.h"
#include "../header/textura.h"

class Model{
public:

    Shader* shader;
    GLfloat vertices[84];
    GLfloat uv[28];
    GLuint indices[36];
    Textura* textura;
    float angle;
    glm::mat4 modelmat;
    GLuint VAO, VBO, UVBO, EBO;

    Model();
    //Model(GLfloat* vertices, GLuint indices);

    void initModel();
    void renderModel(glm::mat4 view, glm::mat4 projection);
    void updateModel(float timeValue);
    void finish();


};