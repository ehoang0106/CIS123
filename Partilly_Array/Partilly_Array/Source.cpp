#include <iostream>

using namespace std;

const int MAX_ARRAY_SIZE = 10;

void addNumber(int arr[], int& numItemsInArray);

// Returns the index of 'target' in the array.
// Or -1 if 'target' is not found
int findIndex(int arr[], int numItemsInArray, int target);

void viewNumbers(int arr[], int numItemsInArray);

void deleteNumber(int arr[], int& numItemsInArray);

int main()
{
    int nums[MAX_ARRAY_SIZE];

    // To track the logical size
    int numItemsInArray = 0;
    char option;
    do
    {
        cout << "a) View the Numbers. b) Add a Number. c) Remove a number. q) Quit: ";
        cin >> option;
        if (option == 'a')
        {
            viewNumbers(nums, numItemsInArray);
        }
        else if (option == 'b')
        {
            // This function adds a number to the array if possible,
            // numItemsInArray is passed by reference and changed
            addNumber(nums, numItemsInArray);
        }
        else if (option == 'c')
        {
            deleteNumber(nums, numItemsInArray);
        }
    } while (option != 'q');

    return 0;
}

int findIndex(int arr[], int numItemsInArray, int target)
{
    for (int i = 0; i < numItemsInArray; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    // We didn't return, so we never found 'target'
    return -1;
}

void addNumber(int arr[], int& numItemsInArray)
{
    // Ask the user to enter a number. Make sure it's not a duplicate!
    // Add it if there is room
    if (numItemsInArray >= MAX_ARRAY_SIZE)
    {
        cout << "Array is full!" << endl;
        return;
    }

    int newNum;
    cout << "Enter a number: ";
    cin >> newNum;

    // Add the number if it is not in the array yet
    if (findIndex(arr, numItemsInArray, newNum) == -1)
    {
        arr[numItemsInArray] = newNum;
        numItemsInArray++;
    }
    else
    {
        cout << "Can't add duplicates!" << endl;
    }
}

void viewNumbers(int arr[], int numItemsInArray)
{
    for (int i = 0; i < numItemsInArray; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteNumber(int arr[], int& numItemsInArray)
{
    int numToDelete;
    cout << "What value do you want to remove from the array? ";
    cin >> numToDelete;

    // Get the index of the item we're deleting
    int index = findIndex(arr, numItemsInArray, numToDelete);
    if (index == -1)
    {
        cout << "That number is not in the array" << endl;
    }
    else
    {
        for (int i = index; i < numItemsInArray - 1; i++)
        {
            // Shift element i + 1 one index left
            arr[i] = arr[i + 1];
        }
        numItemsInArray--;
    }
}