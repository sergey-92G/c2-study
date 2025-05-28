#include <iostream>
#include <clocale>
using namespace std;

// Функция для определения типа числа
// Возвращает 1, если число трехзначное, 2 - двухзначное, 3 - однозначное, 4 - не однозначное
//деалем функцию статическую, чтобы она была доступна только в этом файле	
static int num_test (int n) { 
    if (n > 99 && n < 1000) {
        return 1; // 3-х значное
    } else if (n > 9 && n < 100) {
        return 2; // 2-х значное
    } else if (n > -10 && n < 10) {
        return 3; // однозначное
    } else {
        return 4; // не однозначное
    }
}   

//int main() {
//    // подключаем русскую локаль по умолчанию ОС
//    setlocale(LC_ALL, "");
//    int n = 0;
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout << "Введите число \n";
//    cin >> n;
//	switch (num_test(n)) {
//	case 1: 
//		cout << "Число 3-х значное" << endl;
//		break;
//	case 2:
//		cout << "Число 2-х значное" << endl;
//		break;
//	case 3:
//		cout << "Число однозначное" << endl;
//		break;
//	case 4:
//		cout << "Число не однозначное" << endl;
//		break;
//	default:
//		cout << "неизвестный тип числа" << endl;
//		break;
//    }
//
//	cout << "Конец программы" << endl;
//	cout << "Нажмите Enter для выхода" << endl;
//	cin.ignore(); // игнорируем предыдущий ввод
//	cin.get(); // ждем нажатия Enter
//
//    return 0; // Возвращаем 0 для успешного завершения программы
//}
//

int main() {
	// подключаем русскую локаль по умолчанию ОС
	setlocale(LC_ALL, "");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		cout << "Практика 1.\n" <<;
		cout 
		cout << "Введите число (или 0 для выхода): \n";
		cin >> n;
		if (n == 0) {
			break; // Выход из цикла, если введено 0
		}
		switch (num_test(n)) {
			case 1: 
				cout << "Число 3-х значное" << endl;
				break;
			case 2:
				cout << "Число 2-х значное" << endl;
				break;
			case 3:
				cout << "Число однозначное" << endl;
				break;
			case 4:
				cout << "Число не однозначное" << endl;
				break;
			default:
				cout << "неизвестный тип числа" << endl;
				break;
		}
	}



	cout << "Конец программы" << endl;
	cout << "Нажмите Enter для выхода" << endl;
	cin.ignore(); // игнорируем предыдущий ввод
	cin.get(); // ждем нажатия Enter
	return 0; // Возвращаем 0 для успешного завершения программы
}