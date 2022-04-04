#include "ShootingGame.h"

EnemyExp::EnemyExp(float px, float py) : Animation("", "", true, px, py)
{}

EnemyExp::~EnemyExp()
{}

void EnemyExp::Start()
{
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			AddSprite("Asset/폭발효과.bmp", 0+x*225, 5553 + y*321, 224, 320, 0);
		}
	}

	AddSprite("Asset/폭발효과.bmp", 0 + 0 * 225, 5553 + 2 * 321, 224, 320, 0);
	AddSprite("Asset/폭발효과.bmp", 0 + 1 * 225, 5553 + 2 * 321, 224, 320, 0);

	//애니메이션 속도 조절//
	Speed(2);
}

void EnemyExp::Update()
{
}

void EnemyExp::OnAnimationEnd()
{
	Destroy(this);
}
