#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 650), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	sf::Texture texture;
	if(!texture.loadFromFile("ada_lovelace.jpg", sf::IntRect(0, 0, 100, 150))) {
		cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	}

	sf::Sprite sprite1;
	sprite1.setTexture(texture);

	sf::Sprite sprite2;
	sprite2.setTexture(texture);
	sf::Sprite sprite3;
	sprite3.setTexture(texture);
	sf::Sprite sprite4;
	sprite4.setTexture(texture);
	sf::Sprite sprite5;
	sprite5.setTexture(texture);

	sf::Sprite sprite6;
	sprite6.setTexture(texture);
	sf::Sprite sprite7;
	sprite7.setTexture(texture);
	sf::Sprite sprite8;
	sprite8.setTexture(texture);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

			window.clear();
			//window.draw(shape);
			window.draw(sprite1);
			//sprite.setTextureRect(sf::IntRect(10,10,32,32));
			sprite1.setPosition(sf::Vector2f(10.f, 10.f));
			window.draw(sprite2);
			sprite2.setPosition(sf::Vector2f(130.f, 10.f));
			window.draw(sprite3);
			sprite3.setPosition(sf::Vector2f(250.f, 10.f));
			window.draw(sprite4);
			sprite4.setPosition(sf::Vector2f(370.f, 10.f));
			
			//vertical
			window.draw(sprite5);
			sprite5.setPosition(sf::Vector2f(10.f, 170.f));
			window.draw(sprite6);
			sprite6.setPosition(sf::Vector2f(10.f, 330.f));
			window.draw(sprite7);
			sprite7.setPosition(sf::Vector2f(10.f, 490.f));
			window.display();
	}
	return 0;
}
