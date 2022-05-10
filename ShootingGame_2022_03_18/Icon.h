#pragma once
#include "Sprite.h"

class Icon : public Sprite
{
private:
	string iconImg;

public:
	Icon(float px, float py, string iconImg);
	~Icon();

	void Start();
	void Update();
};

