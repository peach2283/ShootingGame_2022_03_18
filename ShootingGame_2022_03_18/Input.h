#pragma once
#include <windows.h>

//키코드 열거형//
enum KeyCode { UpArrow = 0, DownArrow = 1, LeftArrow = 2, RightArrow = 3, Space = 4, Z = 5 };

//마우스 좌표..저장 구조체//
struct MousePosition
{
	int x;
	int y;
};

class Input
{
	//키 상태 열거형//
	enum State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

private:
	static State state[6 + 3];  //6개 키보드 버튼 + 3개 마우스 버튼
	static int   vKey [6 + 3];

public:

	//마우스..좌표...저장 변수..
	static MousePosition mousePosition;

	static void Update(); //키입력 상태 갱신

	//키 상태 체크 함수//
	static bool GetKey    (KeyCode code); //키가 눌리고 있는 중인지 체크함수
	static bool GetKeyDown(KeyCode code); //키가 눌림 체크함수
	static bool GetKeyUp  (KeyCode code); //키가 놓임 체크함수

	//마우스...상태..체크 함수//
	static bool GetMouseButton(int button);
	static bool GetMouseButtonDown(int button);
	static bool GetMouseButtonUp(int button);
};

