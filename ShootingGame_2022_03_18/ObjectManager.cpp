#include "framework.h"
#include "ShootingGame.h"

//������Ʈ STL vector (static ���� ������)
vector<GameObject*> ObjectManager::gameObjects[MAX_LAYER];

void ObjectManager::Instantiate(GameObject* obj, int layer)
{
	gameObjects[layer].push_back(obj);
	obj->Start();
}

void ObjectManager::Update()
{
	for (int layer = 0; layer < MAX_LAYER ; layer++)
	{
		for (int i = 0; i < gameObjects[layer].size(); i++)
		{
			if (gameObjects[layer][i]->GetActive() == true)  //Ȱ��ȭ�� ��ü��..������Ʈ..������
			{
				gameObjects[layer][i]->Update();
			}
		}
	}
}

void ObjectManager::CheckCollisionObjectPair(GameObject * obji, GameObject * objj)
{
	if (obji->GetActive() == true && objj->GetActive() == true) //����..�� ���ӿ�����Ʈ��..��� Ȱ��ȭ�϶�..�浹�˻� ����
	{
		//��ü�� �浹ü ��������//
		vector<BoxCollider2D> boxi = obji->GetCollider();
		vector<BoxCollider2D> boxj = objj->GetCollider();

		for (int ii = 0; ii < boxi.size(); ii++)
		{
			for (int jj = 0; jj < boxj.size(); jj++)
			{
				//�浹ü�� �簢�� ��ǥ ��������//
				float xi, yi, widthi, heighti;
				float xj, yj, widthj, heightj;

				boxi[ii].GetBox(xi, yi, widthi, heighti);
				boxj[jj].GetBox(xj, yj, widthj, heightj);

				//i �ε��� ��ü �ڽ� ��ǥ//
				float a0 = xi, b0 = yi, a1 = a0 + widthi, b1 = b0 + heighti;

				//j �ε��� ��ü �ڽ� ��ǥ
				float x0 = xj, y0 = yj, x1 = x0 + widthj, y1 = y0 + heightj;

				if (y0 < b1 && y1>b0 && x1 > a0 && x0 < a1)
				{
					//�浹 �̺�Ʈ �߻�//
					obji->OnTriggerStay2D(objj);
					objj->OnTriggerStay2D(obji);
				}
			}
		}
	}
}

void ObjectManager::CheckCollision()
{
	for (int layerI = 0; layerI < MAX_LAYER ; layerI++)
	{
		for (int layerJ = 0; layerJ < MAX_LAYER ; layerJ++)
		{
			if (layerI == layerJ) //���� ���̾��� ��ü�鰣�� �浹�˻�
			{
							
				for (int i = 0; i < gameObjects[layerI].size(); i++)
				{
					for (int j = 0; j < gameObjects[layerJ].size(); j++)
					{
						
						if (i > j)
						{
							CheckCollisionObjectPair(gameObjects[layerI][i], gameObjects[layerJ][j]);
						}						
					}
				}			
			}
			else if (layerI < layerJ)  //�ٸ� ���̾���� ��ü�鰣�� �浹�˻�
			{

				for (int i = 0; i < gameObjects[layerI].size(); i++)
				{
					for (int j = 0; j < gameObjects[layerJ].size(); j++)
					{					
						CheckCollisionObjectPair(gameObjects[layerI][i], gameObjects[layerJ][j]);
						
					}
				}
			}
		}
	}
}

void ObjectManager::Draw()
{
	for (int layer = 0; layer < MAX_LAYER ; layer++)
	{
		for (int i = 0; i < gameObjects[layer].size(); i++)
		{
			if (gameObjects[layer][i]->GetActive() == true)
			{
				gameObjects[layer][i]->Draw();			//��ü �׸���
				gameObjects[layer][i]->OnDrawGizmos(); //�����..�׸���
			}
		}
	}
}

void ObjectManager::ClearDeadObject()
{
	for (int layer = 0; layer < MAX_LAYER ; layer++)
	{
		for (int i = 0; i < gameObjects[layer].size(); i++)
		{
			GameObject* obj = gameObjects[layer][i];

			if (obj->GetDead() == true)
			{
				gameObjects[layer].erase(gameObjects[layer].begin() + i);  //��Ͽ��� ����
				delete obj;                                  //��ü ���� (�Ҹ���)

				i--;
			}
		}
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
	for (int layer = 0; layer < MAX_LAYER ; layer++)
	{
		//��Ͽ� �ִ� ��ü..�����ϱ�//
		for (int i = 0; i < gameObjects[layer].size(); i++)
		{
			delete gameObjects[layer][i];
		}

		//��ü ������ ���� ������..��ü ����//
		gameObjects[layer].clear(); //STL vector�� ��ü����..�Լ�
	}
}