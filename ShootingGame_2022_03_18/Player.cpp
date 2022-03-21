#include "ShootingGame.h"

Player::Player(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 250;  //�̵����ǵ�
}

Player::~Player()
{}

void Player::Start()
{
	SetSprite("Asset/�÷��̾�.bmp");
}

void Player::Update()
{
	//�̵��ϱ�//
	float dist = Time::deltaTime * speed;

	if (GetAsyncKeyState(VK_UP) != 0)  //VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT
	{
		Translate(0, -dist);
	}

	if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		Translate(0, dist);
	}

	if (GetAsyncKeyState(VK_LEFT) != 0)
	{
		Translate(-dist, 0);
	}

	if (GetAsyncKeyState(VK_RIGHT) != 0)
	{
		Translate(dist, 0);
	}
}