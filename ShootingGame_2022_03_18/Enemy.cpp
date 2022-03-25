#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("","", true, px, py)
{
	this->speed = 200;
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	/////////���ؾ��� ���� �̹�����//////////////////////////
	AddSprite("Asset/����.bmp", 200 * 0 + 1, 281, 190, 137,     0);
	AddSprite("Asset/����.bmp", 200 * 1 + 1, 281, 190, 137,     0);

	////////�߰����� ���� �̹�����//////////////////////////
	AddSprite("Asset/����.bmp", 200 * 0 + 1, 141, 190, 137,     1);
	AddSprite("Asset/����.bmp", 200 * 1 + 1, 141, 190, 137,     1);
	AddSprite("Asset/����.bmp", 200 * 2 + 1, 141, 190, 137,     1);
	AddSprite("Asset/����.bmp", 200 * 3 + 1, 141, 190, 137,     1);

	////////�������� ���� �̹�����//////////////////////////
	AddSprite("Asset/����.bmp", 200 * 0 + 1,   1, 190, 137,     2);
	AddSprite("Asset/����.bmp", 200 * 1 + 1,   1, 190, 137,     2);
	AddSprite("Asset/����.bmp", 200 * 2 + 1,   1, 190, 137,     2);
	AddSprite("Asset/����.bmp", 200 * 3 + 1,   1, 190, 137,     2);
}

void Enemy::Update()
{
	//���� �̵��ϱ�//
}
