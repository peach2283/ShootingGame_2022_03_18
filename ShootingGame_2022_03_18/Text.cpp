#include "ShootingGame.h"

Text::Text(wstring text, int size, float px, float py, unsigned char r, unsigned char g, unsigned char b) : GameObject("","",true, px, py)
{
    this->text = text;
    this->size = size;

    this->r = r;
    this->g = g;
    this->b = b;
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
            FT_Set_Pixel_Sizes(face, size, size);
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

        //글자 출력 사각형안에서..위치 재조정..값들
        int left = face->glyph->bitmap_left;
        int top  = face->glyph->bitmap_top;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char data = buffer[y * width + x];

                if (data != 0)
                {
                    float a = data / 255.0f;  //알파값 (0 ~1 사이값으로..변환)

                    //배경색 가져오기
                    unsigned char br, bg, bb;
                    GetPixel(fontx + x + left, fonty + y - top, br, bg, bb);

                    //배경색과 폰트색 블렌딩(알파블렌딩)
                    unsigned char fr = a * r  + (1 - a) * br;
                    unsigned char fg = a * g  + (1 - a) * bg;
                    unsigned char fb = a * b  + (1 - a) * bb;

                    SetPixel(fontx + x + left, fonty + y - top, fr, fg, fb);
                }                  
            }          
        }

        //한 글자 출력 후...해당 글자 만틈..이동하기
        fontx = fontx + face->glyph->advance.x / 64;
        fonty = fonty - face->glyph->advance.y / 64;
    }
}