
// # #################################
// # @Author: Estenio Garcia
// # 
// # Data of Creation: 04/26/2021
// # 
// # License: MIT
// # 
// # #################################
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "../includes/Blocks.hpp"

Blocks::Blocks( Player* player,float px, float py){

	this->player = player;

	this->posx = px;
	this->posy = py;

	this->scale = 1.f;

	this->texture.loadFromFile("./assets/block.jpg");

	this->sprite.setTexture(texture);

	this->sprite.setPosition(this->posx, this->posy);

	sf::Vector2u size = this->texture.getSize();

	this->width = size.x * this->scale;
	this->height = size.y * this->scale;

	font.loadFromFile("./assets/SuperMario256.ttf");
	displayStatus.setFont(font);
	displayStatus.setFillColor(sf::Color::White);
	displayStatus.setCharacterSize(14);
	displayStatus.setString("No Colliding...");
	displayStatus.setPosition(this->posx, this->posy + this->height + 30);
}

void Blocks::Update(){

	// # Calculate distance to player
	// # if player is near, collision will be enable

	startpoint.x = this->posx + abs( this->width / 2 );
	startpoint.y = this->posy + abs( this->height / 2 );

	endpoint.x = player->posx + abs( player->width / 2 );
	endpoint.y = player->posy + abs( player->height / 2 );

	vet[ 0 ].position = startpoint;
	vet[ 1 ].position = endpoint;

	distance = sqrt( pow( (endpoint.x - startpoint.x), 2 ) + pow( (endpoint.y - startpoint.y), 2) );

	if( distance <= 300 ){
		nearToPlayer = true;
		vet[ 0 ].color = sf::Color::Red;
		vet[ 1 ].color = sf::Color::Red;

		displayStatus.setFillColor(sf::Color::Yellow);
		displayStatus.setString("Player is Near...");
	}else{
		nearToPlayer = false;
		vet[ 0 ].color = sf::Color::Green;
		vet[ 1 ].color = sf::Color::Green;

		displayStatus.setFillColor(sf::Color::Green);
		displayStatus.setString("Collision disable!!!");
	}


	if(nearToPlayer == true){

		if(player->posx < this->posx + this->width &&
		   player->posx + player->width > this->posx && 
		   player->posy < this->posy + this->height &&
		   player->posy + player->height > this->posy ){


			displayStatus.setFillColor(sf::Color::Red);
			displayStatus.setString("Colliding on player!");
			
		}
	}
}

sf::Sprite* Blocks::getSprite(){
	return &this->sprite;
}