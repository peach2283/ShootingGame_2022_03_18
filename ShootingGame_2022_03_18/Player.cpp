#include "ShootingGame.h"

Player::Player(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 250;  //이동스피드

	this->fireTimer = 0  ; //발사타이머 측정 변수
	this->fireDelay = 0.2; //발사지연 세팅 변수
}

Player::~Player()
{}

void Player::Start()
{
	SetSprite("Asset/플레이어.bmp");
}

void Player::Update()
{
	Move();
	Fire();
}

void Player::Move()
{
	//이동하기//
	float dist = Time::deltaTime * speed;

	if (GetAsyncKeyState(VK_UP) != 0)  //VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT
	{
		Translate(0, -dist);

		if (GetPy() < 0)
		{
			SetPy(0);
		}
	}

	if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		Translate(0, dist);

		if (GetPy() > HEIGHT - 91)
		{
			SetPy(HEIGHT - 91);
		}
	}

	if (GetAsyncKeyState(VK_LEFT) != 0)
	{
		Translate(-dist, 0);

		if (GetPx() < 0)
		{
			SetPx(0);
		}
	}

	if (GetAsyncKeyState(VK_RIGHT) != 0)
	{
		Translate(dist, 0);

		if (GetPx() > WIDTH - 68)
		{
			SetPx(WIDTH - 68);
		}
	}
}

void Player::Fire()
{
	//레이저 발사하기//
	if (GetAsyncKeyState(VK_SPACE) != 0)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			/***********레이저 한발 발사*************/
			//레이저 객체...생성하기//
			Instantiate(new Laser(px + 34 - 3, py - 35));
			/***************************************/

			/***********레이저 두발 발사*************
			//레이저 객체...생성하기//
			Instantiate(new Laser(px + 34 - 3 - 7, py - 30));
			Instantiate(new Laser(px + 34 - 3 + 7, py - 30));
			***************************************/

			/***********레이저 세발 발사*************
			//레이저 객체...생성하기//
			Instantiate(new Laser(px + 34 - 3 - 7, py - 28));
			Instantiate(new Laser(px + 34 - 3,     py - 38));
			Instantiate(new Laser(px + 34 - 3 + 7, py - 28));
			***************************************/

			//발사타이머...리셋
			fireTimer = 0;
		}
	}
}