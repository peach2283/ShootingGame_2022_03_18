#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("�����Ѿ�","", true, px, py)
{
	this->speed    = 150;
	this->lifeTime = 10;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::Start()
{
	SetSprite("Asset/�Ѿ�1.bmp");
	AddBoxCollider2D(0, 0, 17, 15);
}

void EnemyBullet::Update()
{
	//�̵��ϱ�
	Translate(0, speed * Time::deltaTime);

	//������Ÿ�� ����
	lifeTime -= Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void EnemyBullet::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "��ź����" || tag=="�÷��̾�" || tag == "����")
	{
		//���� �Ѿ� ȿ��
		float px = GetPx();
		float py = GetPy();

		Instantiate(new EnemyBulletExp(px - (40 - 17) / 2, py - (40 - 15) / 2));

		//�����Ѿ� ����
		Destroy(this);
	}
}