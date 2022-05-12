#include "ShootingGame.h"

Scene::Scene()
{}

Scene::~Scene()
{}

void Scene::Load()
{
    //게임매니저/UI 매니저 추가하기//
    ObjectManager::Instantiate(new GameManager());
    ObjectManager::Instantiate(new UIManager());

    //배경, 플레이어 등...게임객체 로딩 
    ObjectManager::Instantiate(new GameBG(0, 0));
    ObjectManager::Instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 100), 1);

    ObjectManager::Instantiate(new EnemySpawner(WIDTH / 2, 10));
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