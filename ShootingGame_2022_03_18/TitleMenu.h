#pragma once
#include "Button.h"

/////////////시작 버튼///////////////////
class StartBTN : public Button
{
private:
public:
	StartBTN(float px, float py);
	~StartBTN();

	void Start();	
	void OnClick();
};

//////////끝내기 버튼///////////////////
class ExitBTN : public Button
{
private:
public:
	ExitBTN(float px, float py);
	~ExitBTN();

	void Start();
	void OnClick();
};