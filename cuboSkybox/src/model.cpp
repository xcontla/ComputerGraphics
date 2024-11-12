#include "../header/model.h"


    Model::Model()
    {

        vertices[0] = -0.5f; vertices[1]  = -0.5f; vertices[2]  = -0.5f; vertices[3]  = 1.0f; vertices[4]  = 0.0f; vertices[5]  = 0.0f; // v0     
        vertices[6]  = 0.5f; vertices[7]  = -0.5f; vertices[8]  = -0.5f; vertices[9]  = 0.0f; vertices[10] = 1.0f; vertices[11] = 0.0f; // v1
        vertices[12] = 0.5f; vertices[13] =  0.5f; vertices[14] = -0.5f; vertices[15] = 0.0f; vertices[16] = 0.0f; vertices[17] = 1.0f; // v2
        vertices[18] =-0.5f; vertices[19] =  0.5f; vertices[20] = -0.5f; vertices[21] = 1.0f; vertices[22] = 1.0f; vertices[23] = 0.0f; // v3
        vertices[24] =-0.5f; vertices[25] = -0.5f; vertices[26] =  0.5f; vertices[27] =  0.0f; vertices[28] = 1.0f; vertices[29] = 1.0f; // v4
        vertices[30] = 0.5f; vertices[31] = -0.5f; vertices[32] =  0.5f; vertices[33] =  1.0f; vertices[34] = 0.0f; vertices[35] = 1.0f; // v5
        vertices[36] = 0.5f; vertices[37] =  0.5f; vertices[38] =  0.5f; vertices[39] =  0.5f; vertices[40] = 0.5f; vertices[41] = 0.5f; // v6
        vertices[42] =-0.5f; vertices[43] =  0.5f; vertices[44] =  0.5f; vertices[45] =  1.0f; vertices[46] = 0.5f; vertices[47] = 0.0f; // v7

        vertices[48] = 0.5f; vertices[49] =  0.5f; vertices[50] =  0.5f; vertices[51] =  0.5f; vertices[52] = 0.5f; vertices[53] = 0.5f; // v6
        vertices[54] = 0.5f; vertices[55] = -0.5f; vertices[56] =  0.5f; vertices[57] =  1.0f; vertices[58] = 0.0f; vertices[59] = 1.0f; // v5
        vertices[60] =-0.5f; vertices[61] =  0.5f; vertices[62] =  0.5f; vertices[63] =  1.0f; vertices[64] = 0.5f; vertices[65] = 0.0f; // v7
        vertices[66] =-0.5f; vertices[67] = -0.5f; vertices[68] =  0.5f; vertices[69] =  0.0f; vertices[70] = 1.0f; vertices[71] = 1.0f; // v4
        vertices[72] = 0.5f; vertices[73] =  0.5f; vertices[74] =  0.5f; vertices[75] =  0.5f; vertices[76] = 0.5f; vertices[77] = 0.5f; // v6
        vertices[78] = 0.5f; vertices[79] = -0.5f; vertices[80] =  0.5f; vertices[81] =  1.0f; vertices[82] = 0.0f; vertices[83] = 1.0f; // v5
        

        // v8 <-> v6;
        // v9 <-> v5;
        // v10 <-> v7;
        // v11 <-> v4;
        // v12 <-> v6;
        // v13 <-> v5;  
       

        indices[0] =  1; indices[1] = 0;   indices[2] = 3;indices[3] = 1;indices[4] = 3;indices[5] = 2;        // 1
        indices[6] =  2; indices[7] = 3;   indices[8] = 7;indices[9] = 2;indices[10] = 7;indices[11] = 6;      // 2 
        indices[12] = 5; indices[13] = 4;  indices[14] = 0;indices[15] = 5;indices[16] = 0;indices[17] = 1;   // 3
        indices[18] = 9; indices[19] = 1; indices[20] = 2;indices[21] = 9;indices[22] = 2;indices[23] = 8;   // 4
        indices[24] = 11; indices[25] = 13;  indices[26] = 12;indices[27] = 11;indices[28] = 12;indices[29] = 10;   // 5       
        indices[30] = 0; indices[31] = 11;  indices[32] = 10;indices[33] = 0;indices[34] = 10;indices[35] = 3;  // 6

        //asignamos coordenadas de vértices
        uv[0] = 0.5f;   uv[1] = 0.66f; 
        uv[2] = 0.25f;  uv[3] = 0.66f; 
        uv[4] = 0.25f;  uv[5] = 0.33f; 
        uv[6] = 0.5f;   uv[7] = 0.33f; 
        uv[8] = 0.5f;   uv[9] = 1.0f; 
        uv[10] = 0.25f; uv[11] = 1.0f; 
        uv[12] = 0.25f; uv[13] = 0.0f; 
        uv[14] = 0.5f;  uv[15] = 0.0f; 
        
        uv[16] = 0.0f;  uv[17] = 0.33f; 
        uv[18] = 0.0f;  uv[19] = 0.66f; 
        uv[20] = 0.75f; uv[21] = 0.33f; 
        uv[22] = 0.75f; uv[23] = 0.66f; 
        uv[24] = 1.0f;  uv[25] = 0.33f; 
        uv[26] = 1.0f;  uv[27] = 0.66f; 
    
    }


    //Model::Model(GLfloat* vertices, GLuint indices){}

    void Model::initModel()
    {

    modelmat = glm::mat4(1.0f);
    shader = new Shader("./shader/cubo.vert","./shader/cuboImagen.frag");
         // Crear y enlazar el VAO y VBO
    textura = new Textura("./img/skybox.jpg");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &UVBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Especificar el layout del vertex shader
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);


    glBindBuffer(GL_ARRAY_BUFFER, UVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_STATIC_DRAW);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(2);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    }

    void Model::updateModel(float timeValue){
        
        modelmat = glm::scale(glm::mat4(1.0f),glm::vec3(30.0f));
        modelmat = glm::rotate(modelmat,timeValue*0.5f, glm::vec3(0.0f,1.0,0.0));
    }

    void Model::renderModel(glm::mat4 view, glm::mat4 projection){
        
        shader->use();

        // Enviar las matrices al shader
        shader->setMat4x4("model", modelmat);
        shader->setMat4x4("view", view);
        shader->setMat4x4("projection", projection);
        
        //Activar textura
        textura->activar(GL_TEXTURE0,shader->ID);
        // Dibujar el cubo
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 36 , GL_UNSIGNED_INT, 0);

    }
    void Model::finish(){

        
        shader->terminate();
        delete(shader);
        delete(textura);
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &UVBO);
        glDeleteBuffers(1, &EBO);
    }