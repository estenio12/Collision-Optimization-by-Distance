
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

class Object2D{

public:
	float posx, posy, width, height;
	float speedX, speedY, speed;
	float scale;

	sf::Texture texture;
	sf::Sprite sprite;

	virtual void Update() = 0;
	virtual sf::Sprite* getSprite() = 0;
};