#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("적기총알","", true, px, py)
{
	this->speed    = 150;
	this->lifeTime = 10;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::Start()
{
	SetSprite("Asset/총알1.bmp");
	AddBoxCollider2D(0, 0, 17, 15);
}

void EnemyBullet::Update()
{
	//이동하기
	Translate(0, speed * Time::deltaTime);

	//라이프타임 측정
	lifeTime -= Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}
