#include "ShootingGame.h"

Scene* SceneManager::sceneList[3] = { nullptr, nullptr, nullptr };
int    SceneManager::activeIndex  = 0;

void SceneManager::Init()
{
	sceneList[0] = new TitleScene ("Title");  //시작과 함께..바로..가장 먼저 로드됨
	sceneList[1] = new GameScene  ("Game");
	sceneList[2] = new EndingScene("Ending");

	activeIndex = 0;
	sceneList[activeIndex]->Load();  //목록의 제일 처음 씬 바로..로드하기	
}

void SceneManager::Run()
{
	sceneList[activeIndex]->Run();
}

void SceneManager::Unload()
{
	sceneList[activeIndex]->Unload();
}

void SceneManager::LoadScene(string name)
{
	for (int i = 0; i < 3; i++)
	{
		if (sceneList[i]->GetName() == name)
		{
			//이전씬 (activeIndex)..언로드
			sceneList[activeIndex]->Unload();

			//새로 로드할..씬..찾아서..로드함
			sceneList[i]->Load();
			activeIndex = i;
		}
	}
}