/*int BLUE = 9, GREEN = 10, DURK_RED = 4, DURK_BLUE = 1, RED = 12,
		CYAN = 11, PINK = 13, GREY = 8, DARK_YELLOW = 6, LIGHT_YELLOW = 14,
		DARK_GREEN = 2, DARK_PINK = 5;*/
/*int EMPTY = 0, BOMB = 9, FLAG = 10, OTEREMPTY = 11;*/
// dont forget about delete [] ar
#include "Header.h"

void Setings(HANDLE &h) {
	system("mode con cols=87 lines=23");
	system("title Sapper");
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(h, &info);
	system("color 32");
	srand(time(0));
}

void Draw(HANDLE &h, int colors, int x, int y, int width, int hight, char ch) {
	COORD frame{ x, y };
	SetConsoleTextAttribute(h, colors);
	for (int i = 0; i < hight; i++) {
		SetConsoleCursorPosition(h, frame);
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
	cout << " - ���� ����� � �������� ������� ���� ������ ������, � ������� 2 - � ������," << endl;
    cout << "�� ��� ��������� �������������." << endl;
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
	cout << "�������� ���������, ����� ������� ENTER:" << endl;
	cout << "����� - 1\n��������� - 2\n������ - 3\n�������: ";
}

void Load(HANDLE &h, int width, int hight) {
	COORD frame{ 22,8 };
	for (int i = 0; i < hight; i++) {
		SetConsoleCursorPosition(h, frame);
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
	SetConsoleCursorPosition(h, frame);
	setlocale(0, "RUS");
	cout << "��������...";
	setlocale(0, "C");
	frame.X = 23, frame.Y = 9;
	SetConsoleCursorPosition(h, frame);
	for (int i = 0; i < width - 2; i++) {
		int random = rand() % 200 + 50;
		cout << char(178);
		frame.X++;
		Sleep(random);
	}
	system("cls");
}

int Complexity(HANDLE &h) {
	int complexity;
	DrawSet();
	cin >> complexity;
	if (complexity == 1)
		return 1;
	else if (complexity == 2)
		return 2;
	else if (complexity == 3)
		return 3;
	else
		main();
	return complexity;
}

void Text(HANDLE &h, int colors, int x, int y) {
	COORD text{ x,y };
	SetConsoleTextAttribute(h, colors);
	SetConsoleCursorPosition(h, text);
	cout << "������� ENTER ��� ������ ����";
	text.Y += 3;
	SetConsoleCursorPosition(h, text);
	cout << "������� SPACE ��� �� ��������� ����������";
	text.Y += 3;
	SetConsoleCursorPosition(h, text);
	cout << "������� ESCAPE ��� ������";
}


bool Start(int &enter, int &space, int &esc) {
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

void LastMessage(int**& ar) {
	int message = MessageBoxA(NULL, "�� ������ ������ ������?", "�� ����������� �� ����", MB_YESNO);
	delete[]ar;
	if (message == IDYES) {
		system("cls");
		main();
	}
	else
		system("taskkill /im Sapper.exe");
}

void CreateMass(HANDLE &h, int**&ar, int ar_hight, int ar_width) {
	ar = new int*[ar_hight];
	for (int i = 0; i < ar_hight; i++)
		ar[i] = new int[ar_width];
	FillMass(h, ar, ar_hight, ar_width);
}

void FillMass(HANDLE& h, int**&ar, int ar_hight, int ar_width) {
	for (int i = 0; i < ar_hight; i++) {
		for (int j = 0; j < ar_width; j++) {
			int random = rand() % 101;
			if (random > 80)
				ar[i][j] = 9; // �����
			else
				ar[i][j] = 0; // �������
		}
	}
	ShowMass(h, ar, ar_hight, ar_width);
}

void ShowMass(HANDLE& h, int**& ar, int ar_hight, int ar_width) {
	COORD c{ 1,1 };
	for (int i = 0; i < ar_hight; i++) {
		SetConsoleCursorPosition(h, c);
		for (int j = 0; j < ar_width; j++)
			cout << ar[i][j];
		c.Y++;
	}
}

void ShowAll(HANDLE& h, int**& ar, int ar_hight, int ar_width) {
	COORD show_all{ 1,1 };
	for (int i = 0; i < ar_hight; i++) {
		SetConsoleCursorPosition(h, show_all);
		for (int j = 0; j < ar_width; j++) {
			if (ar[i][j] == 9) {
				SetConsoleTextAttribute(h, 6);
				cout << char(15);
			}
			else if (ar[i][j] > 0 && ar[i][j] < 9) {
				Choose_color(h, ar[i][j]);
				cout << ar[i][j];
			}
			else
				cout << " ";
		}
		show_all.Y++;
	}
	LastMessage(ar);
}

//void OpenEmpty(HANDLE& h, int**& ar, int ar_hight, int ar_width, int x, int y) {
//	COORD empty{ x,y };
//	for (int i = y - 1; i <= y + 3; i++) { // ����� ������� � ������� 3�3
//		SetConsoleCursorPosition(h, empty);
//		for (int j = x - 1; j <= x + 5; j++) { // ����� ������� � ������� 3�3
//			if (i >= 0 && j >= 0 && i < ar_hight && j < ar_width) {
//				if (ar[i][j] == 0) {
//					ar[i][j] = 11;
//					cout << " ";
//				}
//				else if (ar[i][j] > 0 && ar[i][j] < 9) {
//					Choose_color(h, ar[i][j]);
//					cout << ar[i][j];
//				}
//				else {
//					SetConsoleTextAttribute(h, 14);
//					cout << char(4);
//				}
//			}
//		}
//		empty.Y++;
//	}
//}

int OpenEmpty(HANDLE& h, int**& ar, int ar_hight, int ar_width, int x, int y) {
	
}

void SearchBomb(HANDLE& h, int**& ar, int ar_hight, int ar_width, int x, int y) {
	int count = 0;
	for (int i = y - 1; i <= y + 1; i++) { // ����� ����� � ������� 3�3
		for (int j = x - 1; j <= x + 1; j++) { // ����� ����� � ������� 3�3
			if (i >= 0 && j >= 0 && i < ar_hight && j < ar_width && ar[i][j] == 9)
				count++;
		}
	}
	if (count > 0)
		Write(h, ar, count, x, y);
	else if (count == 0)
		OpenEmpty(h, ar, ar_hight, ar_width, x, y);
		//OpenEmpty(h, ar, ar_hight, ar_width, x - 2, y - 1);
}

void Write(HANDLE& h, int**& ar, int count, int x, int y) {
	ar[y][x] = count;
	Choose_color(h, count);
	cout << count;
}

int AllBomb(HANDLE& h, int**& ar, int ar_hight, int ar_width) {
	int count_bomb = 0;
	for (int i = 0; i < ar_hight; i++) {
		for (int j = 0; j < ar_width; j++) {
			if (ar[i][j] == 9)
				count_bomb++;
		}
	}
	return count_bomb;
}

void ShowText(HANDLE& h, int**& ar, int ar_hight, int ar_width, int color) {
	setlocale(0, "RUS");
	COORD text{ ar_width + 6,1 };
	SetConsoleCursorPosition(h, text);
	SetConsoleTextAttribute(h, 11);
	cout << "��� ����: " << AllBomb(h, ar, ar_hight, ar_width);
	text.Y++;
	SetConsoleCursorPosition(h, text);
	SetConsoleTextAttribute(h, color);
	cout << "������: " << AllFlags(h, ar, ar_hight, ar_width) << " " << char(3) << " ";
	setlocale(0, "C");
}

void Choose_color(HANDLE& h, int count) {
	if (count == 1)
		SetConsoleTextAttribute(h, 9);
	else if (count == 2)
		SetConsoleTextAttribute(h, 10);
	else if (count == 3)
		SetConsoleTextAttribute(h, 4);
	else if (count == 4)
		SetConsoleTextAttribute(h, 1);
	else if (count == 5)
		SetConsoleTextAttribute(h, 12);
	else if (count == 6)
		SetConsoleTextAttribute(h, 11);
	else if (count == 7)
		SetConsoleTextAttribute(h, 13);
	else if (count == 8)
		SetConsoleTextAttribute(h, 8);
}

void SaveMode(HANDLE& h, int**& ar, int ar_hight, int ar_width, int x, int y) {
	if ((ar[y][x] == 0 || ar[y][x] == 9) && ar[y][x] != 11) {
		ar[y][x] = 10;
		SetConsoleTextAttribute(h, 10);
		cout << char(20);
	}
	else if (ar[y][x] == 10) {
		ar[y][x] = 0;
		SetConsoleTextAttribute(h, 14);
		cout << char(4);
	}
}

int AllFlags(HANDLE& h, int**& ar, int ar_hight, int ar_width) {
	int count_flags = 0;
	for (int i = 0; i < ar_hight; i++) {
		for (int j = 0; j < ar_width; j++) {
			if (ar[i][j] == 10)
				count_flags++;
		}
	}
	return count_flags;
}

void WinnerMessage(int**& ar) {
	int message = MessageBoxA(NULL, "�� ������ ������ ������?", "�� ����� �� ����", MB_YESNO);
	delete[]ar;
	if (message == IDYES) {
		system("cls");
		main();
	}
	else
		system("taskkill /im Sapper.exe");
}

void BombsFlags(HANDLE& h, int**& ar, int ar_hight, int ar_width) {
	if (AllFlags(h, ar, ar_hight, ar_width) == AllBomb(h, ar, ar_hight, ar_width))
		WinnerMessage(ar);
}

void GamePlay(HANDLE& h, int**& ar, int ar_hight, int ar_width) {
	ShowText(h, ar, ar_hight, ar_width, 4);
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
			int x = mouse.X - 1;
			int y = mouse.Y - 1;
			if (all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED
				&& mouse.X > 0 && mouse.X < ar_width + 1 && mouse.Y > 0 && mouse.Y < ar_hight + 1) {
				if (ar[y][x] == 9) // ���� ����� �� �����
					ShowAll(h, ar, ar_hight, ar_width);
				else if (ar[y][x] == 0) {// ���� ����� �� ����� ����
					SetConsoleCursorPosition(h, mouse);
					SearchBomb(h, ar, ar_hight, ar_width, x, y);
				}
			}
			else if (all_events[i].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED
				&& mouse.X > 0 && mouse.X < ar_width + 1 && mouse.Y > 0 && mouse.Y < ar_hight + 1) {
				SetConsoleCursorPosition(h, mouse);
				SaveMode(h, ar, ar_hight, ar_width, x, y);
				if (ar[y][x] != 11)
					ShowText(h, ar, ar_hight, ar_width, 10);
			}
			else
				ShowText(h, ar, ar_hight, ar_width, 4);
		}
	}
}