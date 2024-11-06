#version 410 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
out vec3 fragNormal;
out vec3 shadedcolor;

out vec4 modelpos;
out vec4 modelNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;



void main()
{
   
    modelpos = model * vec4(position, 1.0);
    modelNormal = (model * vec4(normal,1.0));
    fragNormal = (modelNormal.xyz + 1.0) * 0.5 ;
    
    //gl_Position = projection * view * model * vec4(position, 1.0);
   gl_Position = projection * view * modelpos;
}