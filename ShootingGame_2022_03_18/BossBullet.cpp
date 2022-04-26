#include "framework.h"
#include "ShootingGame.h"

BossBullet::BossBullet(float px, float py) : Sprite("","",true, px, py)
{
	this->speed = 150;
}

BossBullet::~BossBullet()
{}

void BossBullet::Start()
{
	SetSprite("Asset/ÃÑ¾Ë2.bmp");
}

void BossBullet::Update()
{
	float theta = 90*M_PI / 180; //90µµ 

	Translate(cos(theta), sin(theta));
}