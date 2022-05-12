#include "ShootingGame.h"

Scene::Scene()
{}

Scene::~Scene()
{}

void Scene::Load()
{
    //���ӸŴ���/UI �Ŵ��� �߰��ϱ�//
    ObjectManager::Instantiate(new GameManager());
    ObjectManager::Instantiate(new UIManager());

    //���, �÷��̾� ��...���Ӱ�ü �ε� 
    ObjectManager::Instantiate(new GameBG(0, 0));
    ObjectManager::Instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 100), 1);

    ObjectManager::Instantiate(new EnemySpawner(WIDTH / 2, 10));
}

void Scene::Run()
{
    //��ü��� ������Ʈ
    ObjectManager::Update();

    //��ü �浹�˻�
    ObjectManager::CheckCollision();

    //���� ��� ��ü �����ϱ�//
    ObjectManager::ClearDeadObject();

    //�׸���
    ObjectManager::Draw();
}

void Scene::Unload()
{
    ObjectManager::Clear(); //���Ӱ�ü ���..��ü ����
}