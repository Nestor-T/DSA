/*Задание 4: Дървовидни структури от данни. Двоични дървета за търсене
Задача 1. Да се напише програма, която 1. Въвежда 2. Извежда елементите на двоично дърво за търсене  
с целочислени елементи по метода:

дясно_поддърво - корен - ляво_поддърво (ДКЛ)

корен - ляво_поддърво – дясно_поддърво (КЛД)
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

void print_tree_LKD(node* current)
{
	if (current == NULL)
		return;
	print_tree_LKD(current->left);
	cout << current->data << endl;
	print_tree_LKD(current->right);
}

void print_tree_DKL(node* current)
{
	if (current == NULL)
		return;
	print_tree_DKL(current->right);
	cout << current->data << endl;
	print_tree_DKL(current->left);
}

int main()
{
	//8, 10,11,14,15,16
	node* nodeone = newnode(8);
	insert(nodeone, 10);
	insert(nodeone, 11);
	insert(nodeone, 14);
	insert(nodeone, 15);
	insert(nodeone, 16);

	cout << "Left - Root - Right" << endl;
	print_tree_LKD(nodeone);

	cout << "Right - Root - Left" << endl;
	print_tree_DKL(nodeone);
}
