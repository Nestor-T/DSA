/*Задание 1: Рекурсивни алгоритми - видове рекурсия, използване на паметта, примери за рекурсивни алгоритми
Задача 3. Да се напише рекурсивна функция, която проверява дали две числа са взаимно прости.
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else
        return gcd(b, a % b);
}
int  iscoprime(int a, int b)
{
    if(gcd(a, b)==1) return 1;
}

int main()
{
    int a, b;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    if (iscoprime(a, b) == true) cout << "GCD = 1" << endl << "The two numbers are mutually prime.";
    else cout << "The two numbers are not mutually prime"<<endl<<"Greatest Common Divisor is " << gcd(a, b);
    return 0;
}
