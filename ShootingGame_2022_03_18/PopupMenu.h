#pragma once
#include "Sprite.h"
#include "Button.h"

//////////�˾��޴�..Ŭ����//////
class PopupMenu : public Sprite
{
private:
public:
	PopupMenu(float px, float py);
	~PopupMenu();

	void Start();
	void Update();
};

///////�˾��޴�..���..Ŭ����////
class PopupHeader : public Sprite
{
private:
public:

	PopupHeader(float px, float py);
	~PopupHeader();

	void Start();
	void Update();
};

////�˾� �޴�...������ ��ư..�ٽý���///
class PopupRestart : public Button
{
private:
public:
	PopupRestart(float px, float py);
	~PopupRestart();

	void Start();
};