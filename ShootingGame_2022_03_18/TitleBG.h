#pragma once
#include "Sprite.h"

class TitleBG : public Sprite
{
private:
public:
	TitleBG(float px, float py);
	~TitleBG();

	void Start();
	void Update();
};

