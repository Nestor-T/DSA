/* Задание 5: Графи

Задача 1: Даден е следният неориентиран граф (виж частта Instructions how to perform). 
Как може да се опише чрез матрица на съседство?

Матрица 1 - неориентирана

  1 2 3 4 5 6
1 0 0 1 0 0 0
2 0 0 0 1 0 0
3 1 0 0 1 1 0
4 0 1 1 0 0 1
5 0 0 1 0 0 1
6 0 0 0 1 1 0

Задача 2: Даден е следният ориентиран граф (виж частта Instructions how to perform). 
Как може да се опише чрез матрица на съседство?

Матрица 2 - ориентиран

  1 2 3 4 5 6
1 0 0 1 0 0 0
2 0 0 0 1 0 0
3 0 0 0 1 1 0
4 0 0 0 0 0 1
5 0 0 0 0 0 1
6 0 0 0 0 0 0

Задача 3: Преработете алгоритъма за обхождане в ширина от даден връх като използвате динамична реализация на опашка.
*/
#include<iostream>
#include<windows.h>
using namespace std;

struct item
{
	int value;
	item* next;
}*back = NULL, * front = NULL;

void push(int value)
{
    item* temp = new item;  
    temp->value = value;    

    temp->next = NULL;  
    if (back == NULL)   
    {
        back = temp;
        front = temp;   
    }
    else
    {
        back->next = temp; 
        back = temp;       
    }
}

void pop()
{
    if (front != NULL)
    {
        item* temp = front;
        front = front->next;
        delete temp;
        if (front == NULL)
            back = NULL;
    }
}

/* Максимален брой върхове в графа */
#define MAXN 200 
/* Брой върхове в графа */
const int n = 14;
/* Обхождане в ширина с начало връх v */
const int v = 3;
/* Матрица на съседство на графа */
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


void BFS(int i)
{
    int k, j, p;
    for (k = 0; k < n; k++)used[k] = 0;
    used[i] = 1;
    front = back = NULL;
    push(i);

    while (front != NULL){
        p = front->value; 
        cout << p + 1 << " "; 
        pop(); 
        for (j = 0; j < n; j++){
            if (A[p][j] && !used[j]) {
                push(j); 
                used[j] = 1; 
            }
        }
    }
    cout << endl;
}

int main(void)
{
	SetConsoleOutputCP(1251);
	cout << " Obhojdane v shirina ot vruh " << v << endl;
	BFS(v - 1);
	return 0;
}
