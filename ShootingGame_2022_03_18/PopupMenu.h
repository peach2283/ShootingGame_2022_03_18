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
	void OnClick();
};

////�˾� �޴�...������ ��ư..Ÿ��Ʋ�� ������///
class PopupTitle : public Button
{
private:
public:
	PopupTitle(float px, float py);
	~PopupTitle();

	void Start();
	void OnClick();
};

////�˾� �޴�...������ ��ư..����(�������..����)�� ������///
class PopupQuit : public Button
{
private:
public:
	PopupQuit(float px, float py);
	~PopupQuit();

	void Start();
	void OnClick();
};