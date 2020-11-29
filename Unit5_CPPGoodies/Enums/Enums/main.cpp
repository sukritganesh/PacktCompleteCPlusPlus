#include <iostream>

enum class Color { RED, GREEN, BLUE };

void FillColor(Color color) {
	// Fill background with some color
	if (color == Color::RED) {
		std::cout << "RED" << std::endl;
	} else if (color == Color::GREEN) {
		std::cout << "GREEN" << std::endl;
	} else if (color == Color::BLUE) {
		std::cout << "BLUE" << std::endl;
	}
}

enum class TrafficLight: char {RED = 'd', GREEN, YELLOW};

int main() {
	Color c = Color::RED;
	FillColor(Color::RED);
	FillColor(Color::GREEN);
	FillColor(static_cast<Color>(2));
	char x = static_cast<char>(TrafficLight::YELLOW);
	std::cout << x << std::endl;
	return 0;
}