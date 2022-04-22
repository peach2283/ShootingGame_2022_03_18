#include "ShootingGame.h"

Cannon::Cannon(float px, float py) : BossChildSprite("�����ڽ�","����", true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::Start()
{
	SetSprite("Asset/����.bmp", 357, 262, 21, 22);
	AddBoxCollider2D(5, 0, 11, 22);

	SetDamage(20);  //���ط� �����ϱ�
}