#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum State { moveDown = 0, moveLeft = 1, moveRight = 2 };

private:
	float speed;

public:
	Enemy(float px, float py);
	~Enemy();

	void Start();
	void Update();
};

