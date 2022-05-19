#include "ShootingGame.h"

GameScene::GameScene(string name) : Scene(name)
{}

GameScene::~GameScene()
{}

void GameScene::Load()
{
    //Ÿ�ӽ�����..1�� �����ϱ�
    Time::timeScale = 1.0f;

    //���ӸŴ���/UI �Ŵ��� �߰��ϱ�//
    ObjectManager::Instantiate(new GameManager());
    ObjectManager::Instantiate(new UIManager());

    //���, �÷��̾� ��...���Ӱ�ü �ε� 
    ObjectManager::Instantiate(new GameBG(0, 0));
    ObjectManager::Instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 100), 1);

    ObjectManager::Instantiate(new EnemySpawner(WIDTH / 2, 10));

    //�ؽ�Ʈ �׽�Ʈ�ϱ�//
    //ObjectManager::Instantiate(new Text(L"Font Test123", 32,  100, 200), 6);
}