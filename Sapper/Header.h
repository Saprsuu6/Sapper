// dont forget about delete [] ar
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

void Setings(HANDLE &h);
void Draw(HANDLE &h, int &colors, int &x, int &y, int &width, int &hight, char &ch);
void Instruction();
void RealyExit();
int Complexity(HANDLE &h);
void Text(HANDLE &h, int &colors, int &x, int &y);
bool Start(int &enter, int &space, int &esc);
void Load(HANDLE &h, int &width, int &hight);
void CreateMass(const int r_hight, const int ar_width);
void FillMass(int** ar, const int ar_hight, const int ar_width);
void ShowMass(int** ar, const int ar_hight, const int ar_width);
//void GamePlay(int**** pr_ar, const int*** pr_hight, const int*** pr_width);
int main();