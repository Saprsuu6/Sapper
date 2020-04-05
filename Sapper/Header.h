#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include <string>
using namespace std;

void Setings(HANDLE &h);
void Draw(HANDLE &h, int colors, int x, int y, int width, int hight, char ch);
void Instruction();
void RealyExit();
int Complexity(HANDLE &h);
void Text(HANDLE &h, int colors, int x, int y);
bool Start(int &enter, int &space, int &esc);
void Load(HANDLE &h, int width);
void CreateMass(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
void FillMass(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
void GamePlay(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
int SearchBomb(HANDLE& h, int**& ar, int ar_hight, int ar_width, int x, int y, int& count);
void Choose_color(HANDLE& h, int count);
void WriteNum(HANDLE& h, int count, int x, int y);
void LastMessage(int**& ar, int**& ar_flags, int ar_hight);
int AllBomb(HANDLE& h, int**& ar, int ar_hight, int ar_width);
void SaveMode(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int x, int y, int pink, int yellow);
void End(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width);
void WinnerMessage(int**& ar, int**& ar_flags, int ar_hight);
void ShowText(HANDLE& h, int**& ar, int**& ar_falgs, int ar_hight, int ar_width, int darkred, int cyan);
int AllFlags(HANDLE& h, int**& ar, int ar_hight, int ar_width);
void ShowAll(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int color);
void DellMass(int**& ar, int**& ar_flags, int ar_hight);
void Open(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int& x, int& y);
void DrawOpen(HANDLE& h, int ar_hight, int ar_width, int x, int y);
void Sponsor(HANDLE& h, int green, int red);
void Sponsors(HANDLE& h, string sponsor, COORD text, int color);
void MusikGameOver();
void MusikStart();
int main();