#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("적기","", true, px, py)
{
	this->speed = 100;
	this->state = State::moveDown;

	this->fireTimer = 0;
	this->fireDelay = 0.5;
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	/////////피해없는 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1, 281, 190, 137,     0);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1, 281, 190, 137,     0);

	////////중간피해 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 2 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 3 + 1, 141, 190, 137,     1);

	////////많은피해 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 2 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 3 + 1,   1, 190, 137,     2);

	///충돌체 추가하기////
	AddBoxCollider2D(0, 0, 190, 137);
}

void Enemy::Update()
{	
	//Move();
	//Fire();
}

void Enemy::Move()
{
	//적기 이동하기 스테이트 머신//
	switch (state)
	{
		case State::moveDown:
		{
			Translate(0, speed * Time::deltaTime);

			if (GetPy() > 50)
			{
				state = State::moveLeft;
			}
		}
		break;

		case State::moveLeft:
		{
			Translate(-speed * Time::deltaTime, 0);

			if (GetPx() < 0)
			{
				state = State::moveRight;
			}
		}
		break;

		case State::moveRight:
		{
			Translate(speed * Time::deltaTime, 0);

			if (GetPx() > WIDTH - 190)
			{
				state = State::moveLeft;
			}
		}
		break;

	}
}

void Enemy::Fire()
{
	//총알 발사//
	if (state == State::moveLeft || state == State::moveRight)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			Instantiate(new EnemyBullet(px + 95 - 9, py + 137 - 10));

			fireTimer = 0;
		}
	}
}