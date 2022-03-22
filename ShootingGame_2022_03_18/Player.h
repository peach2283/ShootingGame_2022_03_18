#pragma once
#include "Sprite.h"

class Player : public Sprite
{
private:
	
	//이동속력//
	float speed;

	//발사시간 측정 변수//
	float fireTimer;
	float fireDelay;

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	//플레이어 기능 추가함수//
	void Move();
	void Fire();
};

