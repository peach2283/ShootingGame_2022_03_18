#include "ShootingGame.h"

UIManager::UIManager() : GameObject("","",true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::Start()
{
    //�Ͻ����� ��ư..�߰��ϱ�
    Instantiate(new Pause(430, 5), 6);

    //�˾� �޴�..�߰��ϱ�
    popupMenu = Instantiate(new PopupMenu(122, 300), 6);

    //ü�¹� �߰��ϱ�
    hpBar = Instantiate(new HPBar(30, 48), 6);

    //�÷��̾�..ī��Ʈ..������ �߰��ϱ�
    playerIcons[0] = Instantiate(new Icon(250, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);
    playerIcons[1] = Instantiate(new Icon(300, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);
    playerIcons[2] = Instantiate(new Icon(350, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);

    //���ھ�..�߰��ϱ�
    score = Instantiate(new Score(30, 10), 6);

    //��ź ī��Ʈ..������ �߰��ϱ�
    bombIcons[0] = Instantiate(new Icon(10 + 25 * 0 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);
    bombIcons[1] = Instantiate(new Icon(10 + 25 * 1 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);
    bombIcons[2] = Instantiate(new Icon(10 + 25 * 2 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);
    bombIcons[3] = Instantiate(new Icon(10 + 25 * 3 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);

    bombIcons[4] = Instantiate(new Icon(10 + 25 * 4 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);
    bombIcons[5] = Instantiate(new Icon(10 + 25 * 5 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);
    bombIcons[6] = Instantiate(new Icon(10 + 25 * 6 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);
    bombIcons[7] = Instantiate(new Icon(10 + 25 * 7 , 740, "Asset/UI/Icon/BombIcon.bmp"), 6);    
}

void UIManager::Update()
{
    //���ӸŴ���..��������//
    GameManager* manager = GameManager::Instance();

    //�������� ��ư..UI
    if (manager->GetPause() == true)
    {
        popupMenu->SetActive(true);
    }
    else {
        popupMenu->SetActive(false);
    }

    //�÷��̾� ü�¹�
    float hp=manager->GetPlayerHp();

    ((HPBar*)hpBar)->SetFillAmount(hp/100); 

    //�÷��̾� ī��Ʈ
    int count = manager->GetPlayerCount();

    for (int i = 0; i < 3; i++)
    {
        if (i < count)
        {
            playerIcons[i]->SetActive(true);
        }
        else {
            playerIcons[i]->SetActive(false);
        }
    }

    //��ź����..ī��Ʈ
    count = manager->GetBombCount();

    for (int i = 0; i < 8; i++)
    {
        if (i < count)
        {
            bombIcons[i]->SetActive(true);
        }
        else {
            bombIcons[i]->SetActive(false);
        }
    }

    //��������..ǥ���ϱ�
    int s = manager->GetScore();
    ((Score*)score)->SetScore(s);
}
