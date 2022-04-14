#include "ShootingGame.h"

BulletItem::BulletItem(float px, float py) : Sprite("총알아이템", "", true, px, py)
{
	this->state   = State::moveDown;
	this->visible = true;

	this->blinkTimer = 0;
	this->blinkDelay = 0.3;

	this->speed	 = 100;

	this->moveTimeOut  = 2;
	this->blinkTimeOut = 3;
}

BulletItem::~BulletItem()
{}

void BulletItem::Start()
{
	SetSprite("Asset/총알아이템.bmp");
	AddBoxCollider2D(2, 0, 20, 80);
}

void BulletItem::Update()
{
	if (state == State::moveDown)
	{
		Translate(0, speed * Time::deltaTime);

		moveTimeOut = moveTimeOut - Time::deltaTime;

		if (moveTimeOut <= 0)
		{
			state = State::blink;
		}
	}
	else if (state == State::blink)
	{
			//////////깜빡임 서브스테이트 머신///////////
			switch (visible)
			{
				case true:
				{
					blinkTimer = blinkTimer + Time::deltaTime;

					if (blinkTimer >= blinkDelay)
					{
						enabled = false;  //숨기(스플라이트..사용 중지//
						visible = false;  //숨김 상태..전이

						blinkTimer = 0;    //타이머..리셋
					}
				}
				break;

				case false:
				{
					blinkTimer = blinkTimer + Time::deltaTime;

					if (blinkTimer >= blinkDelay)
					{
						enabled = true;   //보임(스플라이트..사용 가능)//
						visible = true;   //보임 상태..전이

						blinkTimer = 0;  //타이머..리셋
					}
				}
				break;
			}

			/////////깜빡임 타임아웃 측정//////////
			blinkTimeOut -= Time::deltaTime;

			if (blinkTimeOut <= 0)
			{
				Destroy(this);
			}
	}
}
