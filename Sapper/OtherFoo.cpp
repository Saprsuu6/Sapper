/*int BLUE = 9, GREEN = 10, DURK_RED = 4, DURK_BLUE = 1, RED = 12,
		CYAN = 11, PINK = 13, GREY = 8, DARK_YELLOW = 6, LIGHT_YELLOW = 14,
		DARK_GREEN = 2, DARK_PINK = 5;*/
/*int EMPTY = 0, BOMB = 9, FLAG = 10, OTEREMPTY = 11;*/
//размерность char = 255.
// dont forget about delete [] ar
#include "Header.h"

void Setings(HANDLE &h) {
	system("mode con cols=87 lines=23");
	system("title Sapper");
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(h, &info);
	srand(time(0));
}

void MusikGameOver() {
	Beep(587, 500);
	Beep(523, 500);
	Beep(494, 500);
	for (int i = 0; i < 5; i++)
		Beep(466, 100);
}

void MusikStart() {
	Beep(494, 100);
	Beep(523, 100);
	Beep(587, 100);
}

void MusikWin() {
	Beep(494, 500);
	for (int i = 0; i < 2; i++)
		Beep(523, 100);
	Beep(523, 100);
	Beep(880, 500);
}

void Sponsors(HANDLE& h, string sponsor, COORD text, int color) {
	SetConsoleTextAttribute(h, color);
	for (int i = 0; i < size(sponsor); i++) {
		for (int j = 65; j < 123; j++) {
			SetConsoleCursorPosition(h, text);
			if (char(j) == sponsor[i]) {
				text.X++;
				cout << sponsor[i];
				break;
			}
			cout << char(j);
			Sleep(10);
		}
	}
}

void Sponsor(HANDLE& h, int green, int red) {
	COORD text{ 38,7 };
	SetConsoleCursorPosition(h, text);
	SetConsoleTextAttribute(h, red);
	setlocale(0, "RUS");
	cout << "Спонсоры";
	setlocale(0, "C");
	string sponsor = "GameXY";
	string sponsor2 = "BrainGameX";
	string sponsor3 = "EASports";
	text.X++;
	text.Y += 2;
	Sponsors(h, sponsor, text, green);
	text.X -= 2;
	text.Y++;
	Sponsors(h, sponsor2, text, green);
	text.X++;
	text.Y++;
	Sponsors(h, sponsor3, text, green);
	Sleep(500);
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
	cout << "Выберите сложность, затем нажмите ENTER:" << endl;
	cout << "Легко - 1\nНормально - 2\nСложно - 3\nВведите: ";
}

void Load(HANDLE &h, int width) {
	COORD load{ 37,9 };
	SetConsoleCursorPosition(h, load);
	setlocale(0, "RUS");
	cout << "Загрузка...";
	setlocale(0, "C");
	load.X = 23, load.Y = 9;
	SetConsoleCursorPosition(h, load);
	for (int i = 0; i < width - 2; i++) {
		int random = rand() % 200 + 50;
		cout << char(219);
		load.X++;
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
	cout << "Нажмите ENTER для начала игры";
	text.Y += 3;
	SetConsoleCursorPosition(h, text);
	cout << "Нажмите SPACE что бы прочитать инструкцию";
	text.Y += 3;
	SetConsoleCursorPosition(h, text);
	cout << "Нажмите ESCAPE для выхода";
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

void CreateMass(HANDLE &h, int**&ar, int**&ar_flags, int ar_hight, int ar_width) {
	ar = new int*[ar_hight];
	for (int i = 0; i < ar_hight; i++)
		ar[i] = new int[ar_width];
	ar_flags = new int* [ar_hight];
	for (int i = 0; i < ar_hight; i++)
		ar_flags[i] = new int[ar_width];
	FillMass(h, ar, ar_flags, ar_hight, ar_width);
}

void FillMass(HANDLE& h, int**&ar, int**& ar_flags, int ar_hight, int ar_width) {
	for (int i = 0; i < ar_hight; i++) {
		for (int j = 0; j < ar_width; j++) {
			int random = rand() % 101;
			if (random > 80)
				ar[i][j] = 9; // бомба
			else
				ar[i][j] = 0; // пустота
			ar_flags[i][j] = 0;
		}
	}
}

void ShowAll(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int color) {
	COORD show_all{ 1,1 };
	for (int i = 0; i < ar_hight; i++) {
		SetConsoleCursorPosition(h, show_all);
		for (int j = 0; j < ar_width; j++) {
			if (ar[i][j] == 9) {
				SetConsoleTextAttribute(h, color);
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
	MusikGameOver();
	LastMessage(ar, ar_flags, ar_hight);
}

int SearchBomb(HANDLE& h, int**& ar, int ar_hight, int ar_width, int x, int y, int& count) {
	for (int i = y - 1; i <= y + 1; i++) { // поиск бомбы в радиусе 3х3
		for (int j = x - 1; j <= x + 1; j++) { // поиск бомбы в радиусе 3х3
			if (i >= 0 && j >= 0 && i < ar_hight && j < ar_width && ar[i][j] == 9) 
				count++;
		}
	}
	return count;
}

void LastMessage(int**& ar, int**& ar_flags, int ar_hight) {
	int message = MessageBoxA(NULL, "Вы хотите начать заново?", "Вы подорвались на мине", MB_YESNO);
	DellMass(ar, ar_flags, ar_hight);
	if (message == IDYES) {
		system("cls");
		main();
	}
	else
		system("taskkill /im Sapper.exe");
}

void WinnerMessage(int**& ar, int**& ar_flags, int ar_hight) {
	int message = MessageBoxA(NULL, "Вы хотите начать заново?", "Вы нашли все мины", MB_YESNO);
	DellMass(ar, ar_flags, ar_hight);
	if (message == IDYES) {
		system("cls");
		main();
	}
	else
		system("taskkill /im Sapper.exe");
}

void DellMass(int**& ar, int**& ar_flags, int ar_hight) {
	for (int i = 0; i < ar_hight; i++) {
		delete[] ar[i];
		delete[] ar_flags[i];
	}
	delete[]ar;
	delete[]ar_flags;
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

int AllFlags(HANDLE& h, int**& ar_flags, int ar_hight, int ar_width) {
	int count_flags = 0;
	for (int i = 0; i < ar_hight; i++) {
		for (int j = 0; j < ar_width; j++) {
			if (ar_flags[i][j] == 10)
				count_flags++;
		}
	}
	return count_flags;
}

void ShowText(HANDLE& h, int**& ar, int**& ar_falgs, int ar_hight, int ar_width, int darkred, int cyan) {
	setlocale(0, "RUS");
	COORD text{ ar_width + 6,1 };
	SetConsoleCursorPosition(h, text);
	SetConsoleTextAttribute(h, cyan);
	cout << "Все бомы: " << AllBomb(h, ar, ar_hight, ar_width);
	text.Y++;
	SetConsoleCursorPosition(h, text);
	SetConsoleTextAttribute(h, darkred);
	printf("Флажки: %03d ", AllFlags(h, ar_falgs, ar_hight, ar_width));
	setlocale(0, "C");
	cout << char(3);
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

void SaveMode(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int x, int y, int pink, int yellow) {
	if (ar[y][x] != 1 && ar[y][x] != 2 && ar[y][x] != 3 && ar[y][x] != 4 && ar[y][x] != 5
		&& ar[y][x] != 6 && ar[y][x] != 7 && ar[y][x] != 8) {
		if ((ar[y][x] == 0 || ar[y][x] == 9 || ar[y][x] != 11) && ar_flags[y][x] != 10) {
			ar_flags[y][x] = 10;
			SetConsoleTextAttribute(h, pink);
			cout << char(4);
		}
		else if (ar_flags[y][x] == 10) {
			ar_flags[y][x] = 0;
			SetConsoleTextAttribute(h, yellow);
			cout << char(4);
		}
	}
}

int OpenEmpty(HANDLE& h, int**& ar, int ar_hight, int ar_width) {
	int if_empty = 0;
	for (int i = 0; i < ar_hight; i++) {
		for (int j = 0; j < ar_width; j++) {
			if (ar[i][j] == 0)
				if_empty++;
		}
	}
	return if_empty;
}

void End(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width) {
	if (OpenEmpty(h, ar, ar_hight, ar_width) == 0) {
		MusikWin();
		WinnerMessage(ar, ar_flags, ar_hight);
	}
}

void Open(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width, int& x, int& y) {
	int count = 0;
	if (ar[y][x] == 9 && ar_flags[y][x] != 10) // если нажал на бомбу
		ShowAll(h, ar, ar_flags, ar_hight, ar_width, 6);
	else if (ar[y][x] == 0 && ar_flags[y][x] != 10 && ar[y][x] != 11) { // если нажал на пусто поле
		int result = SearchBomb(h, ar, ar_hight, ar_width, x, y, count);
		if (result == 0) {
			ar[y][x] = 11;
			DrawOpen(h, ar_hight, ar_width, x, y);
			for (int i = y - 1; i <= y + 1; i++) {
				for (int j = x - 1; j <= x + 1; j++) {
					if (i >= 0 && j >= 0 && i < ar_hight && j < ar_width) {
						Open(h, ar, ar_flags, ar_hight, ar_width, j, i);
					}
				}
			}
		}
		else {
			ar[y][x] = count;
			WriteNum(h, count, x, y);
		}
	}
}

void DrawOpen(HANDLE& h, int ar_hight, int ar_width, int x, int y) {
	COORD open{ x + 1,y + 1 };
	SetConsoleCursorPosition(h, open);
	cout << " ";
}

void WriteNum(HANDLE& h, int count, int x, int y) {
	COORD num{ x + 1,y + 1 };
	SetConsoleCursorPosition(h, num);
	Choose_color(h, count);
	cout << count;
}

void GamePlay(HANDLE& h, int**& ar, int**& ar_flags, int ar_hight, int ar_width) {
	ShowText(h, ar, ar_flags, ar_hight, ar_width, 4, 11);
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
				&& (mouse.X > 0 || mouse.X < ar_width + 1 || mouse.Y > 0 || mouse.Y < ar_hight + 1)) {
				Open(h, ar, ar_flags, ar_hight, ar_width, x, y);
			}
			else if (all_events[i].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED
				&& mouse.X > 0 && mouse.X < ar_width + 1 && mouse.Y > 0 && mouse.Y < ar_hight + 1) {
				SetConsoleCursorPosition(h, mouse);
				SaveMode(h, ar, ar_flags, ar_hight, ar_width, x, y, 13, 14);
				if (ar[y][x] != 11)
					ShowText(h, ar, ar_flags, ar_hight, ar_width, 10, 11);
			}
			else
				ShowText(h, ar, ar_flags, ar_hight, ar_width, 4, 11);
			End(h, ar, ar_flags, ar_hight, ar_width);
		}
	}
}