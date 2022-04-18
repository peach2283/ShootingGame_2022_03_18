#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	//�÷��̾�..���� ����//
	enum State {showUp=0, control=1};

private:
	
	//�̵��ӷ�//
	float speed;
	float showUpSpeed;

	//�߻�ð� ���� ����//
	float fireTimer;
	float fireDelay;

	//��������Ʈ �̹��� ����ü
	Image sprite[7];

	//��������Ʈ �׸��� �ε���
	int index;

	//�̹�������(�ִϸ��̼�) �ð� ����
	float animTimer;
	float animDelay;

	//�÷��̾� ü��
	float hp;

	//���� ����
	State state;

	//�Ѿ�(������)�߻� ����
	int bulletCount;

	//��ź ���� ����
	int bombCount;

	//�Ѿ�(������) ������..�浹 Ȯ�� ����//
	bool isBulletItemCollided;

	//���� ���� �ð�
	float shieldTimeOut;

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();
	void Draw();

	//�÷��̾� ��� �߰��Լ�//
	void Move();
	void Fire();

	//�浹�̺�Ʈ ó�� �Լ� �������̵�//
	void OnTriggerStay2D(GameObject * other);
};

