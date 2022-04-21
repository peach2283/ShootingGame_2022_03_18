#pragma once
#include "Animation.h"

class Propeller : public Animation
{
private:
	float hp;

public:
	Propeller(float px, float py);
	~Propeller();

	void Start();
	void Update();

	void Explosion();

	void OnTriggerStay2D(GameObject* other);
};

