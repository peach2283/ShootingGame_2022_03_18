#pragma once

#include <string>
#include "Scene.h"

using namespace std;

class SceneManager
{
private:
	static Scene* sceneList[2];

public:

	static void Init();
	static void LoadScene(string name);
};