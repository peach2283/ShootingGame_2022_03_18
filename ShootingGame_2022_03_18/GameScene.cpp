#include "ShootingGame.h"

GameScene::GameScene() : Scene()
{}

GameScene::~GameScene()
{}

void GameScene::Load()
{
    //���ӸŴ���/UI �Ŵ��� �߰��ϱ�//
    ObjectManager::Instantiate(new GameManager());
    ObjectManager::Instantiate(new UIManager());

    //���, �÷��̾� ��...���Ӱ�ü �ε� 
    ObjectManager::Instantiate(new GameBG(0, 0));
    ObjectManager::Instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 100), 1);

    ObjectManager::Instantiate(new EnemySpawner(WIDTH / 2, 10));
}