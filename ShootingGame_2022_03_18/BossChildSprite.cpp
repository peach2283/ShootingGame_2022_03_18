#include "shootingGame.h"

BossChildSprite::BossChildSprite(string tag, string name, bool active, float px, float py)
				:Sprite(tag, name, active, px, py)
{
	this->hp = 100;
}

BossChildSprite::~BossChildSprite()
{}

void BossChildSprite::Update()
{}

void BossChildSprite::Explosion()
{
	//������..����ȿ��//
	float px = GetPx();
	float py = GetPy();

	Instantiate(new BossChildExp(px - 17, py - 30));

	//������..����//
	Destroy(this);
}

void BossChildSprite::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "������")
	{
		//ü�� ���̱�//
		hp = hp - 10;

		if (hp <= 0)
		{
			Explosion();
		}
	}
	else if (tag == "��ź����")
	{
		Explosion();
	}
}