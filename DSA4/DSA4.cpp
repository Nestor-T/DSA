/*Задание 1: Рекурсивни алгоритми - видове рекурсия, използване на паметта, примери за рекурсивни алгоритми
Задача 2. Да се напише рекурсивна функция, която извежда цифрите на въведено  естествено число n в обратен ред.
*/
#include <iostream>
using namespace std;

void PrintReverse(int n) {
    if (n == 0) return;      
    cout << n%10;     
    PrintReverse(n/10);    
}

int main()
{
    PrintReverse(1234);
}