#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:
	//���� Ÿ�� ����//
	float spawnTimer;
	float spawnDelay;

	//���� ����/���� ī��Ʈ �ϱ�//
	int spawnCount;
	int destroyCount;

	//�ڱ� ��ü..�����͸� �����ϴ� ����ƽ ����//
	static EnemySpawner* spawner;

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void Start();
	void Update();

	//OnDrawGizmos �������̵�//
	void OnDrawGizmos();

	//���� ���� ī��Ʈ �Լ�//
	void AddDestroy();

	//��ü ������ ��������//
	static EnemySpawner* Instance();

};

