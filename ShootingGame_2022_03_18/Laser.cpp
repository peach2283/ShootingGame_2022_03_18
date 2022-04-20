#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("레이저","", true, px, py)
{
	this->speed    = 300;
	this->lifeTime = 10;
}

Laser::~Laser()
{
}

void Laser::Start()
{
	SetSprite("Asset/레이저.bmp");
	AddBoxCollider2D(0, 0, 6, 33);
}

void Laser::Update()
{
	//이동하기//
	Translate(0, -speed * Time::deltaTime);

	//라이프타임 측정//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		//레이저 객체..삭제//
		Destroy(this);
	}
}

void Laser::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "적기" || tag == "날개")
	{
		//레이저 폭발효과//
		float px = this->GetPx();
		float py = this->GetPy();

		Instantiate(new LaserExp(px - 14, py));

		Destroy(this);  //레이저 삭제하기//
	}
}