#include "ShootingGame.h"

GameScene::GameScene() : Scene()
{}

GameScene::~GameScene()
{}

void GameScene::Load()
{
    //게임매니저/UI 매니저 추가하기//
    ObjectManager::Instantiate(new GameManager());
    ObjectManager::Instantiate(new UIManager());

    //배경, 플레이어 등...게임객체 로딩 
    ObjectManager::Instantiate(new GameBG(0, 0));
    ObjectManager::Instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 100), 1);

    ObjectManager::Instantiate(new EnemySpawner(WIDTH / 2, 10));
}