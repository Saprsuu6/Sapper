/*int BLUE = 9, GREEN = 10, DURK_RED = 4, DURK_BLUE = 1, RED = 12,
		CYAN = 11, PINK = 13, GREY = 8, DARK_YELLOW = 6, LIGHT_YELLOW = 14,
		DARK_GREEN = 2, DARK_PINK = 5;*/
/*int EMPTY = 0, BOMB = 9;*/
// dont forget about delete [] ar
#include"Header.h"

int main() {
	setlocale(0, "C");
	int enter = 13;
	int space = 32;
	int esc = 27;
	HANDLE h = GetStdHandle(-11);
	Setings(h);
	Draw(h, 14, 0, 0, 40, 20, 4); // главная рамка
	Draw(h, 14, 44, 0, 31, 3, 0); // побочная рамка
	Draw(h, 14, 44, 3, 43, 3, 0); // побочная рамка1
	Draw(h, 14, 44, 6, 27, 3, 0); // побочная рамка2
	setlocale(0, "RUS");
	Text(h, 10, 45, 1); // текст меню
	if (Start(enter, space, esc)) { // пункты меню
		system("cls");
		int value = Complexity(h); // выбор сложности
		system("cls");
		setlocale(0, "C");
		//Load(h, 40, 3);
		system("color 32");
		int** ar = nullptr;
		int** ar_flags = nullptr;
		if (value == 1) {
			int ar_hight = 10;
			int ar_width = 20;
			Draw(h, 14, 0, 0, ar_width + 2, ar_hight + 2, 4); // главная рамка
			Draw(h, 14, ar_width + 5, 0, 15, 4, 0); // побочная рамка
			CreateMass(h, ar, ar_flags, ar_hight, ar_width); 
			GamePlay(h, ar, ar_flags, ar_hight, ar_width);
		}
		else if (value == 2) {
			int ar_hight = 15;
			int ar_width = 30;
			Draw(h, 14, 0, 0, ar_width + 2, ar_hight + 2, 4); // главная рамка
			Draw(h, 14, ar_width + 5, 0, 15, 4, 0); // побочная рамка
			CreateMass(h, ar, ar_flags, ar_hight, ar_width); ;
			GamePlay(h, ar, ar_flags, ar_hight, ar_width);
		}
		if (value == 3) {
			int ar_hight = 20;
			int ar_width = 40;
			Draw(h, 14, 0, 0, ar_width + 2, ar_hight + 2, 4); // главная рамка
			Draw(h, 14, ar_width + 5, 0, 15, 4, 0); // побочная рамка
			CreateMass(h, ar, ar_flags, ar_hight, ar_width); ;
			GamePlay(h, ar, ar_flags, ar_hight, ar_width);
		}
	}
	else if (!Start(enter, space, esc)) { // пункты меню
		system("cls");
		main();
	}
	system("pause > NULL");
}