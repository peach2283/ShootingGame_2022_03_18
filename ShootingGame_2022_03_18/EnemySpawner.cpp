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
	//자기 자신객체..포인터를... spawner 변수에 저장함 [참고..유니티에서는 Start보다 먼저 동작하는 Awake에서 함]	
	spawner = this;	
}

void EnemySpawner::Update()
{
	if (spawnCount - destroyCount < 3)
	{
		spawnTimer = spawnTimer + Time::deltaTime;

		if (spawnTimer >= spawnDelay)
		{
			if (spawnCount < 20)  //적기 스폰
			{
				//랜값선택값 
				int sel = Random::Range(0, 3);
				int offsetX[3] = { 0, -130, 130 };

				//적기 스폰하기//
				float px, py;
				GetPosition(px, py);
				
				Enemy *e = (Enemy *)Instantiate(new Enemy(px + offsetX[sel] - 95, py - 137));

				e->SetDropBulletItem(dropBulletItem[spawnCount]);
				e->SetDropBombItem(dropBombItem[spawnCount]);

				//타이머 리셋
				spawnTimer = 0;

				//스폰카운트 증가
				spawnCount++;
			}
			else  //보스 스폰
			{
				printf("보스 스폰하기\n");				
			}
		}
	}
}

void EnemySpawner::OnDrawGizmos()
{
	float px, py;
	GetPosition(px, py);

	//px, py를 중심으로..크기가 50인 수평직선 그리기//
	DrawLine(px - 50, py   , px + 50,    py   , 255, 0, 0);

	//px, py를 중심으로..크기가 50인 수직직선 그리기//
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