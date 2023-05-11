module;

#include <iostream>
#include <SFML/Graphics>

export module CCat : Button;

namespace CCat {
    export class Button {
    public:
        Button(sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f size) : window(window) {
            // set the pos of the Button
            // set the size of the Button
        }
        
        void setLabel(std::string text, sf::Font& font, sf::Color& color, unsigned int characterSize = 30) {
            // Set text
            // Set font
            // Set Color
             // Set characterSize
             // Set Position to the center of the Button
        } 
        
        void onEvent(sf::Event& event) {
            if (event.type == sf::Event::MouseMoved)
                onMouseMovedEvent(event);
        }
        
        void draw() {
            button.draw(window);
            label.draw(window);
        }
        
        void defaultColor(sf::Color& fillColor, sf::Color& outlineColor) {
            // set
        }
    
    private:
        sf::RenderWindow& window;
        sf::Rectangle button;
        sf::Text label;
        
        void onMouseMovedEvent(sf::Event& event) {
            // if button contains mousePos:
                // 
        }
  }
}
