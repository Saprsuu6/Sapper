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
void CreateMass(HANDLE& h);
void FillMass(HANDLE& h, int ar[][38], const int& ar_hight, const int& ar_width);
void GamePlay(HANDLE& h, int ar[][38], const int& ar_hight, const int& ar_width);
int AllBomb(int ar[][38], const int& ar_hight, const int& ar_width);
void IfBomb(HANDLE& h, int ar[][38], const int& ar_hight, const int& ar_width, int& x, int& y);
void ChoseColor(HANDLE& h, int ar[][38], const int& ar_hight, const int& ar_width);
void LastMessage();
int main();