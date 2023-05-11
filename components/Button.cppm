module;

#include <iostream>
#include <SFML/Graphics.hpp>

export module CCat : Button;

namespace CCat {

    export class Button {
    public:
        Button(sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f size, float outlineThickness = 1) : window(window) {
            // set the pos of the Button
            button.setPosition(pos);
            // set the size of the Button
            button.setSize(size);
            // default Button styles
            defaultFillColor = sf::Color::Transparent;
            defaultOutlineColor = sf::Color::Transparent;
            hoverFillColor = sf::Color(60, 60, 60);
            hoverOutlineColor = sf::Color::White;
            clickFillColor = sf::Color(60, 60, 60);
            clickOutlineColor = sf::Color::White;
            // outline thickness
            button.setOutlineThickness(outlineThickness);
        }
        
        void setLabel(std::string text, sf::Font& font, const sf::Color& color, unsigned int characterSize = 30) {
            // Set text
            label.setString(text); // no returns in the text!!!!
            // Set font
            label.setFont(font);
            // Set Color
            label.setFillColor(color);
            // Set characterSize
            label.setCharacterSize(characterSize);
            // TODO Set Position to the center of the Button
            float x = button.getSize().x / 2 - text.length() * characterSize / 2 + button.getPosition().x;
            float y = button.getSize().y / 2 - characterSize / 2 + button.getPosition().y;

            label.setPosition(x, y);
        }

        void onEvent(sf::Event& event) {
            if (event.type == sf::Event::MouseMoved)
                onMouseMovedEvent(event);
            else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
                onMouseButtonEvent(event);
        }

        void draw() {
            window.draw(button);
            window.draw(label);
        }

        void defaultColor(sf::Color& fillColor, sf::Color& outlineColor) {
            // Set defaultFillColor
            // Set defaultOutlineColor
            defaultFillColor = fillColor;
            defaultOutlineColor = outlineColor;
        }
        
        void hoverColor(sf::Color& fillColor, sf::Color& outlineColor) {
            // Set hoverFillColor
            // Set hoverOutlineColor
            hoverFillColor = fillColor;
            hoverOutlineColor = outlineColor;
        }

        void clickColor(sf::Color& fillColor, sf::Color& outlineColor) {
            // Set clickFillColor
            // Set clickOutlineColor
            clickFillColor = fillColor;
            clickOutlineColor = outlineColor;
        }

    private:
        sf::RenderWindow& window;
        sf::RectangleShape button;
        sf::Text label;

        sf::Color defaultFillColor;
        sf::Color defaultOutlineColor;

        sf::Color hoverFillColor;
        sf::Color hoverOutlineColor;

        sf::Color clickFillColor;
        sf::Color clickOutlineColor;

        void onMouseMovedEvent(sf::Event& event) {
            sf::Vector2f pos(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));
            if (button.getGlobalBounds().contains(pos)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    button.setFillColor(clickFillColor);
                    button.setOutlineColor(clickOutlineColor);
                    // TODO std::function action();
                    std::cout << "Click\n";
                }
                else {
                    button.setFillColor(hoverFillColor);
                    button.setOutlineColor(hoverOutlineColor);
                }
            }
            else {
                button.setFillColor(defaultFillColor);
                button.setOutlineColor(defaultOutlineColor);
            }
        }

        void onMouseButtonEvent(sf::Event& event) {
            sf::Vector2f pos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
            if (button.getGlobalBounds().contains(pos)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    button.setFillColor(clickFillColor);
                    button.setOutlineColor(clickOutlineColor);
                    // TODO std::function action();
                    std::cout << "Click\n";
                }
                else {
                    button.setFillColor(hoverFillColor);
                    button.setOutlineColor(hoverOutlineColor);
                }
            }
            else {
                button.setFillColor(defaultFillColor);
                button.setOutlineColor(defaultOutlineColor);
            }
        }
    };
}
