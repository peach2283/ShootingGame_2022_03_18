#include "ShootingGame.h"

Scene* SceneManager::sceneList[2] = { nullptr, nullptr };

void SceneManager::Init()
{
	sceneList[0] = new TitleScene();
	sceneList[1] = new GameScene();
}

void SceneManager::LoadScene(string name)
{
}