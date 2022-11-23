#include <iostream>
#include <string>
using namespace std;

int countMonth(int firstDay, int dayPerMonth, string month) {
    cout << "                " << month << endl << "---------------------------------------" << endl;
    cout << "Пн    " << "Вт    " << "Ср    " << "Чт    " << "Пт    " << "Сб    " << "Вс    " << endl;
    for (int i = 1; i < firstDay; i++)
        cout << "      ";
    for (int i = 1; i <= dayPerMonth; i++)
    {
        if (i <= 9)
            cout << i << "     ";
        else
            cout << i << "    ";

        if ((firstDay + i) % 7 == 1)
            cout << endl;
    }
    cout << endl;
    cout << endl;
    firstDay = (firstDay + dayPerMonth) % 7;
    if (firstDay == 0)
        firstDay = 7;
    return firstDay;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int firstDay, FebruaryInt;
    cout << "Год висакосный да(1) нет(0): ";
    cin >> FebruaryInt;
    if (FebruaryInt == 1)
        FebruaryInt = 29;
    else
        FebruaryInt = 28;
    string Month[12] = { "Январь" , "Февраль" ,"Март" , "Апрель" , "Май" , "Июнь" , "Июль" , "Август" , "Сентябрь" , "Октябрь" , "Ноябрь" , "Декабрь" };
    int dayPerMonth[12] = { 31,FebruaryInt ,31,30,31,30,31,31,30,31,30,31 };
    cout << "С какого дня недели начинается Январь (1 - понедельник, 2 - вторник и т.д.): ";
    cin >> firstDay;
    system("cls");
    for (int j = 0; j < 12; j++)
        firstDay = countMonth(firstDay, dayPerMonth[j], Month[j]);
}