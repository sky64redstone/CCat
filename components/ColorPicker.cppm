module;

#include <iostream>
#include <SFML/Graphics.hpp>

export module CCat : ColorPicker;

namespace CCat {
    export class ColorPicker {
    public:
        ColorPicker(sf::RenderWindow& window, sf::Vector2f pos, int pixelSize = 1) : window(window), pos(pos), pixelSize(pixelSize) {
            
        }
        
        void draw() {
            if (pixelSize == 1) {
                for (auto y = 0; y < 256; y++) {
                    for (auto x = 0; x < 256; x++) {
                        sf::Vertex point(sf::Vector2f(x + pos.x, y + pos.y), sf::Color(x, y, blue));
                        window.draw(&point, 1, sf::Points);
                    }
                }
            } else if (pixelSize > 1) {
                for (auto y = 0; y < 256; y++) {
                    for (auto x = 0; x < 256; x++) {
                        sf::RectangleShape point({ x + pos.x, y + pos.y }, { pixelSize, pixelSize });
                        point.setFillColor(sf::Color(x, y, blue));
                        window.draw(point);
                    }
                }
            } else {
                std::cout << "Error found: Wrong pixelSize[1-...]! pixelSize = " << pixelSize;
            }
        }
        
        void onEvent(sf::Event event) {
            if (event.type == sf::Event::MouseMoved)
                onMouseMoveEvent(event);
            else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
                onMouseButtonEvent(event);
        }
    private:
        sf::RenderWindow& window;
        sf::Vector2f pos;
        int pixelSize;
        int lastRGB;
        int blue;
        
        void onMouseMoveEvent(sf::Event event) {
            
        }
        
        void onMouseButtonEvent(sf::Event event) {
            
        }
    }
}
