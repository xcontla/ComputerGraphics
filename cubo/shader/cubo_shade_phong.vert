#version 410 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
out vec3 fragNormal;
out vec3 shadedcolor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 posCam;



void main()
{
   
    vec4 modelpos = model * vec4(position, 1.0);
    vec3 L = normalize(posLuz - modelpos.xyz) ;
    vec4 modelNormal = (model * vec4(normal,1.0));
    vec3 N = normalize( modelNormal.xyz );
    fragNormal = (N + 1.0) * 0.5 ;

    //vec3 R = reflect(-L,N);
    vec3 V = normalize(posCam - modelpos.xyz) ;
    vec3 H = normalize(L + V);


    shadedcolor = coef_ambiental * matColor + 
                  coef_difusa * matColor * max(dot(N,L),0.0) +
                 // colorLuz * coef_especular * pow(max(dot(V,R),0.0),glossines);
                 colorLuz * coef_especular * pow(max(dot(N,H),0.0),glossines);

    
    gl_Position = projection * view * model * vec4(position, 1.0);
   //gl_Position = projection * view * modelpos;
}