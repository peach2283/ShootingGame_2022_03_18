#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("�����ڽ�", "�����緯", true, px, py)
{
	this->hp = 100;
}

Propeller::~Propeller()
{}

void Propeller::Start()
{
	//���ؾ��� �ִϸ��̼� - 0��//
	AddSprite("Asset/����.bmp",   7, 439, 32, 12,     0);
	AddSprite("Asset/����.bmp",  42, 439, 30, 12,     0);
	//AddSprite("Asset/����.bmp",  75, 439, 28, 12,     0);
	//AddSprite("Asset/����.bmp", 106, 439, 23, 12,     0);

	//AddSprite("Asset/����.bmp", 133, 439, 19, 12,     0);
	//AddSprite("Asset/����.bmp", 156, 439, 24, 12,     0);
	//AddSprite("Asset/����.bmp", 184, 439, 27, 12,     0);
	//AddSprite("Asset/����.bmp", 215, 439, 29, 12,     0);

	//���⳪�� �ִϸ��̼� - 1��//
	//AddSprite("Asset/����.bmp",   7, 457, 32, 47,      1);
	//AddSprite("Asset/����.bmp",  42, 457, 31, 47,      1);
	//AddSprite("Asset/����.bmp",  76, 457, 29, 47,      1);
	//AddSprite("Asset/����.bmp", 108, 457, 31, 47,      1);

	AddSprite("Asset/����.bmp", 142, 457, 31, 47,      1);
	AddSprite("Asset/����.bmp", 176, 457, 31, 47,      1);
	AddSprite("Asset/����.bmp", 210, 457, 31, 47,      1);
	AddSprite("Asset/����.bmp", 244, 457, 32, 47,      1);

	Play(0);   //0�� �ִϸ��̼�(Ŭ��)����..����
	Speed(2);

	//�浹ü �߰��ϱ�//
	AddBoxCollider2D(0, 0, 32, 12);
}

void Propeller::Update()
{
	//�θ�..������..Ȯ���ϱ�//
	//string tag = parent->GetTag();
	//printf("�����緯�� �θ� ��ü �±� %s\n", tag.data());
}

void Propeller::Explosion()
{
	//���η���..����ȿ��//
	float px = GetPx();
	float py = GetPy();

	float offx = (32 - 64) / 2;
	float offy = (12 - 64) / 2;

	Instantiate(new BossChildExp(px + offx, py + offy));

	//�÷��緯..����//
	Destroy(this);

	//�����緯�� �θ�ü�� ������..�����緯��..���ŵǾ����� �˷���//
	((Boss*)parent)->OnChildDestroy( this->GetName() );
}

void Propeller::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "������")
	{
		//ü�¿�..���� �����ϱ�//
		hp = hp - 10;

		//���� ü�¿� ����..�ִϸ޴ϼ� ���� �� ���� ����//
		if (0 < hp && hp <= 50)
		{
			Play(1);  //���⳪�� �����緯..�ִϸ��̼�����..����
		}
		else if (hp <= 0)
		{
			Explosion();
		}
	}
	else if (tag == "��ź����")
	{
		Explosion();
	}
}
