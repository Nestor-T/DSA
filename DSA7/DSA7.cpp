/* Задание 2: Опашка
В сервиза на магазин Техномаркет са постъпили заявки за ремонт на електроуреди. 
За всеки клиент се събират следните данни: номер на поръчката, име и фамилия на клиента, e-mail. Съставете програма,
за обработка на постъпилите заявки за ремонт чрез динамична опашка. Програмата трябва да дава следните възможности:

1. Добавяне на клиент към опашката.
2. Премахване на клиент от опашката.
3. Извеждане на имената на всички клиенти в опашката по реда на тяхното постъпване и извеждане на броя на постъпилите поръчки.
   В случай, че опашката е празна да се извежда подходящо съобщение.
4. Запис на имената на клиентите от опашката във файл
*/

#include<iostream>
#include<fstream>
using namespace std;

struct item
{
    int ID;
    int order;
    char name[10];
    char fname[10];
    char email[20];
    item* next;
}*back = NULL, * front = NULL;

void push()
{
    item* temp;
    temp = new item;
    cout << "Input ID (number):";
    cin >> temp->ID;
    cout << "Input Order ID (number):";
    cin >> temp->order;
    cout << "Input First Name (text):";
    cin >> temp->name;
    cout << "Input Family Name (text):";
    cin >> temp->fname;
    cout << "Input email (text):";
    cin >> temp->email;

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
        cout << front->ID << " is deleted \n";
        front = front->next;
        delete temp;
        if (front == NULL)
            back = NULL;
    }
    else
        cout << "Queue is empty.." << endl;
}
void print()
{
    cout << "Current elements in queue" << endl;
    item* temp = front;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->ID <<" " << temp->order <<" " << temp->name <<" " <<temp -> fname<<" " << temp->email << endl;
        temp = temp->next;
    }
    cout << endl;
}

void exportfile() 
{
    ofstream MyFile("ClientList.txt");
    cout << "Client list exported to a file." << endl;
    item* temp = front;
    cout << endl;
    while (temp != NULL)
    {
        MyFile << temp->ID << " " << temp->order << " " << temp->name << " " << temp->fname << " " << temp->email << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    char ch;
    do
    {
        cout << "1. Insert\n2. Delete\n3. Display\n4. Export\n5. Quit\nChoose... ";
        cin >> ch;
        switch (ch)
        {
        case '1': push();break;
        case '2': pop();break;
        case '3': print();break;
        case '4': exportfile();break;
        }
    } while (ch != '5');
}
