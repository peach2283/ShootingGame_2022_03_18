#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("����","", true, px, py)
{
	this->speed     = 50;
	this->state     = State::moveDown;
	this->attackPos = 50;

	this->fallTimeOut    = 5;
	this->deadChildCount = 0;
}

Boss::~Boss()
{}

void Boss::Start()
{
	//�������� ���� ���� �̹���//
	SetSprite("Asset/����.bmp", 0, 0, 493, 206);

	//�����緯..�ڽİ�ü �߰��ϱ�
	AddChildObject(new Propeller( 63+16, 41+6));
	AddChildObject(new Propeller(111+16, 41+6));
	AddChildObject(new Propeller(159+16, 41+6));

	AddChildObject(new Propeller(302+16, 41+6));
	AddChildObject(new Propeller(350+16, 41+6));
	AddChildObject(new Propeller(398+16, 41+6));

	//����(����)..�ڽ� ��ü �߰��ϱ�
	AddChildObject(new Wing(256, 97,   0));
	AddChildObject(new Wing(302, 94,   1));
	AddChildObject(new Wing(350, 90,   2));
	AddChildObject(new Wing(405, 84,   3));

	AddChildObject(new Wing(206, 98,   4));
	AddChildObject(new Wing(158, 94,   5));
	AddChildObject(new Wing(110, 90,   6));
	AddChildObject(new Wing( 62, 85,   7));

	//���� �� ... �ڽ� ��ü �߰��ϱ�
	AddChildObject(new Gun( 94, 71));
	AddChildObject(new Gun(142, 71));
	AddChildObject(new Gun(190, 71));

	AddChildObject(new Gun(238, 63));

	AddChildObject(new Gun(286, 71));
	AddChildObject(new Gun(334, 71));
	AddChildObject(new Gun(382, 71));

	//���� ����..�ڽ� ��ü �߰��ϱ�
	AddChildObject(new Cannon(265 + 5, 97 + 10, "�����ʴ���"));  //������ ����
	AddChildObject(new Cannon(206 - 5, 97 + 10, "���ʴ���"));    //���� ����

	//���̴�..�ڽ� ��ü �߰��ϱ�
	AddChildObject(new Radar(241, 105));
	AddChildObject(new Radar(241, 117));
}

void Boss::Update()
{
	if (state == State::moveDown)
	{
		Translate(0, speed * Time::deltaTime);

		if (GetPy() > attackPos)
		{
			state = State::attack;
		}
	}
	else if (state == State::attack)
	{
		//ĳ��..�ڽ�..��ü��..ã�Ƽ�..�߻�..������..�˷���...//
		string cannons[2] = { "�����ʴ���" , "���ʴ���" };
		
		for (int i = 0; i < 2; i++)
		{
			Cannon * c=(Cannon*)Find(cannons[i]);

			if (c != nullptr)
			{
				c->OnStartFire();
			}
		}


	}
	else if (state == State::fall)
	{
		//�߶�... �̵�//
		Translate(0, speed * Time::deltaTime);

		//�߶� �ð� ����//
		fallTimeOut = fallTimeOut - Time::deltaTime;

		if (fallTimeOut <= 0)
		{
			//���� �����ϱ�//
			Destroy(this);

			//�������� Ŭ����//
			printf("=======�������� Ŭ����=======\n");
		}
	}
}

void Boss::OnChildDestroy(string name)
{
	//���ŵ�..�ڽ� ī��Ʈ..������Ű��//
	deadChildCount++;
	printf("���ŵ� �ڽ� ī��Ʈ : %d\n", deadChildCount);

	if (deadChildCount == 25)  //������..��� �ڽİ�ü��..���ŵ� (��ü..�ڽİ����� 25��)
	{
		//����..����...
		float px = GetPx();
		float py = GetPy();

		Instantiate(new EnemyExp(px + (493 - 224) / 2  - 180  , py + (206 - 320) / 2));
		Instantiate(new EnemyExp(px + (493 - 224) / 2         , py + (206 - 320) / 2));
		Instantiate(new EnemyExp(px + (493 - 224) / 2  + 180  , py + (206 - 320) / 2));

		//������...������..�̹�����...����		
		SetSprite("Asset/����.bmp", 0, 613, 385, 182, -47, -7);

		//���� �߶� ���·�..�����ϱ�//
		state = State::fall;
	}
}