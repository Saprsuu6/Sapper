// dont forget about delete [] ar
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

void Setings(HANDLE* pr_h);
void Draw(HANDLE* pr_h, int* pr_colors, int x, int y, int width, int hight, char ch);
void Instruction();
void RealyExit();
void Complexity(HANDLE* pr_h, int enter);
void Text(HANDLE* pr_h, int* pr_colors, int x, int y);
bool Start(int enter, int space, int esc);
void Load(HANDLE** pr_h, int width, int hight);
void CreateMass(const int* pr_hight, const int* pr_width);
void FillMass(int*** pr_ar, const int** pr_hight, const int** pr_width);
int main();