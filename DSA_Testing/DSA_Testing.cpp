#include <string>
#include <stack>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int minimum_number = 10;
    int max_number = 30;

    int random = rand();
    int out = random % (max_number - minimum_number + 1) + minimum_number;

    cout << out;

/*
    int min = 10;
    int max = 20;

    for (int i = 0; i < 15; i++)

    {
        int num = std::min(rand() % (max - min + 1), max);


        cout << num << endl;
    }
    */
}
