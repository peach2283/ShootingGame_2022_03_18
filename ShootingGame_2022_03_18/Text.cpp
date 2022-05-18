#include "ShootingGame.h"

Text::Text(wstring text,float px, float py) : GameObject("","",true, px, py)
{
    this->text = text;
}

Text::~Text()
{
    //폰트 사용 닫기
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

void Text::Start()
{
    //폰트 라이브러리 초기화
    if (FT_Init_FreeType(&library) == 0)
    {
        //폰트 파일(ttf)로드 하기
        if (FT_New_Face(library, "Asset/Font/Medium.ttf", 0, &face) == 0)
        {
            //폰트 사용 옵션(폰트..크기)
            FT_Set_Pixel_Sizes(face, 32, 32);
        }
        else {
            printf("폰트 파일 읽기 실패\n");
        }
    }
    else {

        printf("폰트 라이브러리..초기화 실패\n");
    }
}

void Text::Update()
{}

void Text::Draw()
{
    //폰트 글자 출력 위치
    int fontx = GetPx();
    int fonty = GetPy();

    for (int i = 0; i < text.length() ; i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);

        //폰트 파일에서 찾은 글꼴만 뽑아내서... face->glyph에 저장함
        FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);

        //글꼴을 픽셀단위로...비트맵 이미지로..변환하기
        FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

        //픽셀로..화면에..출력하기
        int width  = face->glyph->bitmap.width;  //글꼴 비트맵 이미지 가로크기
        int height = face->glyph->bitmap.rows;   //글꼴 비트맵 이미지 세로크기

        unsigned char* buffer = face->glyph->bitmap.buffer;  //글꼴 이미지 비트맵 데이타

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char data = buffer[y * width + x];

                if (data != 0)
                {
                    unsigned char r = 255;
                    unsigned char g = 0;
                    unsigned char b = 0;

                    SetPixel(fontx + x, fonty + y, r, g, b);
                }                  
            }          
        }

        //한 글자 출력 후...해당 글자 만틈..이동하기
        fontx = fontx + face->glyph->advance.x / 64;
        fonty = fonty + face->glyph->advance.y / 64;
    }
}