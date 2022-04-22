#pragma once
#include "Sprite.h"

class Boss : public Sprite
{
private:
	int deadChildCount;

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//보스 자식이 ... 폭발되었음을 알려주는 이벤트..함수//
	void OnChildDestroy(string name);
};

