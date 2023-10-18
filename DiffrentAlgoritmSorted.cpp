#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

//Задаём различные размерности для массивов различных типов
#define ARRAY_SIZE1 10000
#define ARRAY_SIZE2 20000
#define ARRAY_SIZE3 30000
#define ARRAY_SIZE4 40000
#define ARRAY_SIZE5 50000
#define ARRAY_SIZE6 60000


// Функция для изменения цвета текста в консоли
void setConsoleColor(int colorCode) {
    cout << "\033[" << colorCode << "m";
}

// Функция для обмена элементов массива
template<typename T>// Шаблон типа Т, даёт возможность работать с различными типами данных
void typeSwap(T& a, T& b) {
    T temp = a;// Создаем буферную переменную temp и присваиваем ей значение переменной a
    a = b;// Присваиваем переменной a значение переменной b
    b = temp;// Присваиваем переменной b значение временной переменной temp
}

template<typename BubbleSort>// Шаблон типа BubbleSort, даёт возможность работать с различными типами данных
void universalBubbleSort(BubbleSort arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {// Проходимся по всем элементам массива, кроме последнего
        for (int j = 0; j < size - i - 1; ++j) {// Проходимся по подмассиву от начала до (size - i - 1)
            if (arr[j] > arr[j + 1]) {// Если текущий элемент больше следующего
                typeSwap(arr[j], arr[j + 1]);// Меняем их местами
            }
        }
    }
}

template<typename InsertionSort>// Шаблон типа InsertionSort, даёт возможность работать с различными типами данных
void universalInsertionSort(InsertionSort arr[], int size) {
    for (int i = 0; i < size; ++i) {// Проходимся по всем элементам массива
        InsertionSort key = arr[i];// Запоминаем текущий элемент в переменной key
        int j = i - 1;// Инициализируем индекс j предыдущим элементом

        while (j >= 0 && arr[j] > key) {// Пока индекс j больше или равен 0 и предыдущий элемент больше текущего
            arr[j + 1] = arr[j];// Перемещаем предыдущий элемент вправо
            --j;// Уменьшаем индекс j
        }

        arr[j + 1] = key;// Вставляем текущий элемент в отсортированную часть массива
    }
}

// Функция для разделения массива на подмассивы и выбора опорного элемента
template<typename Partition>// Шаблон типа Partition, даёт возможность работать с различными типами данных
int partition(Partition array[], int low, int high) {
    Partition pivot = array[high];// Выбираем опорный элемент, который будет располагаться в конце массива
    int i = low - 1;// Инициализируем индекс i на единицу меньше нижней границы

    for (int j = low; j <= high - 1; ++j) {// Проходимся по элементам массива от нижней границы до (верхней границы - 1)
        if (array[j] < pivot) {// Если текущий элемент меньше опорного
            ++i;// Увеличиваем индекс i
            typeSwap(array[i], array[j]);// Меняем местами элементы с индексами i и j
        }
    }

    typeSwap(array[i + 1], array[high]);// Помещаем опорный элемент на правильное место
    return i + 1;// Возвращаем индекс опорного элемента
}

// Функция для рекурсивного вызова быстрой сортировки
template<typename QuickSort>// Шаблон типа QuickSort, даёт возможность работать с различными типами данных
void universalQuickSort(QuickSort array[], int low, int high) {
    if (low < high) {// Проверяем, что массив содержит более одного элемента
        int pivotIndex = partition(array, low, high);// Получаем индекс опорного элемента после разделения массива
        universalQuickSort(array, low, pivotIndex - 1);// Рекурсивно сортируем левую часть массива от начала до опорного элемента
        universalQuickSort(array, pivotIndex + 1, high);// Рекурсивно сортируем правую часть массива от опорного элемента до конца
    }
}

template<typename SelectionSort>// Шаблон типа SelectionSort, даёт возможность работать с различными типами данных
void universalSelectionSort(SelectionSort array[], int size) {
    for (int i = 0; i < size - 1; ++i) {// Проходимся по всем элементам массива, кроме последнего
        int minIndex = i;// Предполагаем, что текущий элемент является минимальным

        // Находим индекс минимального элемента в оставшейся части массива
        for (int j = i + 1; j < size; ++j) {// Проходимся по элементам после текущего элемента
            if (array[j] < array[minIndex]) {// Если текущий элемент меньше предполагаемого минимального
                minIndex = j;// Обновляем индекс минимального элемента
            }
        }
        // Обмениваем текущий элемент с минимальным элементом
        swap(array[i], array[minIndex]);
    }
}

// Функция для сортировки массива методом Шелла
template<typename ShellSort>// Шаблон типа ShellSort, даёт возможность работать с различными типами данных
void universalShellSort(ShellSort array[], int size) {
    // Определяем интервал между элементами
    int interval = 1;
    while (interval < size / 3) {
        interval = interval * 3 + 1;// Интервал начинается с 1 и увеличивается по формуле interval = interval * 3 + 1
    }

    while (interval > 0) {// Пока интервал больше 0
        // Сортировка вставками с заданным интервалом
        for (int i = interval; i < size; ++i) {// Проходимся по элементам массива, начиная с элемента с индексом interval
            ShellSort key = array[i];// Запоминаем текущий элемент в переменной key
            int j = i;// Устанавливаем индекс j на текущий элемент

            while (j >= interval && array[j - interval] > key) {// Пока индекс j больше или равен интервалу и предыдущий элемент больше текущего
                array[j] = array[j - interval];// Перемещаем предыдущий элемент на текущую позицию
                j -= interval;// Уменьшаем индекс j на интервал
            }

            array[j] = key;// Вставляем текущий элемент в отсортированную часть массива
        }

        interval /= 3;// Уменьшаем интервал на треть
    }
}

template<typename shakeSort>// Шаблон типа shakeSort, даёт возможность работать с различными типами данных
void universalShakeSort(shakeSort array[], int size) {
    bool swapped = true;// Флаг для отслеживания перестановок элементов
    int start = 0;// Индекс начала неотсортированной части массива
    int end = size - 1;// Индекс конца неотсортированной части массива

    while (swapped) {// Пока выполняются перестановки элементов
        swapped = false;// Предполагаем, что перестановок не будет

        // Проход слева направо
        for (int i = start; i < end; ++i) {// Проходимся по элементам от начала до конца неотсортированной части
            if (array[i] > array[i + 1]) {// Если текущий элемент больше следующего
                swap(array[i], array[i + 1]);// Меняем их местами
                swapped = true;// Устанавливаем флаг перестановки
            }
        }

        if (!swapped) {// Если не было перестановок, значит массив уже отсортирован
            break;// Выходим из цикла
        }

        swapped = false;// Предполагаем, что перестановок не будет
        --end;// Уменьшаем индекс конца неотсортированной части

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {// Проходимся по элементам от конца до начала неотсортированной части
            if (array[i] > array[i + 1]) {// Если текущий элемент больше следующего
                swap(array[i], array[i + 1]);// Меняем их местами
                swapped = true;// Устанавливаем флаг перестановки
            }
        }

        ++start;// Устанавливаем флаг перестановки
    }
}


//Функции подсчёта времени на сортировку массивов различных типов и данных

//Подсчёт времени пузрьковой сортировки
void universalBubbleTimer(int size) {

    //Обявление массивов различных типов
    int* intArr = new int[size];
    double* doubleArr = new double[size];
    float* floatArr = new float[size];
    char* charArr = new char[size];


    //инициализация массивов рандомными числами
    for (int i = 0; i < size; i++) {
        intArr[i] = rand() % 20001 - 10000;
        doubleArr[i] = (double)rand() / RAND_MAX * 20000 - 10000;
        floatArr[i] = (float)rand() / RAND_MAX * 20000 - 10000;
        charArr[i] = char(rand() % 256);
    }


    cout << "------------Время сортировки для размера " << size << "------------" << endl;
    auto StartIntTimeBubbleSort = chrono::high_resolution_clock::now();//время начала теста
    universalBubbleSort(intArr, size);
    auto EndIntTimeBubbleSort = chrono::high_resolution_clock::now();//время конца теста
    chrono::duration<double> durationIntBubbleTime = EndIntTimeBubbleSort - StartIntTimeBubbleSort;//разность начала и конца теста для получения итогового времени
    cout << "Время сортировки для типа int: " << durationIntBubbleTime.count() << " секунд" << endl;

    //Данный алгоритм подсчёта времени используется во всех тестах
    //Так же используются одни и те же типы массивов во всех тестах
    //Вызываются лишь различные функции сортировки для массивов

    auto StartDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    universalBubbleSort(doubleArr, size);
    auto EndDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationDoubleBubbleTime = EndDoubleTimeBubbleSort - StartDoubleTimeBubbleSort;
    cout << "Время сортировки для типа double: " << durationDoubleBubbleTime.count() << " секунд" << endl;

    auto StartFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    universalBubbleSort(floatArr, size);
    auto EndFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFloatBubbleTime = EndFloatTimeBubbleSort - StartFloatTimeBubbleSort;
    cout << "Время сортировки для типа Float: " << durationFloatBubbleTime.count() << " секунд" << endl;

    auto StartCharTimeBubbleSort = chrono::high_resolution_clock::now();
    universalBubbleSort(charArr, size);
    auto EndCharTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationCharBubbleTime = EndCharTimeBubbleSort - StartCharTimeBubbleSort;
    cout << "Время сортировки для типа char: " << durationCharBubbleTime.count() << " секунд" << endl << endl;
}

//Подсчёт времени сортировки вставкой
void universalInsertionTimer(int size) {

    int* intArr = new int[size];
    double* doubleArr = new double[size];
    float* floatArr = new float[size];
    char* charArr = new char[size];

    for (int i = 0; i < size; i++) {
        intArr[i] = rand() % 20001 - 10000;
        doubleArr[i] = (double)rand() / RAND_MAX * 20000 - 10000;
        floatArr[i] = (float)rand() / RAND_MAX * 20000 - 10000;
        charArr[i] = char(rand() % 256);
    }
    cout << "------------Время сортировки для размера " << size << "------------" << endl;
    auto StartIntTimeBubbleSort = chrono::high_resolution_clock::now();
    universalInsertionSort(intArr, size);
    auto EndIntTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationIntBubbleTime = EndIntTimeBubbleSort - StartIntTimeBubbleSort;
    cout << "Время сортировки для типа int: " << durationIntBubbleTime.count() << " секунд" << endl;

    auto StartDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    universalInsertionSort(doubleArr, size);
    auto EndDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationDoubleBubbleTime = EndDoubleTimeBubbleSort - StartDoubleTimeBubbleSort;
    cout << "Время сортировки для типа double: " << durationDoubleBubbleTime.count() << " секунд" << endl;

    auto StartFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    universalInsertionSort(floatArr, size);
    auto EndFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFloatBubbleTime = EndFloatTimeBubbleSort - StartFloatTimeBubbleSort;
    cout << "Время сортировки для типа Float: " << durationFloatBubbleTime.count() << " секунд" << endl;

    auto StartCharTimeBubbleSort = chrono::high_resolution_clock::now();
    universalInsertionSort(charArr, size);
    auto EndCharTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationCharBubbleTime = EndCharTimeBubbleSort - StartCharTimeBubbleSort;
    cout << "Время сортировки для типа char: " << durationCharBubbleTime.count() << " секунд" << endl << endl;
}

//Подсчёт времени быстрой сортировки
void universalQuickTimer(int size) {

    int* intArr = new int[size];
    double* doubleArr = new double[size];
    float* floatArr = new float[size];
    char* charArr = new char[size];

    for (int i = 0; i < size; i++) {
        intArr[i] = rand() % 20001 - 10000;
        doubleArr[i] = (double)rand() / RAND_MAX * 20000 - 10000;
        floatArr[i] = (float)rand() / RAND_MAX * 20000 - 10000;
        charArr[i] = char(rand() % 256);
    }
    cout << "------------Время сортировки для размера " << size << "------------" << endl;
    auto StartIntTimeBubbleSort = chrono::high_resolution_clock::now();
    universalQuickSort(intArr, 0, size);
    auto EndIntTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationIntBubbleTime = EndIntTimeBubbleSort - StartIntTimeBubbleSort;
    cout << "Время сортировки для типа int: " << durationIntBubbleTime.count() << " секунд" << endl;

    auto StartDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    universalQuickSort(doubleArr, 0, size);
    auto EndDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationDoubleBubbleTime = EndDoubleTimeBubbleSort - StartDoubleTimeBubbleSort;
    cout << "Время сортировки для типа double: " << durationDoubleBubbleTime.count() << " секунд" << endl;

    auto StartFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    universalQuickSort(floatArr, 0, size);
    auto EndFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFloatBubbleTime = EndFloatTimeBubbleSort - StartFloatTimeBubbleSort;
    cout << "Время сортировки для типа Float: " << durationFloatBubbleTime.count() << " секунд" << endl;

    auto StartCharTimeBubbleSort = chrono::high_resolution_clock::now();
    universalQuickSort(charArr, 0, size);
    auto EndCharTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationCharBubbleTime = EndCharTimeBubbleSort - StartCharTimeBubbleSort;
    cout << "Время сортировки для типа char: " << durationCharBubbleTime.count() << " секунд" << endl << endl;
}

//Подсчёт времени сортировки выбором
void universalSelectionTimer(int size) {

    int* intArr = new int[size];
    double* doubleArr = new double[size];
    float* floatArr = new float[size];
    char* charArr = new char[size];

    for (int i = 0; i < size; i++) {
        intArr[i] = rand() % 20001 - 10000;
        doubleArr[i] = (double)rand() / RAND_MAX * 20000 - 10000;
        floatArr[i] = (float)rand() / RAND_MAX * 20000 - 10000;
        charArr[i] = char(rand() % 256);
    }
    cout << "------------Время сортировки для размера " << size << "------------" << endl;
    auto StartIntTimeBubbleSort = chrono::high_resolution_clock::now();
    universalSelectionSort(intArr, size);
    auto EndIntTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationIntBubbleTime = EndIntTimeBubbleSort - StartIntTimeBubbleSort;
    cout << "Время сортировки для типа int: " << durationIntBubbleTime.count() << " секунд" << endl;

    auto StartDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    universalSelectionSort(doubleArr, size);
    auto EndDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationDoubleBubbleTime = EndDoubleTimeBubbleSort - StartDoubleTimeBubbleSort;
    cout << "Время сортировки для типа double: " << durationDoubleBubbleTime.count() << " секунд" << endl;

    auto StartFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    universalSelectionSort(floatArr, size);
    auto EndFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFloatBubbleTime = EndFloatTimeBubbleSort - StartFloatTimeBubbleSort;
    cout << "Время сортировки для типа Float: " << durationFloatBubbleTime.count() << " секунд" << endl;

    auto StartCharTimeBubbleSort = chrono::high_resolution_clock::now();
    universalSelectionSort(charArr, size);
    auto EndCharTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationCharBubbleTime = EndCharTimeBubbleSort - StartCharTimeBubbleSort;
    cout << "Время сортировки для типа char: " << durationCharBubbleTime.count() << " секунд" << endl << endl;
}

//Подсчёт времени сортировки Шелла
void universalShellTimer(int size) {

    int* intArr = new int[size];
    double* doubleArr = new double[size];
    float* floatArr = new float[size];
    char* charArr = new char[size];

    for (int i = 0; i < size; i++) {
        intArr[i] = rand() % 20001 - 10000;
        doubleArr[i] = (double)rand() / RAND_MAX * 20000 - 10000;
        floatArr[i] = (float)rand() / RAND_MAX * 20000 - 10000;
        charArr[i] = char(rand() % 256);
    }
    cout << "------------Время сортировки для размера " << size << "------------" << endl;
    auto StartIntTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShellSort(intArr, size);
    auto EndIntTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationIntBubbleTime = EndIntTimeBubbleSort - StartIntTimeBubbleSort;
    cout << "Время сортировки для типа int: " << durationIntBubbleTime.count() << " секунд" << endl;

    auto StartDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShellSort(doubleArr, size);
    auto EndDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationDoubleBubbleTime = EndDoubleTimeBubbleSort - StartDoubleTimeBubbleSort;
    cout << "Время сортировки для типа double: " << durationDoubleBubbleTime.count() << " секунд" << endl;

    auto StartFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShellSort(floatArr, size);
    auto EndFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFloatBubbleTime = EndFloatTimeBubbleSort - StartFloatTimeBubbleSort;
    cout << "Время сортировки для типа Float: " << durationFloatBubbleTime.count() << " секунд" << endl;

    auto StartCharTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShellSort(charArr, size);
    auto EndCharTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationCharBubbleTime = EndCharTimeBubbleSort - StartCharTimeBubbleSort;
    cout << "Время сортировки для типа char: " << durationCharBubbleTime.count() << " секунд" << endl << endl;
}

//Подсчёт времени шейкерной сортировки
void universalShakeTimer(int size) {

    int* intArr = new int[size];
    double* doubleArr = new double[size];
    float* floatArr = new float[size];
    char* charArr = new char[size];

    for (int i = 0; i < size; i++) {
        intArr[i] = rand() % 20001 - 10000;
        doubleArr[i] = (double)rand() / RAND_MAX * 20000 - 10000;
        floatArr[i] = (float)rand() / RAND_MAX * 20000 - 10000;
        charArr[i] = char(rand() % 256);
    }
    cout << "------------Время сортировки для размера " << size << "------------" << endl;
    auto StartIntTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShakeSort(intArr, size);
    auto EndIntTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationIntBubbleTime = EndIntTimeBubbleSort - StartIntTimeBubbleSort;
    cout << "Время сортировки для типа int: " << durationIntBubbleTime.count() << " секунд" << endl;

    auto StartDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShakeSort(doubleArr, size);
    auto EndDoubleTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationDoubleBubbleTime = EndDoubleTimeBubbleSort - StartDoubleTimeBubbleSort;
    cout << "Время сортировки для типа double: " << durationDoubleBubbleTime.count() << " секунд" << endl;

    auto StartFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShakeSort(floatArr, size);
    auto EndFloatTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFloatBubbleTime = EndFloatTimeBubbleSort - StartFloatTimeBubbleSort;
    cout << "Время сортировки для типа Float: " << durationFloatBubbleTime.count() << " секунд" << endl;

    auto StartCharTimeBubbleSort = chrono::high_resolution_clock::now();
    universalShakeSort(charArr, size);
    auto EndCharTimeBubbleSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationCharBubbleTime = EndCharTimeBubbleSort - StartCharTimeBubbleSort;
    cout << "Время сортировки для типа char: " << durationCharBubbleTime.count() << " секунд" << endl << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");// Корректное пользование русскими символами в консоли
    srand(time(NULL));// Инициализация генератора случайных чисел

    int ArrSize[] = { ARRAY_SIZE1 ,ARRAY_SIZE2 ,ARRAY_SIZE3 ,ARRAY_SIZE4 ,ARRAY_SIZE5 ,ARRAY_SIZE6 };// Размещение всех тестовых размеров в массив

    setConsoleColor(32); // Зеленый цвет
    cout << "-------------------------Пузырьковая сортировка----------------------" << endl;
    setConsoleColor(0); // Сброс цвета (стандартный цвет)
    for (int i = 0; i < 6; i++) {//Сортировка массива с различными размерами
        universalBubbleTimer(ArrSize[i]);
    }

    setConsoleColor(32); // Зеленый цвет
    cout << "-------------------------Сортировка вставкой-------------------------" << endl;
    setConsoleColor(0); // Сброс цвета (стандартный цвет)
    for (int i = 0; i < 6; i++) {//Сортировка массива с различными размерами
        universalInsertionTimer(ArrSize[i]);
    }

    setConsoleColor(32); // Зеленый цвет
    cout << "-------------------------Быстрая сортировка-------------------------" << endl;
    setConsoleColor(0); // Сброс цвета (стандартный цвет)
    for (int i = 0; i < 6; i++) {//Сортировка массива с различными размерами
        universalQuickTimer(ArrSize[i]);
    }

    setConsoleColor(32); // Зеленый цвет
    cout << "-------------------------Сортировка выбором-------------------------" << endl;
    setConsoleColor(0); // Сброс цвета (стандартный цвет)
    for (int i = 0; i < 6; i++) {//Сортировка массива с различными размерами
        universalSelectionTimer(ArrSize[i]);
    }

    setConsoleColor(32); // Зеленый цвет
    cout << "-------------------------Сортировка Шелла-------------------------" << endl;
    setConsoleColor(0); // Сброс цвета (стандартный цвет)
    for (int i = 0; i < 6; i++) {//Сортировка массива с различными размерами
        universalShellTimer(ArrSize[i]);
    }

    setConsoleColor(32); // Зеленый цвет
    cout << "-------------------------Сортировка шейкер-------------------------" << endl;
    setConsoleColor(0); // Сброс цвета (стандартный цвет)
    for (int i = 0; i < 6; i++) {//Сортировка массива с различными размерами
        universalShakeTimer(ArrSize[i]);
    }
}
