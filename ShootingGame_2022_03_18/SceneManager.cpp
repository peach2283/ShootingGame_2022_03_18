#include "ShootingGame.h"

Scene* SceneManager::sceneList[3] = { nullptr, nullptr, nullptr };
int    SceneManager::activeIndex  = 0;

void SceneManager::Init()
{
	sceneList[0] = new TitleScene ("Title");  //���۰� �Բ�..�ٷ�..���� ���� �ε��
	sceneList[1] = new GameScene  ("Game");
	sceneList[2] = new EndingScene("Ending");

	activeIndex = 0;
	sceneList[activeIndex]->Load();  //����� ���� ó�� �� �ٷ�..�ε��ϱ�	
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
			//������ (activeIndex)..��ε�
			sceneList[activeIndex]->Unload();

			//���� �ε���..��..ã�Ƽ�..�ε���
			sceneList[i]->Load();
			activeIndex = i;
		}
	}
}