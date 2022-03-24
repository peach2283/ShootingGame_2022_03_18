#pragma once

#include "GameObject.h"
#include "BMP.h"

class Animation : public GameObject
{
private:
	Image sprite;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	//�ִϸ��̼� ��� �׽�Ʈ �߰� �Լ�//
	void Start();
	void Update();
	void Draw();
};

