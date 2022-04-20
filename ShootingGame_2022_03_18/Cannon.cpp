#include "ShootingGame.h"

Cannon::Cannon(float px, float py) : Sprite("����","", true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::Start()
{
	SetSprite("Asset/����.bmp", 357, 262, 21, 22);
	AddBoxCollider2D(5, 0, 11, 22);
}

void Cannon::Update()
{}

void Cannon::Explosion()
{
	//������..����ȿ��//
	float px = GetPx();
	float py = GetPy();

	Instantiate(new BossChildExp(px - 17, py - 30));

	//������..����//
	Destroy(this);
}

void Cannon::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "������")
	{
		hp = hp - 10;

		if (hp <= 0)
		{
			Explosion();
		}

	}
	else if (tag == "����ȿ��")
	{
		Explosion();
	}
}
