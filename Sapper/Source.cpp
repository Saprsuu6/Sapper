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

int main() {
	setlocale(0, "C");
	int BLUE = 9, GREEN = 10, DURK_RED = 4, DURK_BLUE = 1, RED = 12,
		CYAN = 11, PINK = 13, GREY = 8, DARK_YELLOW = 6, LIGHT_YELLOW = 14,
		DARK_GREEN = 2, DARK_PINK = 5;
	HANDLE h = GetStdHandle(-11);
	Setings(&h);
	Draw(&h, &LIGHT_YELLOW, 0, 0, 40, 20, 4); // ������� �����
	Draw(&h, &LIGHT_YELLOW, 44, 0, 31, 3, 0); // �������� �����
	Draw(&h, &LIGHT_YELLOW, 44, 3, 43, 3, 0); // �������� �����1
	Draw(&h, &LIGHT_YELLOW, 44, 6, 27, 3, 0); // �������� �����2
	setlocale(0, "RUS");
	Text(&h, &GREEN, 45, 1); // ����� ����
	if (Start(13, 32, 27)) { // ������ ����
		system("cls");
		Complexity(&h, 13); // ����� ���������
	}
	else if (!Start(13, 32, 27)) { // ������ ����
		system("cls");
		main();
	}
	system("pause > NULL");
}

void Setings(HANDLE* pr_h) {
	system("mode con cols=87 lines=23");
	system("title Sapper");
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(*pr_h, &info);
	system("color 32");
	srand(time(0));
}

void Draw(HANDLE* pr_h, int* pr_colors, int x, int y, int width, int hight, char ch) {
	COORD frame{ x, y };
	SetConsoleTextAttribute(*pr_h, *pr_colors);
	for (int i = 0; i < hight; i++) {
		SetConsoleCursorPosition(*pr_h, frame);
		for (int j = 0; j < width; j++) {
			if (i == 0 && j == 0)
				cout << char(218);
			else if (i == hight - 1 && j == 0)
				cout << char(192);
			else if (i == 0 && j == width - 1)
				cout << char(191);
			else if (i == hight - 1 && j == width - 1)
				cout << char(217);
			else if (i == 0 || i == hight - 1)
				cout << char(196);
			else if (j == 0 || j == width - 1)
				cout << char(179);
			else
				cout << char(ch);
		}
		frame.Y++;
	}
}

void Instruction() {
	cout << " - ����� � ������ ����������, ������� ��� ������ ������ ������ ������." << endl;
	cout << "��� ����� ������� ������ ���, ��� ��������� ���������� ������, � ��� ��������� �����." << endl;
	cout << " - ���� ����� � �������� ������� ���� ������ ������, �� ��� ��������� �������������." << endl;
	cout << " - ���� �� ������� ������ � �����, �� ���� ���������." << endl;
	cout << " - ��� �� �������� ������(��� ��������), � ������� ��������� �����, ������� � ������ ������� ����." << endl;
	cout << " - ���� � ������ ������� �����, ��� ����������, ������� ��� ������ � ������ ������� ������ ������." << endl;
	cout << "��� ����� �������� ������, ��� ��������� ���������� ������." << endl;
	cout << " - ���� ������������ �� ��� ���, ���� �� �� �������� ��� �� �������������� ������." << endl;
	cout << "\n ������� ���� ;D";
	cout << "\n\n\n\n\n\n\n\n\n\n������� ESCAPE ��� ������ � ������ ����";
	int code = _getch();
	if (code == 224)
		code = _getch();
	if (code == 27)
		main();
	else
		system("cls");
	Instruction();
}

void RealyExit() {
	int maessage = MessageBoxA(NULL, "�� �������, ��� ������ �����", "�����", MB_YESNO);
	if (maessage == IDYES)
		system("taskkill /im Sapper.exe");
	else if (maessage == IDNO)
		main();
}

void DrawSet() {
	setlocale(0, "RUS");
	cout << "�������� ���������, ����� ������� ENTER:" << endl;
	cout << "����� - 1\n��������� - 2\n������ - 3\n�������: ";
	setlocale(0, "C");
}

void Load(HANDLE** pr_h, int width, int hight) {
	COORD frame{ 22,8 };
	for (int i = 0; i < hight; i++) {
		SetConsoleCursorPosition(**pr_h, frame);
		for (int j = 0; j < width; j++) {
			if (i == 0 && j == 0)
				cout << char(218);
			else if (i == hight - 1 && j == 0)
				cout << char(192);
			else if (i == 0 && j == width - 1)
				cout << char(191);
			else if (i == hight - 1 && j == width - 1)
				cout << char(217);
			else if (i == 0 || i == hight - 1)
				cout << char(196);
			else if (j == 0 || j == width - 1)
				cout << char(179);
			else
				cout << " ";
		}
		frame.Y++;
	}
	frame.X = 37, frame.Y = 9;
	SetConsoleCursorPosition(**pr_h, frame);
	setlocale(0, "RUS");
	cout << "��������...";
	setlocale(0, "C");
	frame.X = 23, frame.Y = 9;
	SetConsoleCursorPosition(**pr_h, frame);
	for (int i = 0; i < width - 2; i++) {
		int random = rand() % 200 + 50;
		cout << char(178);
		frame.X++;
		Sleep(random);
	}
}

void Complexity(HANDLE* pr_h, int enter) {
	int complexity;
	DrawSet();
	cin >> complexity;
	system("cls");
	if (complexity == 1) {
		Load(&pr_h, 40, 3);
		const int ar_hight = 10;
		const int ar_width = 20;
	}
	else if (complexity == 2) {
		Load(&pr_h, 40, 3);
		const int ar_hight = 15;
		const int ar_width = 30;
	}
	else if (complexity == 3) {
		Load(&pr_h, 40, 3);
		const int ar_hight = 20;
		const int ar_width = 40;
	}
	else
		main();
}

void Text(HANDLE* pr_h, int* pr_colors, int x, int y) {
	COORD text{ x,y };
	SetConsoleTextAttribute(*pr_h, *pr_colors);
	SetConsoleCursorPosition(*pr_h, text);
	cout << "������� ENTER ��� ������ ����";
	text.Y += 3;
	SetConsoleCursorPosition(*pr_h, text);
	cout << "������� SPACE ��� �� ��������� ����������";
	text.Y += 3;
	SetConsoleCursorPosition(*pr_h, text);
	cout << "������� ESCAPE ��� ������";
}


bool Start(int enter, int space, int esc) {
	int code = _getch();
	if (code == 224)
		code = _getch();
	if (code == esc) {
		system("cls");
		RealyExit();
	}
	if (code == space) {
		system("cls");
		Instruction();
	}
	if (code == enter) {
		system("cls");
		return true;
	}
	else
		return false;
}