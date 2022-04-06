#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	//플레이어..동작 상태//
	enum State {showUp=0, control=1};

private:
	
	//이동속력//
	float speed;
	float showUpSpeed;

	//발사시간 측정 변수//
	float fireTimer;
	float fireDelay;

	//스프라이트 이미지 구조체
	Image sprite[7];

	//스프라이트 그리기 인덱스
	int index;

	//이미지변경(애니메이션) 시간 변수
	float animTimer;
	float animDelay;

	//플레이어 체력
	float hp;

	//상태 변수
	State state;

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();
	void Draw();

	//플레이어 기능 추가함수//
	void Move();
	void Fire();

	//충돌이벤트 처리 함수 오버라이딩//
	void OnTriggerStay2D(GameObject * other);
};

