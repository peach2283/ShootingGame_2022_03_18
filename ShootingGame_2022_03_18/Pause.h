#pragma once
#include "Button.h"

class Pause : public Button
{
private:
public:
	Pause(float px, float py);
	~Pause();

	void Start();

	//부모..클래스의 OnClick 오버라이딩//
	void OnClick();
};

