#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("","", true, px, py)
{
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	/////////���ؾ��� ���� �̹�����//////////////////////////
	//AddSprite("Asset/����.bmp", 200 * 0 + 1, 281, 190, 137);
	//AddSprite("Asset/����.bmp", 200 * 1 + 1, 281, 190, 137);

	////////�߰����� ���� �̹�����//////////////////////////
	AddSprite("Asset/����.bmp", 200 * 0 + 1, 141, 190, 137);
	AddSprite("Asset/����.bmp", 200 * 1 + 1, 141, 190, 137);
	AddSprite("Asset/����.bmp", 200 * 2 + 1, 141, 190, 137);
	AddSprite("Asset/����.bmp", 200 * 3 + 1, 141, 190, 137);
}

void Enemy::Update()
{
}
