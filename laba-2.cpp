#include <iostream> // для std::cout, std::cin и т.д.
#include <clocale> // для setlocale
#include <cstdlib> // для srand и rand
#include <vector> // для std::vector    
#include <ctime> // для time
using namespace std;// пространство имен для стандартной библиотеки C++

void print_array(const vector <int> & arr) {
    //функция для вывода массива на экран
    cout << endl << "Массив: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
vector <int> avto_array (int n) {
    //функция для автоматического создания массива из случайных чисел
    int mn;
    int mx;
    cout << "Нижний предел значений = "; cin >> mn; 
    cout << "Верхний предел значений = "; cin >> mx;
    vector <int> massive(n); // создание вектора заданного размера n
    for (int i = 0; i < n; i++) {
        massive[i] =mn + rand() % (mx-mn+1); // генерация случайного числа
    }
	return massive; // возвращаем сгенерированный массив
}
int ar_max(const vector <int> & arr) {
    //функция для нахождения максимального элемента в массиве
    int max_value = arr[0]; 
	for (const int & num : arr) { // перебор каждого элемента массива
        if (num > max_value) {
            max_value = num; // обновление максимального значения
        }
    }
	return max_value; // возвращаем максимальное значение
}
int ar_min(const vector <int> & arr) {
    //функция для нахождения минимального элемента в массиве
	int min_value = arr[0]; 
    for (const int& num : arr) {
        if (num < min_value) {
			min_value = num; // обновление минимального значения    
        }
    }
	return min_value; // возвращаем минимальное значение
} 
vector <int> new_massiv(const vector <int> & arr, int diff, int x) {
    //выводит новый массив по условию 1 - больше diff; -1 - меньше diff;
    // diff - середина max-min; x (-1 or 1) условия создания
    vector <int> new_array;
    if (x > 0) {
        for (const int & num : arr) {
            if (num > diff)
                new_array.push_back(num); // 
        }
    }
    else if (x < 0) {
        for (const int& num : arr) {
            if (num < diff)
                new_array.push_back(num); // 
        }
    }    
    return new_array;
}
int count_num(const vector <int>& arr) {
    int count = 0;
    for (const int& num : arr) {
        count += 1;
    }
    return count;
}

int main() {
    setlocale(LC_ALL, ""); // для корректного отображения русских символов в консоли
	ios::sync_with_stdio(false); // отключаем синхронизацию с C-стилем ввода-вывода для ускорения работы с cin и cout
	cin.tie(nullptr); // отключаем синхронизацию с C-стилем ввода-вывода для ускорения работы с cin и cout
    srand(time(0)); // инициализация генератора случайных чисел
    
	// Начало программы
    cout << "Введите размер массива для автогенерации N = ";
	int n; // объявление переменной для размера массива
    cin >> n;
    if (n <= 0) { // проверка на корректность ввода размера массива
        cout << "Размер массива должен быть больше 0." << endl;
        return 1; // завершение программы с ошибкой
	}
	vector <int> myarray = avto_array(n); // вызов функции для автогенерации массива 
	printf("Размер массива: %d\n", n); // вывод размера массива
	print_array(myarray); // вывод сгенерированного массива на экран
	
	// Нахождение максимального и минимального элементов массива и их разницы
	int max_value = ar_max(myarray); // вызов функции для нахождения максимального элемента
	int min_value = ar_min(myarray); // вызов функции для нахождения минимального элемента
    int diff = min_value + (max_value - min_value)/2;
	cout << "Максимальный элемент массива max = " << max_value << endl; // вывод максимального элемента
	cout << "Минимальный элемент массива min = : " << min_value << endl; // вывод минимального элемента     
    cout << "Разница между max и min элементами, diff = " << diff << endl; // вывод разницы между максимальным и минимальным элементами
    
    // 2 новых массива 
    cout << "\nНовый массив где значения меньше diff";
    vector <int> mass1 = new_massiv(myarray, diff,-1);
    print_array(mass1);
    printf("Размер массива: %d\n", count_num(mass1)); // вывод размера массива
    cout << "\nНовый массив где значения больше diff";
    vector <int> mass2 = new_massiv(myarray, diff, 1);
    print_array(mass2);
    printf("Размер массива: %d\n", count_num(mass2)); // вывод размера массива
    //
    system("pause"); // пауза для просмотра результата в консоли
	return 0; // успешное завершение программы

}