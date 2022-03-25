#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("","", true, px, py)
{
	this->speed = 200;
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	/////////피해없는 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1, 281, 190, 137,     0);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1, 281, 190, 137,     0);

	////////중간피해 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 2 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 3 + 1, 141, 190, 137,     1);

	////////많은피해 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 2 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 3 + 1,   1, 190, 137,     2);
}

void Enemy::Update()
{
	//적기 이동하기//
}
