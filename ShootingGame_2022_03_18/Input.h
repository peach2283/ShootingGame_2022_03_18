#pragma once
#include <windows.h>

//Ű ���� ������//
enum State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

class Input
{
private:
	static State state[6];
	static int   vKey[6];

public:
	static void Update(); //Ű�Է� ���� ����

	//Ű ���� üũ �Լ�//
	static bool GetKey    (int i); //Ű�� ������ �ִ� ������ üũ�Լ�
	static bool GetKeyDown(int i); //Ű�� ���� üũ�Լ�
	static bool GetKeyUp  (int i); //Ű�� ���� üũ�Լ�
};

