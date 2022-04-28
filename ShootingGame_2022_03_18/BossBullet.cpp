#include "framework.h"
#include "ShootingGame.h"

BossBullet::BossBullet(float px, float py) : Sprite("�����Ѿ�","",true, px, py)
{
	this->speed    = 150;
	this->angle    = 0;
	this->lifeTime = 5;
}

BossBullet::~BossBullet()
{}

void BossBullet::Start()
{
	SetSprite("Asset/�Ѿ�2.bmp");
	AddBoxCollider2D(0, 0, 17, 17);
}

void BossBullet::Update()
{
	//ȸ��������..�̵��ϱ�//
	float theta = angle * M_PI / 180; //90�� 

	float dx = cos(theta) * speed * Time::deltaTime;
	float dy = sin(theta) * speed * Time::deltaTime;

	Translate(dx, dy);

	//������ Ÿ��..����//
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

	if (tag == "��ź����" || tag == "�÷��̾�" || tag == "����")
	{
		//���� �Ѿ� ȿ��
		float px = GetPx();
		float py = GetPy();

		Instantiate(new EnemyBulletExp(px - (40 - 17) / 2, py - (40 - 15) / 2));

		//�����Ѿ� ����
		Destroy(this);
	}
}