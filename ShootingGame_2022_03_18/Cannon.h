#pragma once
#include "BossChildSprite.h"

class Cannon : public BossChildSprite
{
private:
	float hp;

public:
	Cannon(float px, float py);
	~Cannon();

	void Start();
};

