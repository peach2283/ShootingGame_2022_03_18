#include "ShootingGame.h"

Radar::Radar(float px, float py) : Sprite("","", true, px, py)
{}

Radar::~Radar()
{}

void Radar::Start()
{
	SetSprite("Asset/����.bmp", 360, 245, 11, 9);
}

void Radar::Update()
{}
