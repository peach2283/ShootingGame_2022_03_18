#pragma once
#include "Sprite.h"

class BulletItem : public Sprite
{
	enum State {moveDown, blink};

private:
	State state;   //�̵�..������ ���� ����
	bool visible;  //���̱�(true)...�����(false) ����

	//������ �ð� ����
	float blinkTimer;
	float blinkDelay;

	//�̵� �ӷ�(speed) ....[����]�ӵ�(velocity)
	float speed;

	//�̵� Ÿ�Ӿƿ�//
	float moveTimeOut;

	//������ Ÿ�� �ƿ�//
	float blinkTimeOut;

public:
	BulletItem(float px, float py);
	~BulletItem();

	void Start();
	void Update();
};

