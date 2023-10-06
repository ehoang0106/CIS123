#include <iostream>

using namespace std;


int* elementShifter(int* arr, int size);


int main()
{
	int arr[] = { 5,3,2,1,5 };
	int size = 5;

	int* shiftArray = elementShifter(arr, size);

	for (int i = 0; i < size + 1; i++)
	{
		cout << shiftArray[i] << " ";
	}
	delete[] shiftArray;



	return 0;
}



int* elementShifter(int* arr, int size)
{
	//new array on the heap that is ont index larger
	int* newArr = new int[size + 1];


	//let first element = 0;

	newArr[0] = 0;

	//shift

	for (int i = 0; i < size; i++)
	{
		newArr[i + 1] = arr[i];
	}

	return newArr;
}