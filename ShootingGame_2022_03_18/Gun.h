#pragma once
#include "BossChildSprite.h"

class Gun : public BossChildSprite
{
private:
public:
	Gun(float px, float py);
	~Gun();

	void Start();
	void Update();
};

