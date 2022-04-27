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

void Gun::Update()
{
	float px = GetPx();
	float py = GetPy();

	BossBullet * bullet=(BossBullet*)Instantiate(new BossBullet(px, py+20));
	bullet->SetAngle(90);
}