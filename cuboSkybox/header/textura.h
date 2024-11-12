#pragma once

#include <GL/glew.h>
#include <string>
#include <iostream>

#include "stb_image.h"


class Textura {
public:
    GLuint id;
    int width, height;

    // Constructor que carga la textura desde un archivo.
    Textura(const std::string& rutaArchivo) {
        // Cargar la imagen
          // Generar un ID de textura
    GLuint textureID;
    glGenTextures(1, &textureID);
    
    // Cargar la imagen usando stb_image
    int width, height, nrChannels;
    //stbi_set_flip_vertically_on_load(true); // Voltear verticalmente si es necesario
    std::cout << rutaArchivo.c_str() <<std::endl;
    unsigned char *data = stbi_load(rutaArchivo.c_str(), &width, &height, &nrChannels, 0);
    
    std::cout << "Width: " << width << "Height: " <<height << ", Channels: " <<nrChannels  <<std::endl;
    
    if (data) {  
        // Enlazar la textura y configurar sus parámetros
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Parámetros de la textura
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        stbi_image_free(data); // Liberar memoria de la imagen
    } else {
        std::cerr << "Failed to load texture" << std::endl;
        stbi_image_free(data);
    }
    
        id = textureID;
    }

    // Método para activar la textura
    void activar(GLenum unidad, GLuint shaderProgram) const {
        glActiveTexture(unidad);
        glBindTexture(GL_TEXTURE_2D, id);
        glUniform1i(glGetUniformLocation(shaderProgram, "texture0"), 0);
        
    }

    // Destructor para liberar recursos
    ~Textura() {
        glDeleteTextures(1, &id);
    }
};
