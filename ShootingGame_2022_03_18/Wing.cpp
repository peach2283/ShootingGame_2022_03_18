#include "ShootingGame.h"

Wing::Wing(float px, float py, int idx) : BossChildSprite("보스자식","날개",true, px, py)
{
	this->idx = idx;
}

Wing::~Wing()
{}

void Wing::Start()
{
	SetSprite("Asset/보스.bmp", rect[idx][0], rect[idx][1], rect[idx][2], rect[idx][3]);
	AddBoxCollider2D(0, 0, rect[idx][2], rect[idx][3]);
}