/*Задание 4: Дървовидни структури от данни. Двоични дървета за търсене
Задача 2. Да се напише програма, която реализира следните основни функции с двоично дърво за търсене, 
чиито елементи са цели числа:

- Вмъкване
- Търсене на елемент
- Извеждане на минимален елемент
- Извеждане на максимален елемент
- Извеждане на елементите по метода ЛКД
Избора на съответната функция да става чрез избор от меню.
*/

#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

node* newnode(int data)
{
	node* tree = new(node);
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	return(tree);
}

node* insert(node* current, int value)
{
	if (current == NULL)
	{
		return newnode(value);
	}

	else
	{
		if (value < current->data)
		{
			current->left = insert(current->left, value);
		}
		else
		{
			current->right = insert(current->right, value);
		}
		return current;
	}
}

node* find(node* current, int value)
{
	if (current == NULL)
		return NULL;
	if (current->data == value)
		return current;
	if (value < current->data)
		find(current->left, value);
	else
		find(current->right, value);
}

int find_min(node* current)
{
	if (current->left == NULL)
		return current->data;
	else
		find_min(current->left);
}

int find_max(node* current)
{
	if (current->right == NULL)
		return current->data;
	else
		find_max(current->right);
}

void print_tree(node* current)
{
	if (current == NULL)
		return;
	print_tree(current->left);
	cout << current->data << endl;
	print_tree(current->right);
}

int main()
{
	int test;
	node* nodeone=newnode(0);

	char ch;
	do
	{
		cout << "1. Insert/Create \n2. Find\n3. Find Min\n4. Find Max\n5. Print tree\n6. Quit\nChoose... ";
		cin >> ch;
		switch (ch)
		{
		case '1': cin >> test;insert(nodeone, test);break;
		case '2': cin >> test;cout<<find(nodeone, test)<<endl;break;
		case '3': cout << "Max" << find_min(nodeone) << endl;break;
		case '4': cout << "Min" << find_max(nodeone);break;
		case '5': print_tree(nodeone);break;
		}
	} while (ch != '6');
}