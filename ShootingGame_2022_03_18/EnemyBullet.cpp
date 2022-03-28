#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 150;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::Start()
{
	SetSprite("Asset/ÃÑ¾Ë1.bmp");
}

void EnemyBullet::Update()
{
	Translate(0, speed * Time::deltaTime);
}
