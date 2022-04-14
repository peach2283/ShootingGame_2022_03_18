#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:
	//스폰 타임 변수//
	float spawnTimer;
	float spawnDelay;

	//적기 스폰/제거 카운트 하기//
	int spawnCount;
	int destroyCount;

	//자기 객체..포인터를 저장하는 스태틱 변수//
	static EnemySpawner* spawner;

	//총알(레이저)/폭탄 아이템..떨기기..지정..배열//
	bool dropBulletItem[20] = { false, false, false, false, true ,   false, false, true, false , false,
								true , false, false, true , false,   false, true , false, true , true};

	bool dropBombItem[20]   = { false, false, false, false , true ,   false, false, false, false , true,
					   		    false ,false, false, false , true ,   false, false, false, false , true };

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void Start();
	void Update();

	//OnDrawGizmos 오버라이딩//
	void OnDrawGizmos();

	//적기 제거 카운트 함수//
	void AddDestroy();

	//객체 포인터 가져오기//
	static EnemySpawner* Instance();

};

