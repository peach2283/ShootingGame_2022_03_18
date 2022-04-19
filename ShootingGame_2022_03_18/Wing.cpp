#include "ShootingGame.h"

Wing::Wing(float px, float py, int idx) : Sprite("","",true, px, py)
{
	this->idx = idx;
}

Wing::~Wing()
{}

void Wing::Start()
{
	SetSprite("Asset/º¸½º.bmp", rect[idx][0], rect[idx][1], rect[idx][2], rect[idx][3]);
}

void Wing::Update()
{}
