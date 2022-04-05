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
}

void EnemyBulletExp::Update()
{}
