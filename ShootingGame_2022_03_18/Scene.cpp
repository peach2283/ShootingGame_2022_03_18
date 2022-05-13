#include "ShootingGame.h"

Scene::Scene(string name)
{
    this->name = name;
}

Scene::~Scene()
{}

void Scene::Load()
{
}

void Scene::Run()
{
    //객체목록 업데이트
    ObjectManager::Update();

    //객체 충돌검사
    ObjectManager::CheckCollision();

    //삭제 대상 객체 제거하기//
    ObjectManager::ClearDeadObject();

    //그리기
    ObjectManager::Draw();
}

void Scene::Unload()
{
    ObjectManager::Clear(); //게임객체 목록..전체 삭제
}

string Scene::GetName()
{
    return name;
}