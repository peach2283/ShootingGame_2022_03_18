#pragma once
#include <windows.h>

//Ű�ڵ� ������//
enum KeyCode { UpArrow = 0, DownArrow = 1, LeftArrow = 2, RightArrow = 3, Space = 4, Z = 5 };

class Input
{
	//Ű ���� ������//
	enum State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

private:
	static State state[6];
	static int   vKey[6];

public:
	static void Update(); //Ű�Է� ���� ����

	//Ű ���� üũ �Լ�//
	static bool GetKey    (KeyCode code); //Ű�� ������ �ִ� ������ üũ�Լ�
	static bool GetKeyDown(KeyCode code); //Ű�� ���� üũ�Լ�
	static bool GetKeyUp  (KeyCode code); //Ű�� ���� üũ�Լ�
};

