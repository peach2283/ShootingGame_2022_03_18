#include "ShootingGame.h"

Gun::Gun(float px, float py, string name) : BossChildSprite("보스자식", name , true, px, py)
{}

Gun::~Gun()
{}

void Gun::Start()
{
	SetSprite("Asset/보스.bmp", 426, 315, 20, 25);
	AddBoxCollider2D(2, 2, 14, 14);
}

void Gun::Update()
{
}

void Gun::OnFire()
{
	float px = GetPx();
	float py = GetPy();

	BossBullet* bullet = (BossBullet*)Instantiate(new BossBullet(px, py + 20));
	bullet->SetAngle(90);
}