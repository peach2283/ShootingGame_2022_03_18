#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("��ź������", "", true, px, py)
{
	this->speed = 80;
}

BombItem::~BombItem()
{}

void BombItem::Start()
{
	SetSprite("Asset/��ź������.bmp");
}

void BombItem::Update()
{
	Translate(0, speed * Time::deltaTime);
}
