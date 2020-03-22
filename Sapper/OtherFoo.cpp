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
	cout << " - Число в ячейке показывает, сколько мин скрыто вокруг данной ячейки." << endl;
	cout << "Это число поможет понять вам, где находятся безопасные ячейки, а где находятся бомбы." << endl;
	cout << " - Если рядом с открытой ячейкой есть пустая ячейка, то она откроется автоматически." << endl;
	cout << " - Если вы открыли ячейку с миной, то игра проиграна." << endl;
	cout << " - Что бы пометить ячейку(или наоборот), в которой находится бомба, нажмите её правой кнопкой мыши." << endl;
	cout << " - Если в ячейке указано число, оно показывает, сколько мин скрыто в восьми ячейках вокруг данной." << endl;
	cout << "Это число помогает понять, где находятся безопасные ячейки." << endl;
	cout << " - Игра продолжается до тех пор, пока вы не откроете все не заминированные ячейки." << endl;
	cout << "\n Удачной игры ;D";
	cout << "\n\n\n\n\n\n\n\n\n\nНажмите ESCAPE для выхлда в гланое меню";
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
	int maessage = MessageBoxA(NULL, "Вы уверены, что хотите выйти", "Выход", MB_YESNO);
	if (maessage == IDYES)
		system("taskkill /im Sapper.exe");
	else if (maessage == IDNO)
		main();
}

void DrawSet() {
	setlocale(0, "RUS");
	cout << "Выберите сложность, затем нажмите ENTER:" << endl;
	cout << "Легко - 1\nНормально - 2\nСложно - 3\nВведите: ";
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
	cout << "Загрузка...";
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
	cout << "Нажмите ENTER для начала игры";
	text.Y += 3;
	SetConsoleCursorPosition(*pr_h, text);
	cout << "Нажмите SPACE что бы прочитать инструкцию";
	text.Y += 3;
	SetConsoleCursorPosition(*pr_h, text);
	cout << "Нажмите ESCAPE для выхода";
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