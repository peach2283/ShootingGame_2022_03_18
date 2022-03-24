#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
}

Animation::~Animation()
{}

//애니메이션 기능 테스트 추가 함수//
void Animation::Start()
{
	//이미지..슬라이스..테스트 하기//
	//Bitmap::ReadBMP("Asset/적기.bmp", 201 , 141, 190, 137, &sprite);

	Bitmap::ReadBMP("Asset/적기.bmp",   1, 141, 190, 137, &sprite[0]);
	Bitmap::ReadBMP("Asset/적기.bmp", 201, 141, 190, 137, &sprite[1]);
	Bitmap::ReadBMP("Asset/적기.bmp", 401, 141, 190, 137, &sprite[2]);
	Bitmap::ReadBMP("Asset/적기.bmp", 601, 141, 190, 137, &sprite[3]);
	
}

void Animation::Update()
{}

void Animation::Draw()
{
	//스플라이트 그리기//
	float px = GetPx();
	float py = GetPy();

	Bitmap::DrawBMP(px, py, &sprite[0]);
}