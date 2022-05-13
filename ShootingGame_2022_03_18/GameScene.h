#pragma once
#include "Scene.h"

class GameScene : public Scene
{
private:
public:
	GameScene(string name);
	~GameScene();

	void Load();
};