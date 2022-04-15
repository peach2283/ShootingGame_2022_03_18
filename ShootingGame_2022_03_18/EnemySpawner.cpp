#include "ShootingGame.h"

EnemySpawner* EnemySpawner::spawner = nullptr;

EnemySpawner::EnemySpawner(float px, float py) : GameObject("", "", true, px, py)
{
	this->spawnTimer = 0;
	this->spawnDelay = 3;

	this->spawnCount   = 0;
	this->destroyCount = 0;
}

EnemySpawner::~EnemySpawner()
{}

void EnemySpawner::Start()
{
	//�ڱ� �ڽŰ�ü..�����͸�... spawner ������ ������ [����..����Ƽ������ Start���� ���� �����ϴ� Awake���� ��]	
	spawner = this;	
}

void EnemySpawner::Update()
{
	if (spawnCount - destroyCount < 3)
	{
		spawnTimer = spawnTimer + Time::deltaTime;

		if (spawnTimer >= spawnDelay)
		{
			if (spawnCount < 20)  //���� ����
			{
				//�������ð� 
				int sel = Random::Range(0, 3);
				int offsetX[3] = { 0, -130, 130 };

				//���� �����ϱ�//
				float px, py;
				GetPosition(px, py);
				
				Enemy *e = (Enemy *)Instantiate(new Enemy(px + offsetX[sel] - 95, py - 137));

				e->SetDropBulletItem(dropBulletItem[spawnCount]);
				e->SetDropBombItem(dropBombItem[spawnCount]);

				//Ÿ�̸� ����
				spawnTimer = 0;

				//����ī��Ʈ ����
				spawnCount++;
			}
			else  //���� ����
			{
				printf("���� �����ϱ�\n");				
			}
		}
	}
}

void EnemySpawner::OnDrawGizmos()
{
	float px, py;
	GetPosition(px, py);

	//px, py�� �߽�����..ũ�Ⱑ 50�� �������� �׸���//
	DrawLine(px - 50, py   , px + 50,    py   , 255, 0, 0);

	//px, py�� �߽�����..ũ�Ⱑ 50�� �������� �׸���//
	DrawLine(px     , py-50, px     ,   py+50, 255, 0, 0);
}

void EnemySpawner::AddDestroy()
{
	destroyCount++;
}

EnemySpawner* EnemySpawner::Instance()
{
	return spawner;
}