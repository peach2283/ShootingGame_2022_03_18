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
	AddSprite("Asset/�����緯1.bmp",   5, 5, 32, 12,   0,    16, 6);
	AddSprite("Asset/�����緯1.bmp",  39, 5, 32, 12,   0,    16, 6);
	AddSprite("Asset/�����緯1.bmp",  72, 5, 30, 12,   0,    15, 6);
	AddSprite("Asset/�����緯1.bmp", 104, 5, 24, 12,   0,    12, 6);

	AddSprite("Asset/�����緯1.bmp", 131, 5, 20, 12,   0,    10, 6);
	AddSprite("Asset/�����緯1.bmp", 153, 5, 26, 12,   0,    13, 6);
	AddSprite("Asset/�����緯1.bmp", 182, 5, 28, 12,   0,    14, 6);
	AddSprite("Asset/�����緯1.bmp", 213, 5, 30, 12,   0,    15, 6);
	

	//���⳪�� �ִϸ��̼� - 1��//
	AddSprite("Asset/�����緯2.bmp",   7, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/�����緯2.bmp",  42, 4, 31, 48, 1, 15, 6);
	AddSprite("Asset/�����緯2.bmp",  76, 4, 29, 48, 1, 15, 6);
	AddSprite("Asset/�����緯2.bmp", 108, 4, 31, 48, 1, 18, 6);

	AddSprite("Asset/�����緯2.bmp", 142, 4, 31, 48, 1, 17, 6);
	AddSprite("Asset/�����緯2.bmp", 176, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/�����緯2.bmp", 210, 4, 31, 48, 1, 16, 6);
	AddSprite("Asset/�����緯2.bmp", 244, 4, 32, 48, 1, 16, 6);


	Play(0);   //0�� �ִϸ��̼�(Ŭ��)����..����
	Speed(2);

	//�浹ü �߰��ϱ�//
	AddBoxCollider2D(-16, -6, 32, 12);
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
