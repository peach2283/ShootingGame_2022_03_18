#pragma once
#include "Sprite.h"

class Score : public Sprite
{
private:
public:
	Score(float px, float py);
	~Score();

	void Start();
	void Update();
};

