#ifndef PLAYERPHYSICSCOMPONENT_H
#define PLAYERPHYSICSCOMPONENT_H

#include "PhysicsComponent.hpp"

class Player;
class Scene;
class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	void Update(Scene& scene, Player& player, double deltaTime);

};

#endif