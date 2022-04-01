#pragma once

#include "Animation.h" 

class LaserExp : public Animation
{
private:
public:
	LaserExp(float px, float py);
	~LaserExp();

	void Start();
	void Update();

	//애니메이션 종료 이벤트 함수..오브라이딩//
	void OnAnimationEnd();
};

