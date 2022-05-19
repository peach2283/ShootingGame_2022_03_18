#pragma once
#include "Sprite.h"

class HPBar : public Sprite
{
private:
	
	float fillAmount;
	GameObject* text;

public:
	HPBar(float px, float py);
	~HPBar();

	void Start();
	void Update();
	void Draw();

	void SetFillAmount(float fill);
	void SetHP(float hp);
};

