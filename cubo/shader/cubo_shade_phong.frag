#version 410 core
in vec3 fragNormal;
in vec3 shadedcolor;
out vec4 color;

float coef_ambiental = 0.1;
float coef_difusa = 0.8;
float coef_especular = 0.9;

vec3 matColor = vec3(1.0,0.0,1.0);
vec3 posLuz = vec3(-5.0);
vec3 colorLuz = vec3(0.0,1.0,1.0    );

float glossines = 50.0;

void main()
{
    color = vec4(shadedcolor, 1.0);
}