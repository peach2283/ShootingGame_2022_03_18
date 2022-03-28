#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	
	//�̵��ӷ�//
	float speed;

	//�߻�ð� ���� ����//
	float fireTimer;
	float fireDelay;

	//��������Ʈ �̹��� ����ü
	Image sprite[7];

	//��������Ʈ �׸��� �ε���
	int index;

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();
	void Draw();

	//�÷��̾� ��� �߰��Լ�//
	void Move();
	void Fire();
};

