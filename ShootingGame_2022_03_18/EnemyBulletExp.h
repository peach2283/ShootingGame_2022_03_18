#pragma once

#include "Animation.h"

class EnemyBulletExp : public Animation
{
private:
public:
	EnemyBulletExp(float px, float py);
	~EnemyBulletExp();

	void Start();
	void Update();
};

