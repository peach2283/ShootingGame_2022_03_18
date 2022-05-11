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
    icons[0] = Instantiate(new Icon(250, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);
    icons[1] = Instantiate(new Icon(300, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);
    icons[2] = Instantiate(new Icon(350, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);

    //���ھ�..�߰��ϱ�
    Instantiate(new Score(30, 10), 6);

    //��ź ī��Ʈ..������ �߰��ϱ�
    
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
            icons[i]->SetActive(true);
        }
        else {
            icons[i]->SetActive(false);
        }
    }

}
