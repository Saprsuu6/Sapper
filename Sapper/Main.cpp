#include"Header.h"

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

