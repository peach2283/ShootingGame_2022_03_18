#pragma once
#include "BossChildSprite.h"

class Radar : public BossChildSprite
{
private:
public:
	Radar(float px, float py);
	~Radar();

	void Start();
};

