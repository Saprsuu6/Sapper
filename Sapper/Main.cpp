// подключение собственного заголовочного файла
#include"Header.h"

int main() {
	static bool first = true; // булевская переменная для показа заставки
	setlocale(0, "C"); // установка С докализации
	int enter = 13; // АСКИ коды 
	int space = 32;	// АСКИ коды 
	int esc = 27; // АСКИ коды 
	HANDLE h = GetStdHandle(-11); // взятие дискриптора окна консоли
	Setings(h); 
	if (first) { // если  булевская переменная равна тру
		Sponsor(h, 10, 4); 
		first = false;
	}
	system("cls"); // очистка экрана
	system("color 32"); // установка цвета окна консоли
	Draw(h, 14, 0, 0, 40, 20, 4); // главная рамка
	Draw(h, 14, 44, 0, 31, 3, 0); // побочная рамка
	Draw(h, 14, 44, 3, 43, 3, 0); // побочная рамка1
	Draw(h, 14, 44, 6, 27, 3, 0); // побочная рамка2
	setlocale(0, "RUS"); // установка русской докализации
	Text(h, 10, 45, 1); // текст меню
	if (Start(enter, space, esc)) { // пункты меню
		system("cls");
		int value = Complexity(h); // выбор сложности
		system("cls");
		setlocale(0, "C");
		Draw(h, 10, 22, 8, 40, 3, 0); // рамка псевдо нагрузки
		Load(h, 40); // функция псевдо нагрузки
		MusikStart(); // функция включения узыки старта
		system("color 32");
		int** ar = nullptr; // создание указателя на указатель ни на что не указывающая
		int** ar_flags = nullptr; // создание указателя на указатель ни на что не указывающая
		if (value == 1) { // пременная сложности равна 1
			int ar_hight = 10; // переменная установки высоты сложности 1
			int ar_width = 20; // переменная установки ширины сложности 1
			Draw(h, 14, 0, 0, ar_width + 2, ar_hight + 2, 4); // главная рамка
			Draw(h, 14, ar_width + 5, 0, 16, 4, 0); // побочная рамка
			CreateMass(h, ar, ar_flags, ar_hight, ar_width); // создание массива
			GamePlay(h, ar, ar_flags, ar_hight, ar_width); // гланый геймплей
		}
		else if (value == 2) { // пременная сложности равна 2
			int ar_hight = 15; // переменная установки высоты сложности 2
			int ar_width = 30; // переменная установки ширины сложности 2
			Draw(h, 14, 0, 0, ar_width + 2, ar_hight + 2, 4); // главная рамка
			Draw(h, 14, ar_width + 5, 0, 16, 4, 0); // побочная рамка
			CreateMass(h, ar, ar_flags, ar_hight, ar_width); ;
			GamePlay(h, ar, ar_flags, ar_hight, ar_width);
		}
		if (value == 3) { // пременная сложности равна 3
			int ar_hight = 20; // переменная установки высоты сложности 3
			int ar_width = 40; // переменная установки ширины сложности 3
			Draw(h, 14, 0, 0, ar_width + 2, ar_hight + 2, 4); // главная рамка
			Draw(h, 14, ar_width + 5, 0, 16, 4, 0); // побочная рамка
			CreateMass(h, ar, ar_flags, ar_hight, ar_width); ;
			GamePlay(h, ar, ar_flags, ar_hight, ar_width);
		}
	}
	else if (!Start(enter, space, esc)) { // если функция вернула фолс
		system("cls"); 
		main(); // вызов функции мейн
	}
	system("pause > NULL"); // завершение после нажатия на любую клавишу
}