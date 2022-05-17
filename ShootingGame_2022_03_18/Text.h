#pragma once

#include "GameObject.h"

class Text : public GameObject
{
private:
public:
	Text(float px, float py);
	~Text();

	void Start();
	void Update();
};
