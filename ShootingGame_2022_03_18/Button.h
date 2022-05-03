#pragma once
#include "Sprite.h"

class Button : public Sprite
{
	//��ư ����..enum//
	enum State {normal=0, hover=1, click=2};

private:
	State state;  //��ư..���� ����

public:
	Button(float px, float py);
	~Button();

	void Start();
	void Update();

	//���콺..��ǥ��..�̹��� �ȿ� �ִ��� �˻��ϴ� �Լ�//
	bool IsInImageRect();
};

