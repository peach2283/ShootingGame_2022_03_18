#include "framework.h"
#include "ShootingGame.h"

BossBullet::BossBullet(float px, float py) : Sprite("","",true, px, py)
{
	this->speed    = 150;
	this->angle    = 0;
	this->lifeTime = 3;
}

BossBullet::~BossBullet()
{}

void BossBullet::Start()
{
	SetSprite("Asset/총알2.bmp");
}

void BossBullet::Update()
{
	//회전각도로..이동하기//
	float theta = angle * M_PI / 180; //90도 

	float dx = cos(theta) * speed * Time::deltaTime;
	float dy = sin(theta) * speed * Time::deltaTime;

	Translate(dx, dy);

	//라이프 타임..측정//
	lifeTime = lifeTime - Time::deltaTime;
	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void BossBullet::SetAngle(float angle)
{
	this->angle = angle;
}