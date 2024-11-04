#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

    // Dimensiones de la imagen
    const int width = 800;
    const int height = 600;
    
    std::vector<uint8_t> pixels;

void pinta(int x, int y, uint32_t color)
{
    int index = (y * width + x) * 4;
    pixels[index + 0] = (color >> 24) & 0xFF;
    pixels[index + 1] = (color >> 16) & 0xFF;
    pixels[index + 2] = (color >> 8) & 0xFF;
    pixels[index + 3] = color & 0xFF;
}

void initPixels(uint32_t color)
{

pixels.reserve(width * height * 4);
std::cout << "Inicializando" << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
           // uint32_t pixel = image[y][x];
            uint32_t pixel = color;
            int index = (y * width + x) * 4;
            pixels[index + 0] = (pixel >> 24) & 0xFF; // R
            pixels[index + 1] = (pixel >> 16) & 0xFF; // G
            pixels[index + 2] = (pixel >> 8) & 0xFF;  // B
            pixels[index + 3] = pixel & 0xFF;         // A
        }
    }

}

int main() {

    initPixels(0x000000FF);
    // Crear una textura y un sprite para mostrar la imagen
    sf::Texture texture;
    texture.create(width, height);

    std::cout << "Pintando pixeles" << std::endl;
    pinta(300,300,0xFF0000FF);
    pinta(500,300,0x00FF00FF);
    pinta(300,500,0x00FFFF);
    pinta(700,300,0xFF00FFFF);



    std::cout << "Cargar los píxeles en la textura" << std::endl;
    texture.update(pixels.data());

    std::cout << "Crear un sprite para mostrar la textura" << std::endl;
    sf::Sprite sprite(texture);

    std::cout << "Crear una ventana" << std::endl;
    sf::RenderWindow window(sf::VideoMode(width, height), "Display Image from Array");

    // Bucle principal de la ventana
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
