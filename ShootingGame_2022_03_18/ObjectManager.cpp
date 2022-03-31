#include "framework.h"
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

void ObjectManager::CheckCollision()
{
	//printf("------------------------------------\n");

	for (int i = 0; i < gameObjects.size(); i++)
	{
		for (int j = 0; j < gameObjects.size(); j++)
		{
			if (i > j)
			{
				//��ü�� �浹ü ��������//
				BoxCollider2D boxi = gameObjects[i]->GetCollider();
				BoxCollider2D boxj = gameObjects[j]->GetCollider();

				//�浹ü�� �簢�� ��ǥ ��������//
				float xi, yi, widthi, heighti;
				float xj, yj, widthj, heightj;

				boxi.GetBox(xi, yi, widthi, heighti);
				boxj.GetBox(xj, yj, widthj, heightj);

				//i �ε��� ��ü �ڽ� ��ǥ//
				float a0 = xi, b0 = yi, a1 = a0 + widthi, b1 = b0 + heighti;

				//j �ε��� ��ü �ڽ� ��ǥ
				float x0 = xj, y0 = yj, x1 = x0 + widthj, y1 = y0 + heightj;

				if (y0 < b1 && y1>b0 && x1 > a0&& x0 < a1)
				{
					//�浹 �̺�Ʈ �߻�//
					gameObjects[i]->OnTriggerStay2D();
					gameObjects[j]->OnTriggerStay2D();
				}


				//string tagi = gameObjects[i]->GetTag();
				//string tagj = gameObjects[j]->GetTag();

				//printf("(%s , %s) ", tagi.data(), tagj.data());
			}
		}

		//printf("\n");
	}

	//printf("\n");
}

void ObjectManager::Draw()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Draw();			//��ü �׸���
		gameObjects[i]->OnDrawGizmos(); //�����..�׸���
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