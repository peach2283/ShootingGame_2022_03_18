#include "ShootingGame.h"

PlayerExp::PlayerExp(float px, float py) : Animation("", "", true, px, py)
{}

PlayerExp::~PlayerExp()
{}

void PlayerExp::Start()
{
	for (int y = 0; y < 1; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			AddSprite("Asset/폭발효과.bmp", 0 + x * 225, 5553 + y * 321, 224, 320, 0);
		}
	}

	//애니메이션 속도 조절//
	Speed(1);
}

void PlayerExp::Update()
{}

void PlayerExp::OnAnimationEnd()
{
	Destroy(this);
}
