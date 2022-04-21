#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("������","", true, px, py)
{
	this->speed    = 300;
	this->lifeTime = 10;
}

Laser::~Laser()
{
}

void Laser::Start()
{
	SetSprite("Asset/������.bmp");
	AddBoxCollider2D(0, 0, 6, 33);
}

void Laser::Update()
{
	//�̵��ϱ�//
	Translate(0, -speed * Time::deltaTime);

	//������Ÿ�� ����//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		//������ ��ü..����//
		Destroy(this);
	}
}

void Laser::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "����" || tag == "�����ڽ�")
	{
		//������ ����ȿ��//
		float px = this->GetPx();
		float py = this->GetPy();

		Instantiate(new LaserExp(px - 14, py));

		Destroy(this);  //������ �����ϱ�//
	}
}