#include "ShootingGame.h"

Gun::Gun(float px, float py) : BossChildSprite("�����ڽ�","��", true, px, py)
{}

Gun::~Gun()
{}

void Gun::Start()
{
	SetSprite("Asset/����.bmp", 426, 315, 20, 25);
	AddBoxCollider2D(2, 2, 14, 14);
}