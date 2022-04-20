#include "ShootingGame.h"

Cannon::Cannon(float px, float py) : Sprite("대포","", true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::Start()
{
	SetSprite("Asset/보스.bmp", 357, 262, 21, 22);
	AddBoxCollider2D(5, 0, 11, 22);
}

void Cannon::Update()
{}

void Cannon::Explosion()
{
	//날개가..폭발효과//
	float px = GetPx();
	float py = GetPy();

	Instantiate(new BossChildExp(px - 17, py - 30));

	//날개가..제거//
	Destroy(this);
}

void Cannon::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "레이저")
	{
		hp = hp - 10;

		if (hp <= 0)
		{
			Explosion();
		}

	}
	else if (tag == "폭발효과")
	{
		Explosion();
	}
}
