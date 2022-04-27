#include "ShootingGame.h"

Cannon::Cannon(float px, float py, string name) : BossChildSprite("�����ڽ�",name, true, px, py)
{
	this->hp = 100;

	this->fireTimer = 0;
	this->fireDelay = 2;

	this->doFire = false;
}

Cannon::~Cannon()
{}

void Cannon::Start()
{
	SetSprite("Asset/����.bmp", 357, 262, 21, 22);
	AddBoxCollider2D(5, 0, 11, 22);

	SetDamage(20);  //���ط� �����ϱ�

	this->fireDelay = Random::Range(2, 5);
}

void Cannon::Update()
{
	if (doFire == true)
	{
		fireTimer += Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			BossBullet* bullet;

			for (int i = 0; i < 30; i++)
			{
				bullet = (BossBullet*)Instantiate(new BossBullet(px + 2, py + 15));
				bullet->SetAngle(i * 12);
			}

			fireTimer = 0;
		}
	}
}

void Cannon::OnStartFire()
{
	doFire = true;
}