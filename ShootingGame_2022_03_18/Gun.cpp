#include "ShootingGame.h"

Gun::Gun(float px, float py) : Sprite("","", true, px, py)
{}

Gun::~Gun()
{}

void Gun::Start()
{
	SetSprite("Asset/º¸½º.bmp", 426, 315, 20, 25);
}

void Gun::Update()
{}
