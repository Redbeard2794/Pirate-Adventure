#ifndef PLAYER_H
#define PLAYER_H
class Player : public sf::Drawable, public sf::Transformable
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity;
	float speed;
	float maxSpeed;
	sf::Vector2f direction;
public:

	Player();
	~Player();

	void Update();
	void Move();
	void Turn(float a);
	void draw(sf::RenderTarget& window, sf::RenderStates state) const;
	void Player::draw(sf::RenderTarget& window);

	#pragma region Properties
	sf::Vector2f getVelocity(){ return velocity; }
	sf::Sprite getSprite(){ return sprite; }
	float getSpeed(){ return speed; }
	float getMaxSpeed(){ return maxSpeed; }
	sf::Vector2f getDirection(){ return direction; }

	void setVelocity(sf::Vector2f vel){ velocity = vel; }
	void setSpeed(float s){ speed = s; }
	#pragma endregion
};
#endif