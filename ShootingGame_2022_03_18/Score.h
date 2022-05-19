#pragma once
#include "Sprite.h"

class Score : public Sprite
{
private:
	GameObject* text;

public:
	Score(float px, float py);
	~Score();

	void Start();
	void Update();

	void SetScore(int s);
};

