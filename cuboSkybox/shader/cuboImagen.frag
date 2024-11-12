#version 410 core
in vec3 fragColor;
in vec2 uv;


uniform sampler2D texture0; // La textura a aplicar
out vec4 color;

 int mandelbrot(vec2 c)
{

        vec2 z = vec2(0.0);
        int iterations = 0;
        const int maxIterations = 100;

        while(length(z) <= 2.0 && iterations < maxIterations)
        {
            z = vec2(z.x * z.x - z.y * z.y, 2.0 * z.x * z.y) + c;
            iterations++;
        }

        return iterations;

}

void main()
{
    
    int iterations = mandelbrot(uv  * 4.0 - 2.0 );

    float man_color = float(iterations) / 100.0;
    color = texture(texture0, uv) ; //* man_color;
}