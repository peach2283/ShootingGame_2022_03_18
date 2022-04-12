#pragma once
#include "Sprite.h"

class BulletItem : public Sprite
{
private:
	bool visible;  //보이기(true)...숨기기(false) 변수

public:
	BulletItem(float px, float py);
	~BulletItem();

	void Start();
	void Update();
};

