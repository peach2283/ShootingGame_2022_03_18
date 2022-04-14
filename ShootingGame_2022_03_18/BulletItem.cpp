#include "ShootingGame.h"

BulletItem::BulletItem(float px, float py) : Sprite("�Ѿ˾�����", "", true, px, py)
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
	SetSprite("Asset/�Ѿ˾�����.bmp");
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
			//////////������ ���꽺����Ʈ �ӽ�///////////
			switch (visible)
			{
				case true:
				{
					blinkTimer = blinkTimer + Time::deltaTime;

					if (blinkTimer >= blinkDelay)
					{
						enabled = false;  //����(���ö���Ʈ..��� ����//
						visible = false;  //���� ����..����

						blinkTimer = 0;    //Ÿ�̸�..����
					}
				}
				break;

				case false:
				{
					blinkTimer = blinkTimer + Time::deltaTime;

					if (blinkTimer >= blinkDelay)
					{
						enabled = true;   //����(���ö���Ʈ..��� ����)//
						visible = true;   //���� ����..����

						blinkTimer = 0;  //Ÿ�̸�..����
					}
				}
				break;
			}

			/////////������ Ÿ�Ӿƿ� ����//////////
			blinkTimeOut -= Time::deltaTime;

			if (blinkTimeOut <= 0)
			{
				Destroy(this);
			}
	}
}
