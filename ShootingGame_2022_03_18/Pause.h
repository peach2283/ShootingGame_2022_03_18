#pragma once
#include "Button.h"

class Pause : public Button
{
private:
public:
	Pause(float px, float py);
	~Pause();

	void Start();

	//�θ�..Ŭ������ OnClick �������̵�//
	void OnClick();
};

