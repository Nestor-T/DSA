/*Задание 3: Списък
Задача 1: Да се напише програма, която да въвежда в списък имената на 
студентите –име на студента (име и фамилия), факултетен номер (цяло число). Програмата да позволява:

* Въвеждане на елемент в списъка (функция insert_l). Вмъкването трябва да е реализирано по начин, така че
да се запазва сортирането във възходящ ред на студентите по полето име
* Търсене на студент по факултетен номер в списъка  (функция search_l).
* Изтриване на студент (функция delete_l). Изтриването да става по въведен факултетен номер.
* Запис на всички студенти във файл (функция save_to_file)
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct item {
    int data;
    string name;
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
        cout << curr->data << " " << curr->name << endl;
        curr = curr->next;
    }

}

void insert_l(int data)
{
    item* newitem = new item;
    newitem->data = data;
    string tempname;
    getline(cin, tempname);
    newitem->name = tempname;
    if (front == NULL || front->name.compare(newitem->name) > 0)
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

void search_l(int data) {

    if (front == NULL)
    {
        cout << "empty list";
        return;
    }
    item* curr = front;
    item* prev = NULL;
    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        cout << "Element not found" << endl;
    else
    {
        cout << "Found " << curr->name << endl;
    }
}

void delete_l(int data)
{

    if (front == NULL)
    {
        cout << "empty list";
        return;
    }
    item* curr = front;
    item* prev = NULL;
    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        cout << "Element not found" << endl;
    else
    {
        cout << "ID " << curr->data << " is deleted" << endl;
        if (prev == NULL)
            front = front->next;
        else
            prev->next = curr->next;
        delete curr;
    }
}

void exportfile() {
    if (front == NULL)
    {
        cout << "empty list";
        return;
    }
    ofstream MyFile("Export.txt");
    item* curr = front;
    item* prev = NULL;
    while (curr != NULL)
    {
        MyFile << curr->data << " " << curr->name << endl;
        prev = curr;
        curr = curr->next;
        if (curr == NULL)break;
    }
    if (curr == NULL)
        cout << "Finished exporting" << endl;
}

int main()
{

    // Append nodes to the list
    insert_l(100);
    insert_l(200);
    insert_l(300);
    insert_l(400);
    insert_l(500);

    // Showing nodes
    print();

    // Exporting to a file
    exportfile();

    // Searching for a node
    search_l(100);

    cout << "Deleting Elements" << endl;

    // Delete nodes from the list
    delete_l(200);
    delete_l(100);
    delete_l(300);
    delete_l(400);
    print();
}
