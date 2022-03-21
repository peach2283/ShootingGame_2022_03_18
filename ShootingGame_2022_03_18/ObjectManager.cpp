#include "ShootingGame.h"

//������Ʈ STL vector (static ���� ������)
vector<GameObject*> ObjectManager::gameObjects;

void ObjectManager::Instantiate(GameObject* obj)
{
	gameObjects.push_back(obj);
	obj->Start();
}

void ObjectManager::Update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}
}

void ObjectManager::Draw()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Draw();
	}
}

void ObjectManager::Destroy(GameObject* obj)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i] == obj)
		{
			gameObjects.erase(gameObjects.begin() + i); //�����Ͱ����� ����, ��ü delete�� ����

			//��ü delete �ϱ�
			delete obj;

			//���ϴ� ��ü�� �����ϰ�..�ݺ��� ����
			break;
		}
	}
}

void ObjectManager::Clear()
{
	//��Ͽ� �ִ� ��ü..�����ϱ�//
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}

	//��ü ������ ���� ������..��ü ����//
	gameObjects.clear(); //STL vector�� ��ü����..�Լ�
}