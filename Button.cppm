module;

#include <iostream>

export module CCat : Button;

import <SFML/Graphics.hpp>;

namespace CCat {
	export class Button {
	public:
		Button(sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f size) : window(window), pos(pos), size(size) {
			button = sf::RectangleShape(size);
			button.setPosition(pos);
		}

		void setDefaultColor(sf::Color color) {
			defaultColor = color;
		}

		void setHoverColor(sf::Color color, bool onlyOutline = true) {
			hoverColor = color;
			hoverOutline = onlyOutline;
		}

		void setClickColor(sf::Color color) {
			clickColor = color;
		}

		void draw() {
			window.draw(button);
		}

		void onEvent(sf::Event event) {
			if (event.type == sf::Event::MouseMoved) {
				sf::Vector2f mousePos(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));
				if (button.getGlobalBounds().contains(mousePos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						button.setOutlineColor(clickColor);
						button.setFillColor(clickColor);
						function("");
					}
					else {
						if (hoverOutline) {
							button.setOutlineColor(hoverColor);
							button.setFillColor(defaultColor);
						}
						else {
							button.setFillColor(hoverColor);
						}
					}
				}
				else {
					button.setOutlineColor(defaultColor);
					button.setFillColor(defaultColor);
				}
			}
		}
		
		void addFunction(std::function<void(std::string)> action) {
			function = action;
		}	
	private:
		sf::RenderWindow& window;
		sf::RectangleShape button;
		sf::Vector2f pos; 
		sf::Vector2f size;
		sf::Color defaultColor;
		sf::Color hoverColor;
		sf::Color clickColor;
		std::function<void(std::string)> function; // TODO: give some better parameters
		bool hoverOutline;
	};

	// Like in VS the buttons "File", "Edit", "View", ...
	export class MenuButton {
		
	};

	// Like in VS the buttons in "File" -> "Clone Repository...", "Start Window", ...
	export class MenuItem {

	};

	// Like in VS the buttons in "File" -> "New   >", "Open   >", ...
	export class MenuItemList {

	};
}
