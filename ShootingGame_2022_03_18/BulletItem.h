#pragma once
#include "Sprite.h"

class BulletItem : public Sprite
{
private:
	bool visible;  //���̱�(true)...�����(false) ����

public:
	BulletItem(float px, float py);
	~BulletItem();

	void Start();
	void Update();
};

