#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("����","", true, px, py)
{
	this->speed     = 100;
	
	this->fallSpeed   = 300;
	this->fallTimeOut = 3;

	this->state = State::moveDown;

	this->fireTimer = 0;
	this->fireDelay = 0.5;

	this->hp = 100;

	this->isBombExpCollided = false;
	this->isLaserCollided   = false;

	this->dropBulletItem    = false;
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	/////////���ؾ��� ���� �̹�����//////////////////////////
	AddSprite("Asset/����.bmp", 200 * 0 + 1, 281, 190, 137,     0);
	AddSprite("Asset/����.bmp", 200 * 1 + 1, 281, 190, 137,     0);

	////////�߰����� ���� �̹�����//////////////////////////
	AddSprite("Asset/����.bmp", 200 * 0 + 1, 141, 190, 137,     1);
	AddSprite("Asset/����.bmp", 200 * 1 + 1, 141, 190, 137,     1);
	AddSprite("Asset/����.bmp", 200 * 2 + 1, 141, 190, 137,     1);
	AddSprite("Asset/����.bmp", 200 * 3 + 1, 141, 190, 137,     1);

	////////�������� ���� �̹�����//////////////////////////
	AddSprite("Asset/����.bmp", 200 * 0 + 1,   1, 190, 137,     2);
	AddSprite("Asset/����.bmp", 200 * 1 + 1,   1, 190, 137,     2);
	AddSprite("Asset/����.bmp", 200 * 2 + 1,   1, 190, 137,     2);
	AddSprite("Asset/����.bmp", 200 * 3 + 1,   1, 190, 137,     2);

	///�浹ü �߰��ϱ�////
	AddBoxCollider2D(0  , 80, 190, 25);   //��� ���� 
	AddBoxCollider2D(65 , 10,  60,  15);  //���� ���� 
	AddBoxCollider2D(85 , 25,  20,  110); //����

	//moveDown ���� ���� ��ġ ���������
	downEndPos = Random::Range(20, 150);
}

void Enemy::Update()
{	
	Move();
	Fire();

	//�ߺ� �浹 �Ǵ� ���� ����
	isBombExpCollided = false;
	isLaserCollided   = false;
}

void Enemy::Move()
{
	//���� �̵��ϱ� ������Ʈ �ӽ�//
	switch (state)
	{
		case State::moveDown:
		{
			Translate(0, speed * Time::deltaTime);

			if (GetPy() > downEndPos)
			{
				state = State::moveLeft;
			}
		}
		break;

		case State::moveLeft:
		{
			Translate(-speed * Time::deltaTime, 0);

			if (GetPx() < 0)
			{
				state = State::moveRight;
			}
		}
		break;

		case State::moveRight:
		{
			Translate(speed * Time::deltaTime, 0);

			if (GetPx() > WIDTH - 190)
			{
				state = State::moveLeft;
			}
		}
		break;

		case State::fall:
		{
			//�߶� �̵��ϱ�//
			Translate(0, fallSpeed * Time::deltaTime);		

			//Ÿ�Ӿƿ� ����//
			fallTimeOut -= Time::deltaTime;
			
			if (fallTimeOut < 0)
			{
				//���� ����//
				Destroy(this);

				//���� ������..��ü ��������..���� ī��� ����
				EnemySpawner* spawner = EnemySpawner::Instance();
				spawner->AddDestroy();
			}
		}

		break;
	}
}

void Enemy::Fire()
{
	//�Ѿ� �߻�//
	if (state == State::moveLeft || state == State::moveRight)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			Instantiate(new EnemyBullet(px + 95 - 9, py + 137 - 10));

			fireTimer = 0;
		}
	}
}

void Enemy::SetDropBulletItem(bool drop)
{
	dropBulletItem = drop;
}

void Enemy::SetDropBombItem(bool drop)
{
	dropBombItem = drop;
}

void Enemy::Explosion()
{
	//���� ����
	float px = this->GetPx();
	float py = this->GetPy();

	Instantiate(new EnemyExp(px - 18, py - 90), 1);

	//���� ����
	Destroy(this);

	//���� ���� ī��Ʈ �ϱ�
	EnemySpawner* spawner = EnemySpawner::Instance();
	spawner->AddDestroy();

	//�Ѿ�(������) ������ �����//
	//int p = Random::Range(0, 10000);
	//
	//if (p < 1000)
	//{
	//	Instantiate(new BulletItem(px + 80, py + 40));
	//}

	if (dropBulletItem == true)
	{
		Instantiate(new BulletItem(px + 80, py + 40));
	}

	//��ź ������..�����//
	if (dropBombItem == true)
	{
		Instantiate(new BombItem(px + (190 - 22) / 2, py + (137 - 40) / 2));
	}
}

void Enemy::OnTriggerStay2D(GameObject * other)
{
	string tag = other->GetTag();

	if (tag == "������")
	{
		if (isLaserCollided == false)
		{
			isLaserCollided = true;

			hp = hp - 10;  //���� ü�¿�..����(Damage)�� �����ϱ�
		
			//������ ����ȿ��//
			float px = other->GetPx();
			float py = other->GetPy();

			Instantiate(new LaserExp(px - 14, py));

			Destroy(other);  //������ �����ϱ�//

			//����..���� �ִϸ޴ϼ� �Ǵ��ϱ�//
			if (80 <= hp && hp <= 100)
			{
				Play(0);  //���ؾ��� �ִϸ��̼�
			}
			else if (50 <= hp && hp < 80)
			{
				Play(1);  //�߰����� �ִϸ��̼�
			}
			else if (0 < hp && hp < 50)
			{
				Play(2);              //�ɰ������� �ִϸ��̼�
				state = State::fall;  //���� �߶����·�..����(transition)
			}
			else if (hp <= 0)
			{
				Explosion();
			}
		}
	}
	else if (tag == "��ź����")
	{
		if (isBombExpCollided == false)  //������...�浹ó���� �ȵǾ�������..
		{
			isBombExpCollided = true;  //�浹ó�� ������...ǥ��
			Explosion();			
		}
	}
	else if (tag == "�÷��̾�")
	{
		//printf("----���⿡..�÷��̾ �浹��---\n");
	}
}