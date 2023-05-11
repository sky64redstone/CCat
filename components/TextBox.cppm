module;

#include <iostream>
#include <SFML/Graphics.hpp>

export module CCat : TextBox;

namespace CCat {

	export class TextBox {
	public:
		TextBox(sf::RenderWindow& window, const sf::String& string, const sf::Font& font, unsigned int characterSize = 30) : window(window), str(string) {
			text.setString(string);
			text.setFont(font);
			text.setCharacterSize(characterSize);
			mousePos = static_cast<int>(str.length());
			rect.setSize({ 1.0f, static_cast<float>(characterSize) });
			selected = false;
		}

		void setFillColor(sf::Color color) {
			text.setFillColor(color);
		}

		void setBackgroundColor(sf::Color color) {
			back.setFillColor(color);
		}

		void setOutlineColor(sf::Color color) {
			back.setOutlineColor(color);
		}

		void setLineSpacing(float spacing) {
			text.setLineSpacing(spacing);
		}

		void setBounds(sf::Vector2f pos, sf::Vector2f size) {
			text.setPosition(pos);
			back.setPosition(pos);
			back.setSize(size);
		}

		void onEvent(sf::Event event) {
			switch (event.type) {
			case sf::Event::TextEntered:

				textEvent(event);

				break;
			case sf::Event::KeyPressed:

				keyEvent(event);

				break;
			case sf::Event::MouseButtonPressed:

				mouseEvent(event);

				break;
			}
		}

		void draw() {
			// Draw Background
			window.draw(back);
			// Draw Text
			window.draw(text);
			// Draw Mouse
			if (selected && false) { // TODO remove false
				float x = text.findCharacterPos(mousePos).x - text.findCharacterPos(0).x;
				float y = text.findCharacterPos(mousePos).y - text.findCharacterPos(0).y;

				rect.setPosition({ x, y + 5 });

				window.draw(rect);
			}
		}

	private:
		sf::RenderWindow& window;
		sf::RectangleShape rect;
		sf::RectangleShape back;
		sf::Text text;
		std::string str;
		int mousePos;
		bool selected;

		void textEvent(sf::Event event) {
			if (selected && event.type == sf::Event::TextEntered) {
				switch (event.text.unicode) {
				case 8:
					removeLast();
					break;
				case 13:
					append('\n');
					break;
				default:
					append(event.text.unicode);
					break;
				}
			}
		}

		void keyEvent(sf::Event event) {
			// TODO mark with Shift (+ STRG) + Arrow
			if (selected && event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Up:
					// TODO
					break;
				case sf::Keyboard::Down:
					// TODO
					break;
				case sf::Keyboard::Left:
					// TODO str + left => one word left
					if (mousePos > 0)
						mousePos--;
					break;
				case sf::Keyboard::Right:
					// TODO str + right => one word right
					if (mousePos <= str.length())
						mousePos++;
					break;
				}
			}
		}

		void mouseEvent(sf::Event event) {
			// TODO mark Text
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left || event.mouseButton.button == sf::Mouse::Right) {
					sf::Vector2f pos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
					if (back.getGlobalBounds().contains(pos)) {
						selected = true;
						selectWithMouse(pos);
					}
					else {
						selected = false;
					}
				}
			}
		}

		void selectWithMouse(sf::Vector2f mPos) {
			// TODO set mousePos
		}

		void append(char c) {
			if (mousePos >= 0 && mousePos <= str.length()) {
				str.insert(mousePos, 1, c);
				text.setString(str);
				mousePos++;
			}
		}

		void removeLast() {
			if (str.length()) {
				mousePos--;
				str.erase(mousePos, 1);
				text.setString(str);
			}
		}
	};
}
