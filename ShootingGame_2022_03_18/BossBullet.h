#pragma once
#include "Sprite.h"

class BossBullet : public Sprite
{
private:
	float speed;

public:
	BossBullet(float px, float py);
	~BossBullet();

	void Start();
	void Update();
};

