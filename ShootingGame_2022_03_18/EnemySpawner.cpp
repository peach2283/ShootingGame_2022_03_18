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

				//Instantiate(new Enemy(px       - 95, py - 137)); //가운데 스폰위치
				//Instantiate(new Enemy(px - 130 - 95, py - 137)); //왼쪽   스폰위치
				//Instantiate(new Enemy(px + 130 - 95, py - 137)); //오른쪽 스폰위치

				if (dropBulletItem[spawnCount] == true)
				{
					Enemy * e=new Enemy(px + offsetX[sel] - 95, py - 137);

					e->SetDropBulletItem(true);

					Instantiate(e);  //블릿 아이템 떨구는 적기
				}
				else {

					Enemy* e = new Enemy(px + offsetX[sel] - 95, py - 137);

					e->SetDropBulletItem(false);

					Instantiate(e);  //블릿 아이템 떨구지 않는 적기
				}

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