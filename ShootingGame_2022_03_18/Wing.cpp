#include "ShootingGame.h"

Wing::Wing(float px, float py, int idx) : Sprite("날개","",true, px, py)
{
	this->idx = idx;
	this->hp  = 100;
}

Wing::~Wing()
{}

void Wing::Start()
{
	SetSprite("Asset/보스.bmp", rect[idx][0], rect[idx][1], rect[idx][2], rect[idx][3]);
	AddBoxCollider2D(0, 0, rect[idx][2], rect[idx][3]);
}

void Wing::Update()
{}

void Wing::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "레이저")
	{
		//체력 줄이기//
		hp = hp - 10;

		if (hp <= 0)
		{
			//날개가..폭발효과//
			float px = GetPx();
			float py = GetPy();
			
			Instantiate(new BossChildExp(px-17, py-30));

			//날개가..제거//
			Destroy(this);
		}
	}
}