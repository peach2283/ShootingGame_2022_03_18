#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

#define MAX_LAYER 8

class ObjectManager
{
private:
	static vector<GameObject*> gameObjects[MAX_LAYER];
public:

	//게임 Instance 추가 및 제거 //
	static void Instantiate(GameObject* obj, int layer=0);
	static void Destroy(GameObject* obj);

	//게임 목록 업데이트 함수
	static void Update();

	//게임 객체 충돌검사 함수
	static void CheckCollision();
	static void CheckCollisionObjectPair(GameObject* obji, GameObject* objj);

	//게임 목록 그리기
	static void Draw();

	//게임 목록 모두 삭제하기 함수
	static void Clear();

	//삭제 대상으로 표시된 객체들 삭제하기 함수//
	static void ClearDeadObject();
};

