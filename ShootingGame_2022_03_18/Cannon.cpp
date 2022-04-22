#include "ShootingGame.h"

Cannon::Cannon(float px, float py) : BossChildSprite("보스자식","대포", true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::Start()
{
	SetSprite("Asset/보스.bmp", 357, 262, 21, 22);
	AddBoxCollider2D(5, 0, 11, 22);

	SetDamage(20);  //피해량 지정하기
}