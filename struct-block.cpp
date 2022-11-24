#include <iostream>
using namespace std;
struct Block {
    int id;
    char name[50];
    int quantity;
    float stacks;
    float shulkers;
};


void input(int n, Block  *blocks) {
    for (int i = 0; i < n; i++) {
        cout << "Введите id блока: ";
        cin >> blocks[i].id;
        cout << "Введите name блока:";
        cin >> blocks[i].name;
        cout << "Введите quantity блока:";
        cin >> blocks[i].quantity;
    }

}

void stak(int n, Block* blocks) {
    for (int i = 0; i < n; i++)
        blocks[i].stacks = blocks[i].quantity / 64;
}

void shulker(int n, Block* blocks) {
    for (int i = 0; i < n; i++)
        blocks[i].shulkers = blocks[i].stacks / 27;
}


void output(int n, Block* blocks) {
    for (int i = 0; i < n; i++) {
        cout << "id блока: " << blocks[i].id;
        cout << "Название блока: " << blocks[i].name;
        cout << "Колличество блоков: " << blocks[i].quantity;
        cout << "Колличество стаков: " << blocks[i].stacks;
        cout << "Колличество шалкеров: " << blocks[i].shulkers;

    }

}


int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите колличество блоков: ";
    cin >> n;

    Block* blocks = new Block[n];


    input(n, blocks);
    stak(n, blocks);
    shulker(n, blocks);
    output(n, blocks);
}



