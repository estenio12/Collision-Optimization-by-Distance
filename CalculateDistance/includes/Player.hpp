
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

class Player : public Object2D{

public:
	bool* getKeyEvent;

	bool keyLocked[4];

	explicit Player(bool* KeyEvent);
	~Player();

	void Update() override;

	sf::Sprite* getSprite() override;

};