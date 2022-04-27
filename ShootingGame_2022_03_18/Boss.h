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

	//건 발사..패턴 배열//
	bool gunPattern[20][7] = { 
								{true, true, true,    true,     true,  true,  true}, 
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},

								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},

								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},

								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true},
								{true, true, true,    true,     true,  true,  true}
						  };
	int gunPatternIdx;

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//보스 자식이 ... 폭발되었음을 알려주는 이벤트..함수//
	void OnChildDestroy(string name);
};

