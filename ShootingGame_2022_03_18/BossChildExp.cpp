#include "ShootingGame.h"

BossChildExp::BossChildExp(float px, float py) : Animation("","", true, px, py)
{}

BossChildExp::~BossChildExp()
{}

void BossChildExp::Start()
{
    for (int x = 0; x < 8; x++)
    {
        AddSprite("Asset/Æø¹ßÈ¿°ú.bmp", x * 65, 1252, 64, 64, 0);
    }
}

void BossChildExp::Update()
{
}

void BossChildExp::OnAnimationEnd()
{
    Destroy(this);
}