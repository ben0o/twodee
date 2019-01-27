#include "player.hpp"
#include "../scene.hpp"

Player::Player(InputComponent* input, GraphicsComponent* graphics, PhysicsComponent* physics, glm::vec2 position) : pInput(input), pGraphics(graphics), pPhysics(physics)
{
	// Default constructor.
	
	currentPos = position;

	size.x = 30;// spriteImgCoords.w;
	size.y = 48;// spriteImgCoords.h;
	
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	
	newPosition.x = currentPos.x;
	newPosition.y = currentPos.y;
}
Player::~Player()
{
	// Destructor
}

glm::vec2 Player::GetPosition()
{
	return currentPos;
}

glm::vec2 Player::GetNewPosition()
{
	return newPosition;
}

glm::vec2 Player::GetCenter()
{
	return glm::vec2((currentPos.x + (size.x / 2)), currentPos.y + (size.y / 2));
}

glm::vec2 Player::GetVelocity()
{
	return velocity;
}

glm::vec2 Player::GetSize()
{
	return size;
}

void Player::SetPosition(glm::vec2 p)
{
	currentPos = p;
}

void Player::SetNewPosition(glm::vec2 pn)
{
	newPosition = pn;
}

void Player::SetVelocity(glm::vec2 v)
{
	velocity = v;
}

void Player::LoadSprite(SDL_Renderer* p_renderer, std::string imagePath)
{
	pGraphics->LoadSprite(p_renderer, imagePath);
}

void Player::Input(SDL_Event &event)
{
	pInput->Input(event, *this);
}

void Player::Update(Scene* currScene, double deltaTime)
{
	pInput->Update(*this);
	pPhysics->Update(*currScene, *this, deltaTime);
}

void Player::Draw(SDL_Renderer* p_renderer, Scene& scene)
{
	pGraphics->Draw(p_renderer, *this, scene);

} 