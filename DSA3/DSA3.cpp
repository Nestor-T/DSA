/*Задание 1: Рекурсивни алгоритми - видове рекурсия, използване на паметта, примери за рекурсивни алгоритми
Задача 1. Да се напише рекурсивна функция, която намира сумата от елементите на редицата x0, x1, ..., xn-1.
*/
#include <iostream>
using namespace std;

int sumarray(int array[], int i)
{
    if (i <= 0)
    {
        return 0;
    }
    return sumarray(array, i - 1) + array[i - 1];
}

int main()
{
    int test[5] = { 1,2,3,4,5 };
    cout<<sumarray(test, 5);

}
