#pragma once
#include <windows.h>

//키 상태 열거형//
enum State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

class Input
{
private:
	static State state[6];
	static int   vKey[6];

public:
	static void Update(); //키입력 상태 갱신

	//키 상태 체크 함수//
	static bool GetKey    (int i); //키가 눌리고 있는 중인지 체크함수
	static bool GetKeyDown(int i); //키가 눌림 체크함수
	static bool GetKeyUp  (int i); //키가 놓임 체크함수
};

