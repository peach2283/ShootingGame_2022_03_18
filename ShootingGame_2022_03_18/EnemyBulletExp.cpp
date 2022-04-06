#include "ShootingGame.h"

EnemyBulletExp::EnemyBulletExp(float px, float py) : Animation("","", true, px, py)
{}

EnemyBulletExp::~EnemyBulletExp()
{}

void EnemyBulletExp::Start()
{
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			AddSprite("Asset/ÃÑ¾ËÆø¹ß.bmp", col * 40, row * 40, 40, 40, 0);
		}
	}

	for (int col = 0; col < 2; col++)
	{
		AddSprite("Asset/ÃÑ¾ËÆø¹ß.bmp", col * 40, 2 * 40, 40, 40, 0);
	}

	Speed(1.5);
}

void EnemyBulletExp::Update()
{}

void EnemyBulletExp::OnAnimationEnd()
{
	Destroy(this);
}