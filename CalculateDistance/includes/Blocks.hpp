
// # #################################
// # @Author: Estenio Garcia
// # 
// # Data of Creation: 04/26/2021
// # 
// # License: MIT
// # 
// # #################################
#pragma once 

#include <SFML/Graphics.hpp>

#include "../includes/Object2D.hpp"
#include "../includes/Player.hpp"

class Blocks : public Object2D{

public:
	Player* player;
	sf::Vector2f startpoint;
	sf::Vector2f endpoint;

	sf::Vertex vet[2];

	bool nearToPlayer = false;
	float distance = 0.f;

	sf::Font font;
	sf::Text displayStatus;

	explicit Blocks(Player* player, float px, float py);

	void Update() override;

	sf::Sprite* getSprite() override;
};