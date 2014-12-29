#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> 
#include <time.h>
#include <conio.h>
SMALL_RECT use_rc = { 2, 1, 48, 29 };static bool hitTop;
#define consolescreenx 50
#define consolescreeny 30      
HANDLE handle;
DWORD a;

void TurnBlock(bool BlockSet[4][4])
{
	int y = 0, val;
	for (int x = 0; x < 3; x++)
	{
		val = BlockSet[x][y];
		BlockSet[x][y] = BlockSet[3 - y][x];
		BlockSet[3 - y][x] = BlockSet[3 - x][3 - y];
		BlockSet[3 - x][3 - y] = BlockSet[y][3 - x];
		BlockSet[y][3 - x] = (bool)val;
	}
	y = 1;
	{
		int x = 1;
		val = BlockSet[x][y];
		BlockSet[x][y] = BlockSet[3 - y][x];
		BlockSet[3 - y][x] = BlockSet[3 - x][3 - y];
		BlockSet[3 - x][3 - y] = BlockSet[y][3 - x];
		BlockSet[y][3 - x] = (bool)val;
	}
}
void RandBlock(bool BlockSet[4][4])
{
	srand(clock());
	unsigned int i = rand();
	switch (i % 7)
	{
	case 0:
		BlockSet[0][0] = 0; BlockSet[1][0] = 0; BlockSet[2][0] = 0; BlockSet[3][0] = 0;
		BlockSet[0][1] = 1; BlockSet[1][1] = 1; BlockSet[2][1] = 1; BlockSet[3][1] = 1;
		BlockSet[0][2] = 0; BlockSet[1][2] = 0; BlockSet[2][2] = 0; BlockSet[3][2] = 0;
		BlockSet[0][3] = 0; BlockSet[1][3] = 0; BlockSet[2][3] = 0; BlockSet[3][3] = 0;
		break;
	case 1:
		BlockSet[0][0] = 0; BlockSet[1][0] = 0; BlockSet[2][0] = 0; BlockSet[3][0] = 0;
		BlockSet[0][1] = 0; BlockSet[1][1] = 1; BlockSet[2][1] = 1; BlockSet[3][1] = 0;
		BlockSet[0][2] = 0; BlockSet[1][2] = 1; BlockSet[2][2] = 1; BlockSet[3][2] = 0;
		BlockSet[0][3] = 0; BlockSet[1][3] = 0; BlockSet[2][3] = 0; BlockSet[3][3] = 0;
		break;
	case 2:
		BlockSet[0][0] = 0; BlockSet[1][0] = 0; BlockSet[2][0] = 0; BlockSet[3][0] = 0;
		BlockSet[0][1] = 0; BlockSet[1][1] = 0; BlockSet[2][1] = 1; BlockSet[3][1] = 1;
		BlockSet[0][2] = 0; BlockSet[1][2] = 1; BlockSet[2][2] = 1; BlockSet[3][2] = 0;
		BlockSet[0][3] = 0; BlockSet[1][3] = 0; BlockSet[2][3] = 0; BlockSet[3][3] = 0;
		break;
	case 3:
		BlockSet[0][0] = 0; BlockSet[1][0] = 0; BlockSet[2][0] = 0; BlockSet[3][0] = 0;
		BlockSet[0][1] = 1; BlockSet[1][1] = 1; BlockSet[2][1] = 0; BlockSet[3][1] = 0;
		BlockSet[0][2] = 0; BlockSet[1][2] = 1; BlockSet[2][2] = 1; BlockSet[3][2] = 0;
		BlockSet[0][3] = 0; BlockSet[1][3] = 0; BlockSet[2][3] = 0; BlockSet[3][3] = 0;
		break;
	case 4:
		BlockSet[0][0] = 0; BlockSet[1][0] = 0; BlockSet[2][0] = 0; BlockSet[3][0] = 0;
		BlockSet[0][1] = 1; BlockSet[1][1] = 1; BlockSet[2][1] = 1; BlockSet[3][1] = 0;
		BlockSet[0][2] = 0; BlockSet[1][2] = 0; BlockSet[2][2] = 1; BlockSet[3][2] = 0;
		BlockSet[0][3] = 0; BlockSet[1][3] = 0; BlockSet[2][3] = 0; BlockSet[3][3] = 0;
		break;
	case 5:
		BlockSet[0][0] = 0; BlockSet[1][0] = 0; BlockSet[2][0] = 0; BlockSet[3][0] = 0;
		BlockSet[0][1] = 0; BlockSet[1][1] = 1; BlockSet[2][1] = 1; BlockSet[3][1] = 1;
		BlockSet[0][2] = 0; BlockSet[1][2] = 1; BlockSet[2][2] = 0; BlockSet[3][2] = 0;
		BlockSet[0][3] = 0; BlockSet[1][3] = 0; BlockSet[2][3] = 0; BlockSet[3][3] = 0;
		break;
	case 6:
		BlockSet[0][0] = 0; BlockSet[1][0] = 0; BlockSet[2][0] = 0; BlockSet[3][0] = 0;
		BlockSet[0][1] = 1; BlockSet[1][1] = 1; BlockSet[2][1] = 1; BlockSet[3][1] = 0;
		BlockSet[0][2] = 0; BlockSet[1][2] = 1; BlockSet[2][2] = 0; BlockSet[3][2] = 0;
		BlockSet[0][3] = 0; BlockSet[1][3] = 0; BlockSet[2][3] = 0; BlockSet[3][3] = 0;
		break;
	}
	for (unsigned int n = 0; n < i % 4; n++)
		TurnBlock(BlockSet);
}
void BackGround(HANDLE handle)
{
	for (int y1 = 0; y1 < 30; y1++)
		FillConsoleOutputAttribute(handle, NULL, 50, { 0, y1 }, &a);
	for (int y = 0; y < consolescreeny; y++)
	{
		FillConsoleOutputAttribute(handle, BACKGROUND_GREEN | BACKGROUND_INTENSITY, 2, { 0, y }, &a);
		FillConsoleOutputAttribute(handle, BACKGROUND_GREEN | BACKGROUND_INTENSITY, 2, { (consolescreenx - 2), y }, &a);
	}
	FillConsoleOutputAttribute(handle, BACKGROUND_GREEN | BACKGROUND_INTENSITY, consolescreenx, { 0, 0 }, &a);
	FillConsoleOutputAttribute(handle, BACKGROUND_GREEN | BACKGROUND_INTENSITY, consolescreenx, { 0, consolescreeny }, &a);
	WriteConsoleOutputCharacter(handle, L"         ", 9, { consolescreenx / 2 - 7, 15 }, &a);
	WriteConsoleOutputCharacter(handle, L" ", 1, { consolescreenx / 2 + 1, 16 }, &a);
	WriteConsoleOutputCharacter(handle, L" ", 1, { consolescreenx / 2 + 1, 17 }, &a);
	WriteConsoleOutputCharacter(handle, L" ", 1, { consolescreenx / 2 + 1, 18 }, &a);
	WriteConsoleOutputCharacter(handle, L" ", 1, { consolescreenx / 2 + 1, 19 }, &a);
}
void FillBlock(bool BlockSet[4][4], COORD XY, int i)
{
	WORD back;
	switch (i % 11)
	{
	case 0: back = (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); break;
	case 1: back = (BACKGROUND_RED | BACKGROUND_INTENSITY); break;
	case 2: back = (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
	case 3: back = (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
	case 4: back = (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
	case 5: back = (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE); break;
	case 6: back = (BACKGROUND_RED | BACKGROUND_INTENSITY); break;
	case 7: back = (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN); break;
	case 8: back = (BACKGROUND_BLUE | BACKGROUND_GREEN); break;
	case 9: back = (BACKGROUND_RED | BACKGROUND_GREEN); break;
	case 10: back = (BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE); break;
	default:
		break;
	}
	int x = 0, y = 0;
	for (int x1 = 0; x1 < 4; x1++)
	for (int y1 = 0; y1 < 4; y1++)
	if (BlockSet[x1][y1])
	{
		FillConsoleOutputAttribute(handle, back, 2, { XY.X + 2 * x1 + 1, XY.Y + y1 }, &a);
	}
}
void CleanBlock(bool BlockSet[4][4], COORD XY)
{
	int x = 0, y = 0;
	for (int x1 = 0; x1 < 4; x1++)
	for (int y1 = 0; y1 < 4; y1++)
	if (BlockSet[x1][y1])
	{
		FillConsoleOutputAttribute(handle, NULL, 2, { XY.X + 2 * x1 + 1, XY.Y + y1 }, &a);
	}
}
bool isHitDown(bool BlockSet[4][4], COORD XY)
{
	WORD Attribute1 = NULL;
	for (int x = 0; x < 4; x++)
	for (int y = 0; y < 3; y++)
	{
		if (BlockSet[x][y])
		if (!BlockSet[x][y + 1])
		{
			if (ReadConsoleOutputAttribute(handle, &Attribute1, 1, { XY.X + 2 * x + 1, XY.Y + y + 1 }, &a))
			if (Attribute1)
			{
				if (XY.Y + y + 1 < 5)
				{
					hitTop = true;
				}
				return true;
			}
		}
	}
	for (int x = 0; x < 4; x++)
	{
		if (BlockSet[x][3])
		{
			ReadConsoleOutputAttribute(handle, &Attribute1, 1, { XY.X + 2 * x + 1, XY.Y + 4 }, &a);
			if (Attribute1)
			{
				if (XY.Y  < 4)
				{
					hitTop = true;
				}
				return true;
			}
		}
	}
	return 0;
}
bool isHitLeft(bool BlockSet[4][4], COORD XY)
{
	WORD Attribute1 = NULL;
	for (int x = 0; x < 3; x++)
	for (int y = 0; y < 4; y++)
	{
		if (BlockSet[x][y])
		if (!BlockSet[x-1][y])
		{
			if (ReadConsoleOutputAttribute(handle, &Attribute1, 1, { XY.X + 2 * x - 1, XY.Y + y }, &a))
			if (Attribute1)
				return true;
		}
	}
	for (int y = 0; y < 4; y++)
	{
		if (BlockSet[0][y])
		{
			ReadConsoleOutputAttribute(handle, &Attribute1, 1, { XY.X - 1, XY.Y + y }, &a);
			if (Attribute1)
				return true;
		}
	}
	return 0;
}
bool isHitRight(bool BlockSet[4][4], COORD XY)
{
	WORD Attribute1 = NULL;
	for (int x = 0; x < 3; x++)
	for (int y = 0; y < 4; y++)
	{
		if (BlockSet[x][y])
		if (!BlockSet[x+1][y])
		{
			if (ReadConsoleOutputAttribute(handle, &Attribute1, 1, { XY.X + 2 * x + 3, XY.Y + y }, &a))
			if (Attribute1)
				return true;
		}
	}
	for (int y = 0; y < 4; y++)
	{
		if (BlockSet[3][y])
		{
			ReadConsoleOutputAttribute(handle, &Attribute1, 1, { XY.X + 9, XY.Y + y }, &a);
			if (Attribute1)
				return true;
		}
	}
	return 0;
}
bool isNearBlock(bool BlockSet[4][4], COORD XY)
{
	WORD Attribute1=NULL;
	for (int x = 0; x < 4;x++)
	for (int y = 0; y < 4; y++)
	{
		if (!BlockSet[x][y])
		{
			ReadConsoleOutputAttribute(handle, &Attribute1, 1, { XY.X + 2 * x + 1, XY.Y + y }, &a);
			if (Attribute1) 
				return true;
		}
	}
	return false;
}
bool DeleteFullLine()
{
	WORD Attribute; bool fullline = true;
	COORD xy = { 2, 1 };
	for (xy.Y = 29; xy.Y > 0; xy.Y--)
	{
		fullline = true;
		for (xy.X = 3; xy.X < 48; xy.X += 2)
		{
			ReadConsoleOutputAttribute(handle, &Attribute, 1, xy, &a);
			if (!Attribute) { fullline = false; break; }
		}
		if (fullline) break;

	}
	if (fullline)
	{
		for (; xy.Y>1; xy.Y--)
		for (int x = 2; x < 50; x += 2)
		{
			ReadConsoleOutputAttribute(handle, &Attribute, 1, { x, xy.Y - 1 }, &a);
			FillConsoleOutputAttribute(handle, Attribute, 2, { x, xy.Y }, &a);
		}
		return true;
	}
	return false;
}
void paintScoreFace(int score)
{
	
	char sText[20] ;
	sprintf(sText, "%d", score);
	DWORD dwNum = MultiByteToWideChar(CP_ACP, 0, sText, -1, NULL, 0);
	wchar_t *pwText;
	pwText = new wchar_t[dwNum];
	if (!pwText)
	{
		delete[]pwText;
	}
	MultiByteToWideChar(CP_ACP, 0, sText, -1, pwText, dwNum);
	FillConsoleOutputAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY|FOREGROUND_BLUE, 20, { 4, 2 }, &a);
	WriteConsoleOutputCharacter(handle, L"得分为:", 4, { 4, 2 }, &a);
	WriteConsoleOutputCharacter(handle, pwText, dwNum-1, { 12, 2 }, &a);
}
void endBackground()
{
	for (int y = 10; y < 20; y++)
		FillConsoleOutputAttribute(handle, BACKGROUND_BLUE|BACKGROUND_INTENSITY, 20, { consolescreeny/2, y }, &a);
	FillConsoleOutputAttribute(handle, BACKGROUND_BLUE | BACKGROUND_INTENSITY| FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY, 14, { consolescreenx / 2 - 7, 15 }, &a);
	WriteConsoleOutputCharacter(handle, L"you are loser!", 14, { consolescreenx/2 - 7, 15 }, &a);
}
void beginBackground()
{
	for (int y = 15; y < 20;y++)
	FillConsoleOutputAttribute(handle,  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY, 14, { consolescreenx / 2 - 7, y }, &a);
	WriteConsoleOutputCharacter(handle, L"速度为：1", 5, { consolescreenx / 2 - 7, 15 }, &a);
	WriteConsoleOutputCharacter(handle, L"2", 1, { consolescreenx / 2 +1, 16 }, &a);
	WriteConsoleOutputCharacter(handle, L"3", 1, { consolescreenx / 2 +1, 17 }, &a);
	WriteConsoleOutputCharacter(handle, L"4", 1, { consolescreenx / 2 + 1, 18 }, &a);
	WriteConsoleOutputCharacter(handle, L"5", 1, { consolescreenx / 2 + 1, 19 }, &a);
}
int main()
{
	COORD xy; DWORD time_beg; int sroce = 0,times=0; char speed;
	unsigned DELAY;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(L"CopyLeft && made by ndsry");
	SMALL_RECT rc = { 0, 0, 50, 30 };
	SetConsoleScreenBufferSize(handle, { 50 + 1, 30 + 1 });
	SetConsoleWindowInfo(handle, true, &rc);
	bool BlockSet[4][4];
	BackGround(handle);
	hitTop = false;
	beginBackground();
	speed = _getch();
	switch (speed)
	{
	case '1': DELAY = 700; break;
	case '2': DELAY = 500; break;
	case '3': DELAY = 300; break;
	case '4': DELAY = 200; break;
	case '5': DELAY = 100; break;
	default:
		DELAY = 700;
		break;
	}
	BackGround(handle);
	while (!hitTop)
	{
		/*******************************************************************************/
		xy = { 23, 1 };
		char direct;
		srand(clock());
		int i = rand();
		RandBlock(BlockSet);	
		for (int y = 1; y < 30; y++, xy.Y++)
		{
			FillBlock(BlockSet, xy, i);
			
			time_beg = clock();
			int hit = 0;
			do
			{
				/**************************************************************************/
				if (_kbhit())
				{
					hit++;
					direct = _getch();
					CleanBlock(BlockSet, xy);
					switch (direct)
					{
					case 75: if (!isHitLeft(BlockSet, xy)) xy.X -= 2;  FillBlock(BlockSet, xy, i); break;
					case 77: if (!isHitRight(BlockSet, xy)) xy.X += 2; FillBlock(BlockSet, xy, i); break;
					case 72: if (!isNearBlock(BlockSet,xy)) TurnBlock(BlockSet); FillBlock(BlockSet, xy, i); break;//存在不完善的地方，以不能变换的方式带过
					case 80: if (!isHitDown(BlockSet, xy)) xy.Y++; FillBlock(BlockSet, xy, i); break;
					}
				}
				/**************************************************************************/
			} while (((clock() - time_beg) < DELAY) && (hit<10));

			if (isHitDown(BlockSet, xy))
				break;
			else
				CleanBlock(BlockSet, xy);
			direct = 0;
		}
		/*********************************/
		times = 0;
		while (DeleteFullLine())
		{ 
			times++; 
		}
		/*******************************************************************************/
		sroce += times*times;
		paintScoreFace(sroce*100);
	}
	BackGround(handle);
	endBackground();
	while (1);
	return 0;
}