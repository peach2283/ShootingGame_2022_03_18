#pragma once
#include <windows.h>

//Ű�ڵ� ������//
enum KeyCode { UpArrow = 0, DownArrow = 1, LeftArrow = 2, RightArrow = 3, Space = 4, Z = 5 };

//���콺 ��ǥ..���� ����ü//
struct MousePosition
{
	int x;
	int y;
};

class Input
{
	//Ű ���� ������//
	enum State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

private:
	static State state[6 + 3];  //6�� Ű���� ��ư + 3�� ���콺 ��ư
	static int   vKey [6 + 3];

public:

	//���콺..��ǥ...���� ����..
	static MousePosition mousePosition;

	static void Update(); //Ű�Է� ���� ����

	//Ű ���� üũ �Լ�//
	static bool GetKey    (KeyCode code); //Ű�� ������ �ִ� ������ üũ�Լ�
	static bool GetKeyDown(KeyCode code); //Ű�� ���� üũ�Լ�
	static bool GetKeyUp  (KeyCode code); //Ű�� ���� üũ�Լ�

	//���콺...����..üũ �Լ�//
	static bool GetMouseButton(int button);
	static bool GetMouseButtonDown(int button);
	static bool GetMouseButtonUp(int button);
};

