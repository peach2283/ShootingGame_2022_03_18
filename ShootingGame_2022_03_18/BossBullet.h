#pragma once
#include "Sprite.h"

class BossBullet : public Sprite
{
private:
	float speed;
	float angle;

	float lifeTime;

public:
	BossBullet(float px, float py);
	~BossBullet();

	void SetAngle(float angle);

	void Start();
	void Update();

	void OnTriggerStay2D(GameObject* other);
};

