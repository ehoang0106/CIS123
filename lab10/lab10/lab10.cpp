#include <iostream>
using namespace std;

int* duplicateArray(int* arr, int size);
int* doubleArray(int* arr, int size);
void printArray(int arr[], int size);





int main() {

    int arr[] = { 1, 2, 3, 4, 5 };
    int size = 5;

    int* dupArr = duplicateArray(arr, size);
    int* dblArr = doubleArray(arr, size);

    cout << "Original: ";
    printArray(arr, size);

    cout << "Duplicated: ";
    printArray(dupArr, size);

    cout << "Doubled: ";
    printArray(dblArr, 2 * size);

    delete[] dupArr;
    delete[] dblArr;

    return 0;
}

int* duplicateArray(int *arr, int size) 
{
    
    int *newArr = new int[size];

    for(int i = 0; i < size; i++)
    {
        *(newArr + i) = *(arr + i);

    }
    return newArr;
}

int* doubleArray(int *arr, int size) 
{
    int* newArr = new int[size * 2];

    for (int i = 0; i < size; i++) 
    {
        *(newArr + i) = *(arr + i);
    }

    for (int i = size; i < size * 2; i++) 
    {
        *(newArr +i) = 0;
    }
    return newArr;
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

