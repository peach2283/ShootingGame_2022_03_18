#include "framework.h"
#include "ShootingGame.h"

BossBullet::BossBullet(float px, float py) : Sprite("보스총알","",true, px, py)
{
	this->speed    = 150;
	this->angle    = 0;
	this->lifeTime = 5;
}

BossBullet::~BossBullet()
{}

void BossBullet::Start()
{
	SetSprite("Asset/총알2.bmp");
	AddBoxCollider2D(0, 0, 17, 17);
}

void BossBullet::Update()
{
	//회전각도로..이동하기//
	float theta = angle * M_PI / 180; //90도 

	float dx = cos(theta) * speed * Time::deltaTime;
	float dy = sin(theta) * speed * Time::deltaTime;

	Translate(dx, dy);

	//라이프 타임..측정//
	lifeTime = lifeTime - Time::deltaTime;
	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void BossBullet::SetAngle(float angle)
{
	this->angle = angle;
}

void BossBullet::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "폭탄폭발" || tag == "플레이어" || tag == "방패")
	{
		//적기 총알 효과
		float px = GetPx();
		float py = GetPy();

		Instantiate(new EnemyBulletExp(px - (40 - 17) / 2, py - (40 - 15) / 2));

		//적기총알 제거
		Destroy(this);
	}
}