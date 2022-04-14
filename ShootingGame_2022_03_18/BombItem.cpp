#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("ÆøÅº¾ÆÀÌÅÛ", "", true, px, py)
{
	this->speed = 80;
}

BombItem::~BombItem()
{}

void BombItem::Start()
{
	SetSprite("Asset/ÆøÅº¾ÆÀÌÅÛ.bmp");
	AddBoxCollider2D(0, 0, 22, 40);
}

void BombItem::Update()
{
	Translate(0, speed * Time::deltaTime);

	//È­¸é ÇÏ´Ü¿¡¼­..Á¦°ÅÇÏ±â//
	if (GetPy() >= HEIGHT)
	{
		Destroy(this);
	}
}
