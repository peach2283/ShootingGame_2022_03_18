#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	
	//이동속력//
	float speed;

	//발사시간 측정 변수//
	float fireTimer;
	float fireDelay;

	//스프라이트 이미지 구조체
	Image sprite[7];

	//스프라이트 그리기 인덱스
	int index;

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();
	void Draw();

	//플레이어 기능 추가함수//
	void Move();
	void Fire();
};

