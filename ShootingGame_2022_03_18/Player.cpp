#include "ShootingGame.h"

Player::Player(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 250;  //�̵����ǵ�

	this->fireTimer = 0  ; //�߻�Ÿ�̸� ���� ����
	this->fireDelay = 0.2; //�߻����� ���� ����
}

Player::~Player()
{}

void Player::Start()
{
	SetSprite("Asset/�÷��̾�.bmp");
}

void Player::Update()
{
	Move();
	Fire();
}

void Player::Move()
{
	//�̵��ϱ�//
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
	//������ �߻��ϱ�//
	if (GetAsyncKeyState(VK_SPACE) != 0)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			/***********������ �ѹ� �߻�*************/
			//������ ��ü...�����ϱ�//
			Instantiate(new Laser(px + 34 - 3, py - 35));
			/***************************************/

			/***********������ �ι� �߻�*************
			//������ ��ü...�����ϱ�//
			Instantiate(new Laser(px + 34 - 3 - 7, py - 30));
			Instantiate(new Laser(px + 34 - 3 + 7, py - 30));
			***************************************/

			/***********������ ���� �߻�*************
			//������ ��ü...�����ϱ�//
			Instantiate(new Laser(px + 34 - 3 - 7, py - 28));
			Instantiate(new Laser(px + 34 - 3,     py - 38));
			Instantiate(new Laser(px + 34 - 3 + 7, py - 28));
			***************************************/

			//�߻�Ÿ�̸�...����
			fireTimer = 0;
		}
	}
}