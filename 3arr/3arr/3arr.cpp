#include <iostream>
#include <ctime>
using namespace std;

#define size_x 5
#define size_y 5
#define size_z 5

void init(int ArrayX[size_x * size_y * size_z],int ArrayXYZ[size_x][size_y][size_z]) {
    int m = 0;
    for (int i = 0; i < size_x; i++){
        for (int j = 0; j < size_y; j++){
            for (int k = 0; k < size_z; k++, m++)
                ArrayXYZ[i][j][k] = size_x * size_y * size_z - m-1;
        }
    }

    for (int i = 0; i < size_x * size_y * size_z; i++)
        ArrayX[i] = i;

};

void random_init(int ArrayX[size_x * size_y * size_z], int ArrayXYZ[size_x][size_y][size_z]) {
    int m = 0;
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            for (int k = 0; k < size_z; k++, m++)
                ArrayXYZ[i][j][k] = rand() % 100; 
        }
    }

    for (int i = 0; i < size_x * size_y * size_z; i++)
        ArrayX[i] = rand() % 100;

};

void print(int ArrayX[size_x * size_y * size_z], int ArrayXYZ[size_x][size_y][size_z]) {
    cout << "\x1B[32mArrayXYZ трёхмерный массив\033[0m";
    for (int i = 0; i < size_x; i++){
        if(i!=0)
            cout << endl;
        for (int j = 0; j < size_y; j++){
                cout << endl;
            for (int k = 0; k < size_z; k++)
                cout << ArrayXYZ[i][j][k]<<" ";
        }
    }
    cout << "\n\n";

    cout << "\x1B[32mArrayX одномерный массив\033[0m" << endl;
    for (int i = 0; i < size_x * size_y * size_z; i++)
        cout << ArrayX[i] << " ";
    cout << "\n\n";
}

void swap1(int ArrayX[size_x * size_y * size_z], int ArrayXYZ[size_x][size_y][size_z]) {
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            for (int k = 0; k < size_z; k++)
                ArrayXYZ[i][j][k] = ArrayX[i * size_y * size_z + j * size_z + k];
};

void swap2(int ArrayX[size_x * size_y * size_z], int ArrayXYZ[size_x][size_y][size_z]) {
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            for (int k = 0; k < size_z; k++)
                ArrayX[i * size_y * size_z + j * size_z + k] = ArrayXYZ[i][j][k];
};

int main()
{   
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int ArrayX[size_x * size_y * size_z];
    int ArrayXYZ[size_x][size_y][size_z];
    int ansver;

    cout << "Заполнить массивы случайными числами да(1)/нет(0): ";
    cin >> ansver;
    cout << "\n";

    if(ansver)
        random_init(ArrayX, ArrayXYZ);
    else
        init(ArrayX, ArrayXYZ);

    print(ArrayX, ArrayXYZ);

    cout << "Заполнить трёхмерный мерный массив значениями одномерного(1), заполнить одномерный массив значениями трёхмерного(2): ";
    cin >> ansver;
    cout << "\n";

    switch (ansver)
    {
    case 1:swap1(ArrayX, ArrayXYZ); print(ArrayX, ArrayXYZ); break;
    case 2:swap2(ArrayX, ArrayXYZ); print(ArrayX, ArrayXYZ); break;
    default:cout << "Введено неккоректное значение!";
        break;
    }

}


