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
	for (int i = 0; i < gameObjects.size(); i++)
	{
		for (int j = 0; j < gameObjects.size(); j++)
		{
			if (i > j)
			{
				//�浹�˻� ��ü..������ �������ϱ�//
				GameObject* obji = gameObjects[i];
				GameObject* objj = gameObjects[j];

				//��ü�� �浹ü ��������//
				BoxCollider2D boxi = obji->GetCollider();
				BoxCollider2D boxj = objj->GetCollider();

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
					obji->OnTriggerStay2D(objj);
					objj->OnTriggerStay2D(obji);

					////�� ��ü�� ��� ��� �Ϸ� ���Ŀ�..����///
				}
			}
		}
	}
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
	obj->SetDead(true);

	/****************************************************
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
	********************************************************/
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