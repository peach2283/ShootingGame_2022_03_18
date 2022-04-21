#pragma once
#include "BossChildSprite.h"

class Wing : public BossChildSprite
{
private:

	int rect[8][4] = 
	{ 
		{298, 425, 30, 18},
		{329, 426, 32, 16},
		{364, 426, 32, 16},
		{399, 426, 32, 16},

		{404, 406, 28, 15},
		{369, 406, 32, 16},
		{334, 406, 32, 16},
		{299, 406, 32, 16},
	};

	int idx;

public:
	Wing(float px, float py, int idx);
	~Wing();

	void Start();
};

