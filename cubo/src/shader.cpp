// shader.cpp
#include "../header/shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vertexPath, const char* fragmentPath) {

 // Leer los shaders
    std::string vertexShaderCode = leerArchivoShader(vertexPath);
    std::string fragmentShaderCode = leerArchivoShader(fragmentPath);


    if (vertexShaderCode.empty() || fragmentShaderCode.empty()) {
        std::cerr << "Error al cargar los shaders" << std::endl;
    }

        // Convertir los strings a const char*
    const char* vShaderCode = vertexShaderCode.c_str();
    const char* fShaderCode = fragmentShaderCode.c_str();

    std::cout << "Iniciando compilación de Shader Vertices: " << std::endl;
    
    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

        // Check for shader compile errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    std::cout << "Iniciando compilación de Shader Fragmentos: " << std::endl;
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

     // Check for shader compile errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    std::cout << "Finalizando compilación Shader" << std::endl;
    
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    std::cout << "Linkeado Shader" << std::endl;

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    std::cout << "Fin - Inicialización Shader" << std::endl;
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec3(const std::string &name, float x, float y, float z) const {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::setVec3(const std::string &name, glm::vec3 vector) const {
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &vector[0]);
}

void Shader::setMat4x4(const std::string &name,  const glm::mat4 &value) const{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::terminate(){
    std::cout << "Termina Shader" << std::endl;
    glDeleteProgram(ID);
}

std::string  Shader::leerArchivoShader(const char* rutaArchivo) {
    std::ifstream archivoShader;
    std::stringstream bufferShader;

    // Abrir archivo
    archivoShader.open(rutaArchivo);
    if (!archivoShader.is_open()) {
        std::cerr << "No se pudo abrir el archivo del shader: " << rutaArchivo << std::endl;
        return "";
    }

    // Leer el contenido del archivo en un stringstream
    bufferShader << archivoShader.rdbuf();

    // Cerrar el archivo
    archivoShader.close();

    // Convertir el contenido del stringstream en un string
    return bufferShader.str();
}
