#pragma once

#include "GameObject.h"
#include "BMP.h"

class Animation : public GameObject
{
private:
	Image sprite;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	//애니메이션 기능 테스트 추가 함수//
	void Start();
	void Update();
	void Draw();
};

