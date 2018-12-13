#include "MovingObject.h"

MovingObject::MovingObject(Game& game, sf::Vector2f& velocity)
	: Entity { game }, velocity {velocity}
{

}