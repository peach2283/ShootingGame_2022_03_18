#include "ShootingGame.h"

Bomb::Bomb(float px, float py) : Animation("", "", true, px, py)
{
	this->speed = 150;
}

Bomb::~Bomb()
{}

void Bomb::Start()
{
	for (int i = 0; i < 8; i++)
	{
		AddSprite("Asset/������ź2.bmp", i * 34, 0, 32, 32, 0);
	}

	Speed(0.5);
}

void Bomb::Update()
{
	Translate(0, -speed * Time::deltaTime);
}

void Bomb::OnAnimationEnd()
{
	//��ź ����//
	float px, py;
	
	GetPosition(px, py);
	Instantiate(new BombExp(px-50, py-60));

	//��ź ��ü�� ����//
	Destroy(this);
}