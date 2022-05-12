#pragma once
#include "Button.h"

class StartBTN : public Button
{
private:

public:
	StartBTN(float px, float py);
	~StartBTN();

	void Start();	
};
