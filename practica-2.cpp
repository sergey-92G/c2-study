#include <iostream> // для cout, cin
#include <clocale> // для setlocale
#include <string> // для работы со строками

#include <cstdlib>  // для rand(), srand()
#include <ctime>    // для time()
using namespace std; // пространство имен std	

void fun_1 (int n) {
	// Цикл For выводит числа от n до n
	string res1, res2, result; //result, res1, res2 Объявляем переменные заранее
		for (int i = 0; i <= n; i++) {
			if (i > 0) { // если i больше 0, то добавляем к res1
				res1 += to_string(i) + " ";
			}
			res2 += to_string(n - i) + " "; // добавляем к res2 числа от n до 0
		}
	result = res2 + res1;
	cout << result << "\n";
}

void fun_2 (int n) {
	// рандомное числа, кол-во n
	srand(time(0)); // инициализация генератора случайных чисел

	for (int i = 1; i <= n; i++) {
		int random_number = rand() % 17+(7); // генерируем случайное число от 0 до 16
		cout << "Случайное число " << i << ": " << random_number << endl;	
		}

}

void fun_3 (int n) {
	// сумма чисел до n включительно
	int count = 0; // обнуляем счетчик

	for (int i = 1; i <= n; i++) {
		count += i; // суммируем числа от 0 до n		
	}
	cout << "Сумма чисел от 0 до " << n << " включительно: " << count << endl;
}

int menu() {
	cout << "1. Цикл от N до N\n";
	cout << "2. n случаных чисел от 7 до 23\n";
	cout << "3. Сумма от 1 до N включительно\n";
	cout << "0. Выход\n";

	int choice;
	cin >> choice;

	if (choice < 0 || choice > 3) {
		cout << "Неверный выбор. Пожалуйста, выберите пункт от 0 до 3.\n";
		return menu(); // повторно вызываем меню для корректного выбора
	}
	int n;
	switch (choice) {
		case 0:
			cout << "Выход из программы.\n";
			exit(0); // Завершаем программу
			break;
		case 1: {
			system("cls"); // очистка экрана	
			cout << "Вы выбрали пункт 1: Цикл от N до N\n";			
			cout << "Введите число N: ";
			cin >> n;
			if (n < 0) {
				cout << "Ошибка: число должно быть неотрицательным.\n";
				return menu(); // повторно вызываем меню для корректного выбора
			}
			fun_1(n);
			system("pause");   // окно осталось с результатом и сообщением
			break;
		}
		case 2:
			system("cls"); // очистка экрана	
			cout << "Вы выбрали пункт 2: n случаных чисел от 7 до 23\n";
			cout << "Введите число N: ";
			cin >> n;
			if (n == 0) {
				cout << "Ошибка: число не должно быть нулем.\n";
				return menu(); // повторно вызываем меню для корректного выбора
			}
			cout << "Вы ввели число: " << n << "; \n";
			fun_2(n);// << endl;
			system("pause");   // окно осталось с результатом и сообщением
			break;
		case 3:
			system("cls"); // очистка экрана	
			cout << "Вы выбрали пункт 3: Сумма от 1 до N включительно\n";
			cout << "Введите число n: ";
			int n;
			cin >> n;
			if (n <= 0) {
				cout << "Число должно быть положительным.\n";
				return menu(); // повторно вызываем меню для корректного выбора
			}
			fun_3(n); // вызываем функцию для подсчета суммы чисел
			system("pause");   // окно осталось с результатом и сообщением
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
		system("cls"); // очистка экрана
		menu();
	}
}