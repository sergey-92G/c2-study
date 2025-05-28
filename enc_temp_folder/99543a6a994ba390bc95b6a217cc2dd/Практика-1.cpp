#include <iostream>
#include <clocale>
#include <string>
using namespace std;

string fun_1 (int n) {
	// Функция для определения типа числа
	if (n >= 100 && n < 1000) {
		return "Число трехзначное.";
	}
	else if (n >= 10 && n < 100) {
		return "Число двухзначное.";
	}
	else if (n >= 0 && n < 10) {
		return "Число однозначное.";
	}
	else {
		return "Число не однозначное.";
	}
}
string fun_2 (int n) {
	// Функция для проверки числа на большее, меньшее или равное нулю
	if (n > 0) {
		return "Число положительное.";
	}
	else if (n < 0) {
		return "Число отрицательное.";
	}
	else {
		return "Число равно нулю.";
	}
}

string fun_3 (int x) {
	// Функция для поиска максимального числа из трех чисел
	int n;
	int max_num = 0; // Переменная для хранения максимального числа
	for (int i = 0; i < x; i++) {
		cout << "Введите число " << i+1 << ": ";
		cin >> n;
		if (max_num < n) {
			max_num = n; // Обновляем максимальное число, если текущее больше
		}
	}
	return "Максимальное число: " + to_string(max_num);
}

int menu() {
	cout << "1. пр1 Кол-во разрядов\n";
	cout << "2. пр1 > < = нулю\n";
	cout << "3. пр1 max() num\n";
	cout << "0. Выход\n";
	
	int choice;
	cin >> choice;

	if (choice < 0 || choice > 3) {
		cout << "Неверный выбор. Пожалуйста, выберите пункт от 0 до 3.\n";
		return menu(); // повторно вызываем меню для корректного выбора
	}

	int n = 0; // Объявляем переменную заранее
	//pair<int, string> res; // Объявляем переменную заранее

	switch (choice) {
		case 0:
			cout << "Выход из программы.\n";
			exit(0); // Завершаем программу
			break;
		case 1: {
			cout << "Вы выбрали пункт 1: Кол-во разрядов\n";
			cout << "Введите число для проверки: ";
			cin >> n;
			cout << "Вы ввели число: " << n << "; ";
			cout 
				<< fun_1(n) << std::endl;
			system("cls");    // Windows
			break;
		}
		case 2:
			cout << "Вы выбрали пункт 2: > < = нулю\n";
			cout << "Введите число для проверки: ";
			cin >> n;
			cout << "Вы ввели число: " << n << "; ";
			cout << fun_2(n) << endl;
			system("cls");    // Windows
			break;
		case 3:
			cout << "Вы выбрали пункт 3: max() num\n";
			cout << "Введите количество чисел для проверки: ";
			int x;
			cin >> x;
			if (x <= 0) {
				cout << "Количество чисел должно быть больше нуля.\n";
				return menu(); // повторно вызываем меню для корректного выбора
			}
			cout << "Вы ввели количество чисел: " << x << "; \n";
			cout << fun_3(x) << endl;
			system("cls");    // Windows
			break;
		default:
			cout << "Неверный выбор. Пожалуйста, выберите пункт от 0 до 3.\n";
			return menu(); // повторно вызываем меню для корректного выбора
	}
}

int main() {
	// подключаем русскую локаль по умолчанию ОС
	setlocale(LC_ALL, "");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		cout << "Практика по C++\n";
		cout << "Выберите пункт меню: \n";
		menu();
	}
}

//cout << "Конец программы" << endl;
//cout << "Нажмите Enter для выхода" << endl;
//cin.ignore(); // игнорируем предыдущий ввод
//cin.get(); // ждем нажатия Enter