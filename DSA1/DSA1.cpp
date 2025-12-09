/* Задание 1: Алгоритми за сортиране
2. Да се състави програма, която като входни данни има 2 едномерни сортирани масива arr1 и arr2 с размери
съответно n1 и n2, съдържащи естествени числа. Да се изведе на екрана резултата от обединението на
двата масива, като елементите на новообразувания масив са също сортирани.
*/

#include<iostream>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < n1)
        arr3[k++] = arr1[i++];

    while (j < n2)
        arr3[k++] = arr2[j++];
}

int main()
{
    int arr1[] = {1,3,5,7,9,11,113};
    const int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2,4,6,8,10,12,14,16,18,20};
    const int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);

    cout << "Merged: " << endl;
    for (int i = 0; i < n1 + n2; i++)
        cout << arr3[i] << " ";

    return 0;
}