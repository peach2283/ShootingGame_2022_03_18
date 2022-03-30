#include "framework.h"
#include "ShootingGame.h"

//오브젝트 STL vector (static 으로 공유됨)
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
	printf("------------------------------------\n");

	for (int i = 0; i < gameObjects.size(); i++)
	{
		for (int j = 0; j < gameObjects.size(); j++)
		{
			if (i > j)
			{
				//객체의 충돌체 가져오기//
				BoxCollider2D boxi = gameObjects[i]->GetCollider();
				BoxCollider2D boxj = gameObjects[j]->GetCollider();

				//충돌체의 사각형 좌표 가져오기//
				float xi, yi, widthi, heighti;
				float xj, yj, widthj, heightj;

				boxi.GetBox(xi, yi, widthi, heighti);
				boxj.GetBox(xj, yj, widthj, heightj);


				string tagi = gameObjects[i]->GetTag();
				string tagj = gameObjects[j]->GetTag();

				printf("(%s , %s) ", tagi.data(), tagj.data());
			}
		}

		printf("\n");
	}

	printf("\n");
}

void ObjectManager::Draw()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Draw();			//객체 그리기
		gameObjects[i]->OnDrawGizmos(); //기즈모..그리기
	}
}

void ObjectManager::Destroy(GameObject* obj)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i] == obj)
		{
			gameObjects.erase(gameObjects.begin() + i); //포인터공간만 삭제, 객체 delete는 안함

			//객체 delete 하기
			delete obj;

			//원하는 객체를 삭제하고..반복문 종료
			break;
		}
	}
}

void ObjectManager::Clear()
{
	//목록에 있는 객체..삭제하기//
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}

	//객체 포인터 저장 공간만..전체 삭제//
	gameObjects.clear(); //STL vector에 전체삭제..함수
}