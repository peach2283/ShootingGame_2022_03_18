#include "ShootingGame.h"

BombExp::BombExp(float px, float py) : Animation("","", true, px, py)
{}

BombExp::~BombExp()
{}

void BombExp::Start()
{
	for (int r = 0; r < 2; r++)  //row
	{
		for (int c = 0; c < 6; c++) //column
		{
			AddSprite("Asset/��ź����.bmp", c * 130, r * 130, 128, 128, 0);
		}
	}
}

void BombExp::Update()
{}