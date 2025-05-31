#include <iostream>
#include <windows.h>
using namespace std;

int FCN(string text) {
	/*unsigned char symb = text[0];
	unsigned char symb_A = 'А';
	int num = symb - symb_A + 1;
	return num;*/
	string alf_upper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	string alf_lower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	int num;//порядковый номер первой буквы
	bool check = false;//соответствует требованиям или нет



	for (int i = 0; i < alf_upper.length(); i++) {
		if (text[0] == alf_upper[i]) {//проверяем первая буква заглавная или нет
			num = i + 1;//записываем порядковый номер этой буквы
			check = true;//проверка пройдена
			break;
		}
	}

	if (check) {//если первая проверка пройдена
		int kol = 0;//для записи кол-во символов в тексте кроме первой буквы
		for (int i = 1; i < text.length(); i++) {//перебираем текст со второго символа
			for (int j = 0; j < alf_lower.length(); j++) {//перебираем алфавит маленьких букв
				if (text[i] == alf_lower[j]) {//если символ найден
					kol++;//увеличиваем кол-во на один
					break;
				}
			}
		}
		if (kol + 1 == text.length()) {//если кол-во символов совпадает
			check = true;//записываем true то что прошло проерку
		}
		else {
			check = false;//записываем false если проверку не прошло
		}

	}


	if (check) {
		return num;//возвращаем порядковый номер если все проверки пройдены
	}
	else {
		return -1;//возвращаем -1 как ошибку
	}


}

int LEN(string text) {
	int size = 0;
	for (; text[size] != '\0'; size++);
	return size;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string LN; //фамилия
	string FN; //имя
	int YY; //2 послед цифры года поступления
	int M; //месяц поступления (2 или 9)
	int i; //номер лабораторной работы
	int CNT; //кол-во вариантов в лабораторной работе

	cout << "Введите фамилию: ";
	cin >> LN;

	cout << "Введите имя: ";
	cin >> FN;

	cout << "Введите две последние цифры года поступления: ";
	cin >> YY;

	cout << "Введите месяц поступления (номер): ";
	cin >> M;

	cout << "Введите номер лабораторной работы: ";
	cin >> i;

	cout << "Введите кол-во вариантов в лабораторной работе: ";
	cin >> CNT;

	int FCN_LN = FCN(LN);
	int LEN_LN = LEN(LN);
	int FCN_FN = FCN(FN);
	int LEN_FN = LEN(FN);

	if (FCN_LN == -1 || FCN_FN == -1) {
		cout << "Ошибка ввода данных!" << endl;
	}

	int VAR = (YY + M + FCN_LN + LEN_LN + FCN_FN + LEN_FN) * i % CNT + 1;
	cout << "Вариант: " << VAR << endl;

}