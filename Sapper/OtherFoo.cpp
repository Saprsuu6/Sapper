// dont forget about delete [] ar
#include "Header.h"

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
		CreateMass(&ar_hight, &ar_width);
	}
	else if (complexity == 2) {
		Load(&pr_h, 40, 3);
		const int ar_hight = 15;
		const int ar_width = 30;
		CreateMass(&ar_hight, &ar_width);
	}
	else if (complexity == 3) {
		Load(&pr_h, 40, 3);
		const int ar_hight = 20;
		const int ar_width = 40;
		CreateMass(&ar_hight, &ar_width);;
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

void CreateMass(const int* pr_hight, const int* pr_width) {
	int** ar = new int* [*pr_width];
	for (int i = 0; i < *pr_width; i++) 
		ar[i] = new int[*pr_hight];
	FillMass(&ar, &pr_hight, &pr_width);
}

void FillMass(int*** pr_ar, const int** pr_hight, const int** pr_width) {
	int EMPTY, BOMB = 9;
	for (int i = 0; i < **pr_hight; i++) {
		for (int j = 0; j < **pr_width; j++) {
			int random = rand() % 101;
			if (random < 21)
				*pr_ar[i][j] = BOMB;
			else 
				*pr_ar[i][j] = EMPTY;
		}
	}
	GamePlay(&pr_ar, &pr_hight, &pr_width);
}

void GamePlay(int**** pr_ar, const int*** pr_hight, const int*** pr_width) {
	COORD mouse;
	HANDLE h_in = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(h_in, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	const int events = 256;
	INPUT_RECORD all_events[events];
	DWORD read_events;
	while (true) {
		ReadConsoleInput(h_in, all_events, events, &read_events);
		for (int i = 0; i < read_events; i++) {
			mouse.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			mouse.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;
		}
	}
}