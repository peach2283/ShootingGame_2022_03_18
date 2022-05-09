#pragma once
#include "Sprite.h"

class HPBar : public Sprite
{
private:
public:
	HPBar(float px, float py);
	~HPBar();

	void Start();
	void Update();
	void Draw();
};

