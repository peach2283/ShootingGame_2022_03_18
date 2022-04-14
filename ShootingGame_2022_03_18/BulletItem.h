#pragma once
#include "Sprite.h"

class BulletItem : public Sprite
{
	enum State {moveDown, blink};

private:
	State state;   //이동..깜빡인 상태 변수
	bool visible;  //보이기(true)...숨기기(false) 변수

	//깜빡임 시간 변수
	float blinkTimer;
	float blinkDelay;

	//이동 속력(speed) ....[참고]속도(velocity)
	float speed;

	//이동 타임아웃//
	float moveTimeOut;

	//깜빡인 타움 아웃//
	float blinkTimeOut;

public:
	BulletItem(float px, float py);
	~BulletItem();

	void Start();
	void Update();
};

