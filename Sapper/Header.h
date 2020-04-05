/*int BLUE = 9, GREEN = 10, DURK_RED = 4, DURK_BLUE = 1, RED = 12,
		CYAN = 11, PINK = 13, GREY = 8, DARK_YELLOW = 6, LIGHT_YELLOW = 14,
		DARK_GREEN = 2, DARK_PINK = 5;*/
/*int EMPTY = 0, BOMB = 9;*/
// dont forget about delete [] ar
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

void Setings(HANDLE &h);
void Draw(HANDLE &h, int colors, int x, int y, int width, int hight, char ch);
void Instruction();
void RealyExit();
int Complexity(HANDLE &h);
void Text(HANDLE &h, int colors, int x, int y);
bool Start(int &enter, int &space, int &esc);
void Load(HANDLE &h, int width, int hight);
void CreateMass(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
void FillMass(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
//void ShowMass(HANDLE& h, int**& ar, int ar_hight, int ar_width);
void GamePlay(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
int SearchBomb(HANDLE& h, int**& ar, int ar_hight, int ar_width, int x, int y, int& count);
void Choose_color(HANDLE& h, int count);
void WriteNum(HANDLE& h, int count, int x, int y);
void LastMessage(int**& ar, int**& ar_flags, int ar_hight);
int AllBomb(HANDLE& h, int**& ar, int ar_hight, int ar_width);
void SaveMode(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int x, int y);
void End(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
void WinnerMessage(int**& ar, int**& ar_flags, int ar_hight);
void ShowText(HANDLE& h, int**& ar, int**& ar_falgs, int ar_hight, int ar_width, int color);
int AllFlags(HANDLE& h, int**& ar, int ar_hight, int ar_width);
void ShowAll(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
void DellMass(int**& ar, int**& ar_flags, int ar_hight);
void Open(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int& x, int& y);
void DrawOpen(HANDLE& h, int ar_hight, int ar_width, int x, int y);
int main();