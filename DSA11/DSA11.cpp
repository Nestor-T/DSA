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
	{
		cout << "Found node: " << current->data << endl;
		if (current->left != NULL)
			cout << "Left node value: " << current->left->data << endl;
		else
			cout << "Left node value: NULL" << endl;

		if (current->right != NULL)
			cout << "Right node value: " << current->right->data << endl;
		else
			cout << "Right node value: NULL" << endl;

		return current;
	}

	if (value < current->data)
		return find(current->left, value);
	else
		return find(current->right, value);
}

int find_min(node* current)
{
	if (current == NULL)
		return -1;

	if (current->left == NULL)
		return current->data;

	return find_min(current->left);
}

int find_max(node* current)
{
	if (current == NULL)
		return -1;

	if (current->right == NULL)
		return current->data;

	return find_max(current->right);
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
	int main();
	{
		int test;
		node* nodeone = NULL;
		char ch;

		do
		{
			cout << "\n1. Insert/Create\n2. Find\n3. Find Min\n4. Find Max\n5. Print tree\n6. Quit\nChoose... ";
			cin >> ch;

			switch (ch)
			{
			case '1':
				cout << "Enter node (num<root left | num>root right): ";
				cin >> test;
				nodeone = insert(nodeone, test);
				break;

			case '2':
				cin >> test;
				if (find(nodeone, test) == NULL)
					cout << "Not found\n";
				break;

			case '3':
				cout << "Min = " << find_min(nodeone) << endl;
				break;

			case '4':
				cout << "Max = " << find_max(nodeone) << endl;
				break;

			case '5':
				print_tree(nodeone);
				break;
			}
		} while (ch != '6');
	}

}