#pragma once
#include "BossChildSprite.h"

class Cannon : public BossChildSprite
{
private:
	float hp;

	float fireTimer;
	float fireDelay;
	bool  doFire; 

public:
	Cannon(float px, float py, string name);
	~Cannon();

	void Start();
	void Update();

	//발사 시작 이벤트 함수//
	void OnStartFire();

};

