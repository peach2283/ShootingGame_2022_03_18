#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:
public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void Start();
	void Update();
};

