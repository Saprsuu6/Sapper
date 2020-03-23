// dont forget about delete [] ar
#include"Header.h"

int main() {
	setlocale(0, "C");
	int enter = 13, space = 32, esc = 27;
	int pos_x = 0, pos_y = 0, width = 40, hight = 20; char char_ = 4; // главная рамка
	int pos2_x = 44, pos2_y = 0, width2 = 31, hight2 = 3; char char2_ = 0; // побочная рамка
	int pos3_x = 44, pos3_y = 3, width3 = 43, hight3 = 3; char char3_ = 0; // побочная рамка1
	int pos4_x = 44, pos4_y = 6, width4 = 27, hight4 = 3; char char4_ = 0; // побочная рамка2
	int menu_x = 45, menu_y = 1; // текс меню
	int load_x = 40, load_y = 3; // окно загрузки
	int BLUE = 9, GREEN = 10, DURK_RED = 4, DURK_BLUE = 1, RED = 12,
		CYAN = 11, PINK = 13, GREY = 8, DARK_YELLOW = 6, LIGHT_YELLOW = 14,
		DARK_GREEN = 2, DARK_PINK = 5;
	HANDLE h = GetStdHandle(-11);

	Setings(h);
	Draw(h, LIGHT_YELLOW, pos_x, pos_y, width, hight, char_); // главная рамка
	Draw(h, LIGHT_YELLOW, pos2_x, pos2_y, width2, hight2, char2_); // побочная рамка
	Draw(h, LIGHT_YELLOW, pos3_x, pos3_y, width3, hight3, char3_); // побочная рамка1
	Draw(h, LIGHT_YELLOW, pos4_x, pos4_y, width4, hight4, char4_); // побочная рамка2
	setlocale(0, "RUS");
	Text(h, GREEN, menu_x, menu_y); // текст меню
	if (Start(enter, space, esc)) { // пункты меню
		system("cls");
		int value = Complexity(h); // выбор сложности
		if (value == 1) {
			const int ar_hight = 10;
			const int ar_width = 20;
			Load(h, load_x, load_y);
			CreateMass(&ar_hight, &ar_width);
		}
		else if (value == 2) {
			const int ar_hight = 15;
			const int ar_width = 30;
			Load(h, load_x, load_y);
			CreateMass(&ar_hight, &ar_width);
		}
		else if (value == 3) {
			const int ar_hight = 20;
			const int ar_width = 40;
			Load(h, load_x, load_y);
			CreateMass(&ar_hight, &ar_width);
		}
	}
	else if (!Start(enter, space, esc)) { // пункты меню
		system("cls");
		main();
	}
	system("pause > NULL");
}