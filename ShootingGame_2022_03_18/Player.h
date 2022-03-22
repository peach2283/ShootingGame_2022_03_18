#pragma once
#include "Sprite.h"

class Player : public Sprite
{
private:
	
	//�̵��ӷ�//
	float speed;

	//�߻�ð� ���� ����//
	float fireTimer;
	float fireDelay;

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	//�÷��̾� ��� �߰��Լ�//
	void Move();
	void Fire();
};

