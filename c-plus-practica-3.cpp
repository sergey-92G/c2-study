#include <iostream> // для cout, cin
#include <clocale> // для setlocale
#include <string> // для работы со строками

#include <cstdlib>  // для rand(), srand()
#include <ctime>    // для time()

#include <vector> // для работы с векторами-массивы


#include <algorithm> // для std::sort
#include <iomanip> // для std::setprecision
#include <cmath> // для математических функций, если нужно

#include <limits> // для INT_MAX, INT_MIN

using namespace std; // пространство имен std	

void print_vector (const vector<int> & vec) {
	// Функция для печати вектора
	cout << "Элементы вектора: ";
	for (const auto& elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}

void fun_1(int n) {
	// Массив вручную
	vector <int> myarray(n); // объявляем массив фиксированного размера
	for (int i = 0; i < n; i++) {
		cout << "Введите элмент массива [" << i << "]: ";
		cin >> myarray[i]; // заполняем массив
	}
	print_vector(myarray); // печатаем массив
}
void fun_2 (int n) {
	//Случайный массив до n включительно
	vector <int> myarray(n); // объявляем массив фиксированного размера
	srand(time(0)); // инициализация генератора случайных чисел
	for (int i = 0; i < n; ++i) {		
		int num_random = rand() % 100; // генерируем случайное число от 0 до 99
		myarray[i] = num_random; // заполняем массив случайными числами		
	}
	print_vector(myarray); // печатаем массив
}
void fun_3(int n) {
	// Массив от 0 до N включительно
	vector <int> myarray(n); // объявляем массив фиксированного размера
	for (int i = 0; i < n; ++i) {
		myarray[i] = i; // заполняем массив числами от 0 до N
	}
	print_vector(myarray); // печатаем массив
}
void fun_4(int n) {
	// Массив значений nx2, только четные
	vector <int> myarray(n); // объявляем массив фиксированного размера
	for (int i = 1; i < n+1; ++i) { // увеличиваем размер массива в 2 раза
		myarray[i-1] = i*2; // заполняем массив числами от 0 до N
	}
	print_vector(myarray); // печатаем массив
}
void fun_6(int n) {
	// Массив от 0 до N (min, max, avg)
	vector <int> myarray(n); // объявляем массив фиксированного размера	
	srand(time(0)); // инициализация генератора случайных чисел
	for (int i = 0; i < n; ++i) {
		myarray[i] = rand() % 100; // генерируем случайное число от 0 до 99
	}
	print_vector(myarray); // печатаем исходный массив
	int max_val = INT_MIN; // минимально возможное значение
	int min_val = INT_MAX; // максимально возможное значение
	double sum = 0.0;
	for (const auto& elem : myarray) {
		if (elem < min_val) min_val = elem;
		if (elem > max_val) max_val = elem;
		sum += elem;
	}
	double avg = sum / myarray.size();
	cout << "Минимальное значение: " << min_val << endl;
	cout << "Максимальное значение: " << max_val << endl;
	cout << "Среднее значение: " << setprecision(2) << fixed << avg << endl;
}
void fun_7(int n) {
	// Массив от 0 до N (+отсортировать min-max)
	vector <int> myarray(n); // объявляем массив фиксированного размера
	srand(time(0)); // инициализация генератора случайных чисел
	for (int i = 0; i < n; ++i) {
		myarray[i] = rand() % 100; // генерируем случайное число от 0 до 99
	}
	print_vector(myarray); // печатаем исходный массив

	sort(myarray.begin(), myarray.end()); // сортируем массив по возрастанию
	cout << "Отсортированный массив: ";
	print_vector(myarray); // печатаем отсортированный массив

}


int menu() {
	cout << "1. Массив вручную\n";
	cout << "2. Массив случайно\n";
	cout << "3. Массив от 0 до N\n";
	cout << "4. Массив от 0 до N (х на 2 четные)\n";
	cout << "5. неясно пр студентов\n";
	cout << "6. Массив от 0 до N (min, max, avg)\n";
	cout << "7. Массив от 0 до N (+отсортировать min-max)\n";
	cout << "0. Выход\n";

	int choice;
	cin >> choice;

	if (choice < 0 || choice > 7) {
		cout << "Неверный выбор. Пожалуйста, выберите пункт от 0 до 7.\n";
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
		cout << "1. Массив вручную\n";
		cout << "Введите число N: ";
		cin >> n;

		if (n <= 0) {
			cout << "Ошибка: число должно быть >0.\n";
			return menu(); // повторно вызываем меню для корректного выбора
		}

		fun_1(n);
		system("pause");   // окно осталось с результатом и сообщением
		break;
	}
	case 2: {
		system("cls"); // очистка экрана	
		cout << "Вы выбрали пункт 2: Массив случайно\n";
		cout << "Введите число N: ";
		cin >> n;
		if (n <= 0) {
			cout << "Ошибка: число должно быть >0.\n";
			return menu(); // повторно вызываем меню для корректного выбора
		}
		fun_2(n);
		system("pause");   // окно осталось с результатом и сообщением
		break;
	}
	case 3: {
		system("cls"); // очистка экрана	
		cout << "Вы выбрали пункт 3: Массив от 0 до N\n";
		cout << "Введите число N: ";
		cin >> n;
		if (n <= 0) {
			cout << "Ошибка: число должно быть >0.\n";
			return menu(); // повторно вызываем меню для корректного выбора
		}
		fun_3(n);
		system("pause");   // окно осталось с результатом и сообщением
		break;
	}
	case 4: {
		system("cls"); // очистка экрана	
		cout << "Вы выбрали пункт 3: Массив от 0 до N (х на 2 четные)\n";
		cout << "Введите число N: ";
		cin >> n;
		if (n <= 0) {
			cout << "Ошибка: число должно быть >0.\n";
			return menu(); // повторно вызываем меню для корректного выбора
		}
		fun_4(n);
		system("pause");   // окно осталось с результатом и сообщением
		break;
	}
	case 5: {
		system("cls"); // очистка экрана	
		cout << "Вы выбрали пункт 5: неясно пр студентов\n";
		cout << "Введите число N: ";
		cin >> n;
		if (n <= 0) {
			cout << "Ошибка: число должно быть >0.\n";
			return menu(); // повторно вызываем меню для корректного выбора
		}
		// Здесь можно добавить логику для обработки студентов
		cout << "Функционал не реализован.\n";
		system("pause");   // окно осталось с результатом и сообщением
		break;
	}
	case 6: {
		system("cls"); // очистка экрана	
		cout << "Вы выбрали пункт 6: Массив от 0 до N (min, max, avg)\n";
		cout << "Введите число N: ";
		cin >> n;
		if (n <= 0) {
			cout << "Ошибка: число должно быть >0.\n";
			return menu(); // повторно вызываем меню для корректного выбора
		}
		fun_6(n); // Здесь должна быть функция для обработки массива и вычисления min, max, avg
		system("pause");   // окно осталось с результатом и сообщением
		break;
	}
	case 7: {
		system("cls"); // очистка экрана	
		cout << "Вы выбрали пункт 7: Массив от 0 до N (+отсортировать min-max)\n";
		cout << "Введите число N: ";
		cin >> n;
		if (n <= 0) {
			cout << "Ошибка: число должно быть >0.\n";
			return menu(); // повторно вызываем меню для корректного выбора
		}
		fun_7(n); // Здесь должна быть функция для обработки массива и вычисления min, max, avg
		system("pause");   // окно осталось с результатом и сообщением
		break;
	}
	default:
		cout << "Неверный выбор. Пожалуйста, выберите пункт от 0 до 7.\n";
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