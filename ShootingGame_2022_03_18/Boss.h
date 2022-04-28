#pragma once
#include "Sprite.h"

class Boss : public Sprite
{
	enum State {moveDown=0, attack=1, fall=2};

private:
	float speed;
	int deadChildCount;
	float attackPos;

	float fallTimeOut;

	State state;

	float gunFireTimer;
	float gunFireDeley;

	//�� �߻�..���� �迭//
	bool gunPattern[20][7] = { 
								{true, true, true,    false,     false,  false,  false},
								{true, true, true,    false,     false,  false,  false},
								{true, true, true,    false,     false,  false,  false},
								{true, true, true,    false,     false,  false,  false},
								{true, true, true,    false,     false,  false,  false},

								{false, false, false,    false,     true,  true,  true},
								{false, false, false,    false,     true,  true,  true},
								{false, false, false,    false,     true,  true,  true},
								{false, false, false,    false,     true,  true,  true},
								{false, false, false,    false,     true,  true,  true},

								{true, false, false,    true,     false,  false,  true},
								{true, false, false,    true,     false,  false,  true},
								{true, false, false,    true,     false,  false,  true},
								{true, false, false,    true,     false,  false,  true},
								{true, false, false,    true,     false,  false,  true},

								{false, false, true,    true,     true,  false,  false},
								{false, false, true,    true,     true,  false,  false},
								{false, false, true,    true,     true,  false,  false},
								{false, false, true,    true,     true,  false,  false},
								{false, false, true,    true,     true,  false,  false}
						  };
	int gunPatternIdx;

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//���� �ڽ��� ... ���ߵǾ����� �˷��ִ� �̺�Ʈ..�Լ�//
	void OnChildDestroy(string name);
};

