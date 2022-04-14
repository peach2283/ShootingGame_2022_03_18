#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum State { moveDown = 0, moveLeft = 1, moveRight = 2, fall=3 };

private:

	float speed;
	float fallSpeed;

	float fallTimeOut;

	State state;

	float fireTimer;
	float fireDelay;

	float hp;

	bool isBombExpCollided;  //��ź ���߰� �浹ó��..�Ǵܺ���
	bool isLaserCollided;    //������ �浹 ó�� .. �Ǵܺ���

	int  downEndPos;         //moveDown ��������..���� ��ġ

	bool dropBulletItem;     //��(������) ������..������..���� ����
	bool dropBombItem;       //��ź ������ ������..���� ����

public:
	Enemy(float px, float py);
	~Enemy();

	void Start();
	void Update();

	void Move();
	void Fire();

	void SetDropBulletItem(bool drop);
	void SetDropBombItem  (bool drop);

	//�浹�̺�Ʈ ó�� �Լ� �������̵�//
	void OnTriggerStay2D(GameObject * other);

	//���� ���� �Լ�//
	void Explosion();
};

