#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
}

Animation::~Animation()
{}

//�ִϸ��̼� ��� �׽�Ʈ �߰� �Լ�//
void Animation::Start()
{
	//�̹���..�����̽�..�׽�Ʈ �ϱ�//
	Bitmap::ReadBMP("Asset/����.bmp", 201, 141, 190, 137, &sprite);
}

void Animation::Update()
{}

void Animation::Draw()
{}