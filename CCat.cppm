module;

#include <winrt/Windows.Storage.h>
#include <SFML/Graphics.hpp>
#include <iostream>

export module CCat;

import :TextBox;
import :Window;

namespace CCat {

	export auto Run() {

		auto font = sf::Font();
		font.loadFromFile(winrt::to_string(winrt::Windows::Storage::SystemDataPaths::GetDefault().Fonts()) + "/Segoeui.ttf");
		
		auto window = sf::RenderWindow();
		setWindowProperties(window);

		auto event = sf::Event();

		auto textBox = TextBox(window, "", font);
		textBox.setFillColor(sf::Color::White);
		textBox.setLineSpacing(0.7f);

		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed:

					window.close();

					break;
				case sf::Event::Resized:

					window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));//38,35

					break;
				default:

					textBox.onEvent(event);

					break;
				}
			}

			window.clear(backgroundColor);
			textBox.draw();
			window.display();
		};
	}
}