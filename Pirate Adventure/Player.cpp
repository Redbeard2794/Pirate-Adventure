#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	if (texture.loadFromFile("player.png")){}
	sprite.setTexture(texture);
		setPosition(sf::Vector2f(100, 100));
	setOrigin(sf::Vector2f(texture.getSize().x / 2, texture.getSize().y / 2));
	//setRotationValue(0.05);
	setSpeed(0);
	setVelocity(sf::Vector2f(1, 1));
	maxSpeed = 0.03f;
}

Player::~Player()
{
	//blank destructor for now
}

void Player::Update()
{
	Move();
	//Fire();
	//update the direction(maybe not everytime update is called)
	direction = sf::Vector2f(cos(getRotation()*(3.14/180.0)), sin(getRotation()*(3.14/180.0)));//Fucking cos and sin only take radians, problem solved
	direction /= std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
}

void Player::Move()//may or may not be needed. Could possibly deal with movement in update() only
{
	//detecting keyboard input for player to accelerate foward and then decelerate back to 0
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (getSpeed() < getMaxSpeed())
		{
			speed += 0.001;//fiddle with this number to change acceleration
		}
		
	}
	else
	{
		if (speed > 0)
			speed -= 0.000005;//fiddle with this number to change deceleration
		else if (speed < 0)
			speed = 0;
	}

	//For turning the ship
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Turn(-0.015);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Turn(0.015);
	}
	//update the position
	setPosition(getPosition() + (getDirection() * getSpeed()));

}//end Move()

void Player::Turn(float a)
{
	rotate(a);
}//end Rotate()

void Player::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
	
}//end Draw()

void Player::draw(sf::RenderTarget& window)
{

	window.draw(sprite, getTransform());

}