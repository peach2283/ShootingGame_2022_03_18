#include "ShootingGame.h"

Radar::Radar(float px, float py) : BossChildSprite("�����ڽ�","���̴�", true, px, py)
{}

Radar::~Radar()
{}

void Radar::Start()
{
	SetSprite("Asset/����.bmp", 360, 245, 11, 9);
	AddBoxCollider2D(0, 0, 11, 9);
}