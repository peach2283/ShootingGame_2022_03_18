#include "ShootingGame.h"

Radar::Radar(float px, float py) : BossChildSprite("보스자식","", true, px, py)
{}

Radar::~Radar()
{}

void Radar::Start()
{
	SetSprite("Asset/보스.bmp", 360, 245, 11, 9);
	AddBoxCollider2D(0, 0, 11, 9);
}