#pragma once
#include "Sprite.h"
#include "Button.h"

//////////팝업메뉴..클래스//////
class PopupMenu : public Sprite
{
private:
public:
	PopupMenu(float px, float py);
	~PopupMenu();

	void Start();
	void Update();
};

///////팝업메뉴..헤딩..클래스////
class PopupHeader : public Sprite
{
private:
public:

	PopupHeader(float px, float py);
	~PopupHeader();

	void Start();
	void Update();
};

////팝업 메뉴...아이템 버튼..다시시작///
class PopupRestart : public Button
{
private:
public:
	PopupRestart(float px, float py);
	~PopupRestart();

	void Start();
	void OnClick();
};

////팝업 메뉴...아이템 버튼..타이틀로 나가기///
class PopupTitle : public Button
{
private:
public:
	PopupTitle(float px, float py);
	~PopupTitle();

	void Start();
	void OnClick();
};

////팝업 메뉴...아이템 버튼..종료(윈도우로..나감)로 나가기///
class PopupQuit : public Button
{
private:
public:
	PopupQuit(float px, float py);
	~PopupQuit();

	void Start();
	void OnClick();
};