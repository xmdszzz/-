#pragma warning(disable:4996)
#include<graphics.h>
#include<iostream>
#include<time.h>
#include<conio.h>
#include<queue>
using namespace std; 
IMAGE images[10];
TCHAR s[100];
int status[20] = { 1,5,6,7,3,2,0,4,8,9 };
int coordinate[20][5] = { { 0,-76 },{ 0,0 },{ 100,0 },{ 200,0 },{ 0,76 },{ 100,76 },{ 200,76 },{ 0,152 },{ 100,152 },{ 200,152 } };
int next_num[20][10] = { { -1, -1, -1, 1 },{ -1,  0,   2,  4 },{ 1, -1,  3,  5 },{ 2,-1, -1,  6 },{ -1,  1,   5, 7 },{ 4,  2,  6,  8 },{ 5,  3, -1,  9 },{ -1,  4,  8, -1 },{ 7,  5,  9, -1 },{ 8,  6, -1, -1 } };
void init()
{
	initgraph(600, 400);
	setbkcolor(WHITE);
	cleardevice();
	setorigin(150, 100);
	loadimage(&images[0], L"1\\0.png");
	loadimage(&images[1], L"1\\1.png");
	loadimage(&images[2], L"1\\2.png");
	loadimage(&images[3], L"1\\3.png");
	loadimage(&images[4], L"1\\4.png");
	loadimage(&images[5], L"1\\5.png");
	loadimage(&images[6], L"1\\6.png");
	loadimage(&images[7], L"1\\7.png");
	loadimage(&images[8], L"1\\8.png");
	loadimage(&images[9], L"1\\9.png");
}
void show()
{
	for (int i = 0; i <= 9; i++)
		putimage(coordinate[i][0], coordinate[i][1], &images[status[i]]);
}
void move()
{
	init();
	show();
	int cut = 0, l = 0;
	while (cut != 10) {
		_stprintf_s(s, _T("%d 步"), l);
		settextcolor(BLUE);
		outtextxy(-150, -100, s);
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			m.x -= 150; m.y -= 100;
			int f = 0;
			for (int i = 0; i < 10; i++)
				if (m.x > coordinate[i][0] && m.x  < coordinate[i][0] + 100 && m.y > coordinate[i][1] && m.y < coordinate[i][1] + 76) {
					for (int j = 0; j < 4; j++)
						if (next_num[i][j] >= 0 && status[next_num[i][j]] == 0) {
							swap(status[i], status[next_num[i][j]]);
							f = 1;
							l++;
							break;
						}
					if (f) break;
				}
		}
		show();
		cut = 0;
		for (int i = 0; i < 10; i++)
			if (status[i] == i)
				cut++;
	}
	_stprintf_s(s, _T("游戏通关，你一共走了%d 步"), l);
	settextcolor(RED);
	outtextxy(-150, -100, s);
	Sleep(5000);
}
int main()
{
	move();
	return 0;
}
