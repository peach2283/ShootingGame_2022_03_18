#pragma once
#include "Sprite.h"

class BossChildSprite : public Sprite
{
private:
	float hp;

public:
	BossChildSprite(string tag, string name, bool active, float px, float py);
	~BossChildSprite();

	void Update();

	void Explosion();
	void OnTriggerStay2D(GameObject* other);

};

