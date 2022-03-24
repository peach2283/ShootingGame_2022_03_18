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
	//Bitmap::ReadBMP("Asset/����.bmp", 201 , 141, 190, 137, &sprite);

	Bitmap::ReadBMP("Asset/����.bmp",   1, 141, 190, 137, &sprite[0]);
	Bitmap::ReadBMP("Asset/����.bmp", 201, 141, 190, 137, &sprite[1]);
	Bitmap::ReadBMP("Asset/����.bmp", 401, 141, 190, 137, &sprite[2]);
	Bitmap::ReadBMP("Asset/����.bmp", 601, 141, 190, 137, &sprite[3]);
	
}

void Animation::Update()
{}

void Animation::Draw()
{
	//���ö���Ʈ �׸���//
	float px = GetPx();
	float py = GetPy();

	Bitmap::DrawBMP(px, py, &sprite[0]);
}