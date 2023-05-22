module;

#include <dwmapi.h>

export module CCat : Window;

import <SFML/Graphics.hpp>;

namespace CCat {

	export const sf::Color backgroundColor{ 30, 30, 30 };

	export auto setWindowProperties(sf::RenderWindow& window) {

		auto videoMode = sf::VideoMode::getDesktopMode();
		videoMode.width *= 0.75;
		videoMode.height *= 0.75;

		window.create({ videoMode.width, videoMode.height }, "CCat");

		auto handle = static_cast<HWND>(window.getSystemHandle());

		auto setDarkMode = TRUE;
		::DwmSetWindowAttribute(handle, DWMWA_USE_IMMERSIVE_DARK_MODE, &setDarkMode, sizeof(setDarkMode));

		::ShowWindow(handle, SW_MAXIMIZE);
	}
}