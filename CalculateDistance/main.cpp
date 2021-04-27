
// # #################################
// # @Author: Estenio Garcia
// # 
// # Data of Creation: 04/26/2021
// # 
// # License: MIT
// # 
// # #################################

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "./includes/Player.hpp"
#include "./includes/Blocks.hpp"

int main(){


	sf::RenderWindow window(sf::VideoMode(900, 700), "Calculate Distance Collision - By Estenio Garcia",sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	// # System Variables
	sf::Clock clock;
	sf::Text displayTextDistance;
	sf::Font font;
	float deltaTime;

	// # Universal Variables
	static bool Key[4];

	// # Instances
	Player* player = new Player(Key);
	Blocks* block = new Blocks(player, 250, 250);
	Blocks* block2 = new Blocks(player, 650, 350);
	Blocks* block3 = new Blocks(player, 150, 450);

	font.loadFromFile("./assets/SuperMario256.ttf");
	displayTextDistance.setFont(font);
	displayTextDistance.setFillColor(sf::Color::Cyan);
	displayTextDistance.setCharacterSize(14);
	displayTextDistance.setPosition(10,20);

	while(window.isOpen()){

		sf::Event event;

		while(window.pollEvent(event)){

			if(event.type == sf::Event::Closed)
				window.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			Key[ 0 ] = true;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			Key[ 1 ] = true;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			Key[ 2 ] = true;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			Key[ 3 ] = true;

		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			Key[ 0 ] = false;
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			Key[ 1 ] = false;
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			Key[ 2 ] = false;
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			Key[ 3 ] = false;


		// # Update Methods
		player->Update();
		block->Update();
		block2->Update();
		block3->Update();

		displayTextDistance.setString("deltaTime: " + std::to_string(deltaTime * 1000.f));

		// # Draw Methods
		window.clear();

		window.draw(*block->getSprite());
		window.draw(*block2->getSprite());
		window.draw(*block3->getSprite());
		window.draw(*player->getSprite());

		window.draw(block->vet, (size_t) 2, sf::Lines);
		window.draw(block->displayStatus);

		window.draw(block2->vet, (size_t) 2, sf::Lines);
		window.draw(block2->displayStatus);

		window.draw(block3->vet, (size_t) 2, sf::Lines);
		window.draw(block3->displayStatus);

		window.draw(displayTextDistance);

		window.display();

		// # Function deltaTime counter
		deltaTime = clock.getElapsedTime().asSeconds();

		clock.restart().asSeconds();
	}


	return 0;
}