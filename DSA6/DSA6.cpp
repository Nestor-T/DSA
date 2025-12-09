/*Задание 1: Стек
 Даден е числов израз като низ. Да се направи проверка дали скобите в този числов израз са сложени правилно.

Вход: (1* 2) * ((5 - 6) - (7/5)))              Изход:  „Грешка – несъответствие в скобите!“
Вход: {(5 - 3)/(5 - 6)}                        Изход:  „Числовият израз е въведен правилно“
*/
#include <iostream> 
#include <stack>
#include <string>
using namespace std;

int main() {
    
    string one = "(1* 2) * ((5 - 6) - (7/5)))";
    string two = "{(5 - 3)/(5 - 6)}";
    stack<char> st;

    string input = one;// one = wrong, two = correct

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '{' || input[i] == '(' || input[i] == '[') st.push(input[i]);
        if (input[i] == '}' || input[i] == ')' || input[i] == ']') {
            if (st.empty() == true) {
                cout << "wrong"; return 0;
            }
            else st.pop();
        }
    }

    if (st.empty() == true)cout << "correct!";


    return 0;
}