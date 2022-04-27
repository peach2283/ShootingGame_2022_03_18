#pragma once
#include "BossChildSprite.h"

class Gun : public BossChildSprite
{
private:
public:
	Gun(float px, float py, string name);
	~Gun();

	void Start();
	void Update();

	void OnFire();
};

