#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 150;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::Start()
{
	SetSprite("Asset/�Ѿ�1.bmp");
}

void EnemyBullet::Update()
{
	Translate(0, speed * Time::deltaTime);
}
