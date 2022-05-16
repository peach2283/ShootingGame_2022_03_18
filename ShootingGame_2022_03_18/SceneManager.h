#pragma once

#include <string>
#include "Scene.h"

using namespace std;

class SceneManager
{
private:
	static Scene* sceneList[3];
	static int    activeIndex;

public:

	static void Init();
	static void Run();
	static void Unload();

	static void LoadScene(string name);
};