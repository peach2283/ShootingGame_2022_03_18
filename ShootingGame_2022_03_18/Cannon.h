#pragma once
#include "BossChildSprite.h"

class Cannon : public BossChildSprite
{
private:
	float hp;

	float fireTimer;
	float fireDelay;

public:
	Cannon(float px, float py, string name);
	~Cannon();

	void Start();
	void Update();
};

