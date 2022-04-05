#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("Àû±âÃÑ¾Ë","", true, px, py)
{
	this->speed = 150;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::Start()
{
	SetSprite("Asset/ÃÑ¾Ë1.bmp");
	AddBoxCollider2D(0, 0, 17, 15);
}

void EnemyBullet::Update()
{
	Translate(0, speed * Time::deltaTime);
}
