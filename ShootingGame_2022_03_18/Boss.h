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

	//���� �ڽ��� ... ���ߵǾ����� �˷��ִ� �̺�Ʈ..�Լ�//
	void OnChildDestroy(string name);
};

