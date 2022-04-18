#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("","", true, px, py)
{}

Boss::~Boss()
{}

void Boss::Start()
{
	//폭발하지 않은 보스 이미지//
	SetSprite("Asset/보스.bmp", 0, 0, 493, 206 );

	//폭발 이후..보스 이미지
	//SetSprite("Asset/보스.bmp", 0, 613, 385, 182);
}

void Boss::Update()
{}
