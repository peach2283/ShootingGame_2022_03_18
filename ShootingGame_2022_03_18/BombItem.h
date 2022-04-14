#pragma once
#include "Sprite.h"

class BombItem : public Sprite
{
private:
	float speed;

public:
	BombItem(float px, float py);
	~BombItem();

	void Start();
	void Update();
};

