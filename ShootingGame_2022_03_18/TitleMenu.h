#pragma once
#include "Button.h"

/////////////���� ��ư///////////////////
class StartBTN : public Button
{
private:
public:
	StartBTN(float px, float py);
	~StartBTN();

	void Start();	
	void OnClick();
};

//////////������ ��ư///////////////////
class ExitBTN : public Button
{
private:
public:
	ExitBTN(float px, float py);
	~ExitBTN();

	void Start();
	void OnClick();
};