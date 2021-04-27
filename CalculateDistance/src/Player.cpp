// # #################################
// # @Author: Estenio Garcia
// # 
// # Data of Creation: 04/26/2021
// # 
// # License: MIT
// # 
// # #################################

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../includes/Player.hpp"

Player::Player(bool* KeyEvent){

	this->getKeyEvent = KeyEvent;

	this->posx = 50;
	this->posy = 250;

	this->scale = 1.f;

	this->speedX = 0;
	this->speedY = 0;
	this->speed  = 3.0f;

	this->texture.loadFromFile("./assets/player.jpg");
	this->sprite.setTexture(this->texture);

	sf::Vector2u size = this->texture.getSize();

	this->width = size.x;//* scale;
	this->height = size.y;// * scale;
}

sf::Sprite* Player::getSprite(){
	return &this->sprite;
}

void Player::Update(){


	if(this->getKeyEvent[ 0 ] == true && keyLocked[ 0 ] == false)
		this->speedY = -this->speed;
	if(this->getKeyEvent[ 1 ] == true && keyLocked[ 1 ] == false)
		this->speedY = this->speed;
	if(this->getKeyEvent[ 2 ] == true && keyLocked[ 2 ] == false)
		this->speedX = -this->speed;
	if(this->getKeyEvent[ 3 ] == true && keyLocked[ 3 ] == false)
		this->speedX = this->speed;

	this->posx += this->speedX;
	this->posy += this->speedY;

	this->sprite.setPosition(this->posx, this->posy);

	if(this->getKeyEvent[ 0 ] == false)
		this->speedY = 0;
	if(this->getKeyEvent[ 1 ] == false)
		this->speedY = 0;
	if(this->getKeyEvent[ 2 ] == false)
		this->speedX = 0;
	if(this->getKeyEvent[ 3 ] == false)
		this->speedX = 0;
}