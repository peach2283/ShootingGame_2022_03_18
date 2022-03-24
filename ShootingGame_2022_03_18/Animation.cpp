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
	Bitmap::ReadBMP("Asset/적기.bmp", 201, 141, 190, 137, &sprite);
}

void Animation::Update()
{}

void Animation::Draw()
{}