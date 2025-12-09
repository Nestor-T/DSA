/*Задание 3: Списък
Задача 2: Да се състави програма, чрез която се въвежда естествено число N от интервала [10..100]. 
Да се генерират N броя псевдослучайни естествени числа от интервала [1..1000]. Числата да бъдат записани 
в сортиран вид в едносвързан списък. Програмата да изведе: всички елементи на списъка, 
минималния елемент и средната стойност на въведените елементи.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct item {
    int data;
    item* next;
} *front = NULL;


void print()
{
    item* curr = front;
    if (curr == NULL)
    {
        cout << "EMPTY" << endl;
        return;
    }
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }

}

void insert_l(int data)
{
    item* newitem = new item;
    newitem->data = data;
    if (front == NULL || front->data >= newitem->data)
    {
        newitem->next = front;
        front = newitem;
    }
    else
    {
        item* curr = front;
        item* prev = NULL;
        while (curr != NULL && curr->data < data)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newitem;
        newitem->next = curr;
    }
}

int main()
{
    int n;
    cout << "N= ";
    cin >> n;

    srand(time(NULL));

    int minimum_number = 10;
    int max_number = 100;

    for (int i = 0; i < n; i++)
    {
        int random = rand();
        int randomNum = random % (max_number - minimum_number + 1) + minimum_number;
        insert_l(randomNum);
    }
    print();
}