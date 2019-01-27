#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

class Player;
class Scene;
class PhysicsComponent
{
public:
	virtual ~PhysicsComponent() {};
	virtual void Update(Scene& scene, Player& player, double deltaTime) = 0;

};

#endif