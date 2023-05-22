module;

#include <winrt/Windows.Storage.h>
#include <SFML/Graphics.hpp>
#include <iostream>

export module CCat;

import :TextBox;
import :Window;
import :Button;

namespace CCat {

	export auto Run() {

		auto font = sf::Font();
		font.loadFromFile(winrt::to_string(winrt::Windows::Storage::SystemDataPaths::GetDefault().Fonts()) + "/Segoeui.ttf");
		
		auto window = sf::RenderWindow();
		setWindowProperties(window);

		auto event = sf::Event();

		// TextBox
		auto textBox = TextBox(window, "", font);
		textBox.setFillColor(sf::Color::White);
		textBox.setLineSpacing(0.7f);
		textBox.setBounds({0, 0}, {500, 500});
		textBox.setBackgroundColor(sf::Color(10, 10, 10));

		// Button
		auto button = Button(window, { 600, 500 }, { 100, 20 });
		button.setLabel("Label", font, sf::Color::White, 20);

		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed:

					window.close();

					break;
				case sf::Event::Resized:

					window.setView(sf::View(sf::FloatRect(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));//38,35

					break;
				default:

					textBox.onEvent(event);
					button.onEvent(event);

					break;
				}
			}

			window.clear(backgroundColor);

			textBox.draw();
			button.draw();

			window.display();
		};
	}
}