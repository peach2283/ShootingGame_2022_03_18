#include "ShootingGame.h"

Wing::Wing(float px, float py, int idx) : BossChildSprite("�����ڽ�","����",true, px, py)
{
	this->idx = idx;
}

Wing::~Wing()
{}

void Wing::Start()
{
	SetSprite("Asset/����.bmp", rect[idx][0], rect[idx][1], rect[idx][2], rect[idx][3]);
	AddBoxCollider2D(0, 0, rect[idx][2], rect[idx][3]);
}