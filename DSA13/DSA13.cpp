/* Задание 5: Графи
Задача 3: Преработете алгоритъма за обхождане в ширина от даден връх като използвате динамична реализация на опашка.
*/
#include <iostream>
#include<windows.h> 
#include <stack>
using namespace std;

#define MAXN 200 

const int n = 14;
const int v = 5;
const char A[MAXN][MAXN] = {
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}
};
char used[MAXN];
void DFS(int i)
{
	int k;
	used[i] = 1;
	cout << i + 1 << " ";
	for (k = 0; k < n; k++)
		if (A[i][k] && !used[k]) DFS(k);
}

void DFSF(int i)
{
    int k;
    stack<int> s;   
    s.push(i);      

    used[i] = 1;

    while (!s.empty())  
    {
        int current = s.top();  
        s.pop();
        cout << current + 1 << " ";  
        for (k = 0; k < n; k++)
        {
            if (A[current][k] && !used[k])
            {
                s.push(k);   
                used[k] = 1; 
            }
        }
    }
    cout << endl;
}

int main()
{
	int k;
	SetConsoleOutputCP(1251);
	for (k = 1; k < n; k++) used[k] = 0;
	cout << "Obhojdane v dulbochina ot vruh " << v << endl;
	DFSF(v - 1);
	cout << endl;
	return 0;
}


