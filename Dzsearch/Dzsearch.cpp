#include <iostream>


using namespace std;

void InitArray(int arr[], int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void ShowArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void SortArray(int arr[], int size, int order = 1)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((order == 0 && arr[j] > arr[j + 1]) ||
                (order == 1 && arr[j] < arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int LinearSearch(int arr[], int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }

    return -1;
}

void MixArray(int arr[], int size)
{
    int temp;
    int index;

    for (int i = 0; i < size; i++)
    {
        index = rand() % size;

        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int main()
{
    srand(time(0));

    const int size1 = 10;
    int arr1[size1];

    cout << "1. Initial array:" << endl;

    InitArray(arr1, size1, 0, 100);
    ShowArray(arr1, size1);

    SortArray(arr1, size1);

    cout << "Sorted in descending order:" << endl;
    ShowArray(arr1, size1);

    SortArray(arr1, size1, 0);

    cout << "Sorted in ascending order:" << endl;
    ShowArray(arr1, size1);

    const int size2 = 10;
    int arr2[size2];

    cout << endl << "2. Initial array:" << endl;

    InitArray(arr2, size2, -20, 20);
    ShowArray(arr2, size2);

    int left = -1;
    int right = -1;

    for (int i = 0; i < size2; i++)
    {
        if (arr2[i] < 0)
        {
            if (left == -1)
            {
                left = i;
            }

            right = i;
        }
    }

    if (left == -1)
    {
        cout << "There are no negative elements." << endl;
    }
    else
    {
        cout << "Position of the first negative element: " << left << endl;
        cout << "Position of the last negative element: " << right << endl;

        SortArray(arr2 + left + 1, right - left - 1, 0);

        cout << "Array after sorting:" << endl;
        ShowArray(arr2, size2);
    }

    const int size3 = 20;
    int arr3[size3];

    cout << endl << "3. Array from 1 to 20:" << endl;

    for (int i = 0; i < size3; i++)
    {
        arr3[i] = i + 1;
    }

    MixArray(arr3, size3);
    ShowArray(arr3, size3);

    int randomNumber = rand() % 20 + 1;
    int position = LinearSearch(arr3, size3, randomNumber);

    cout << "Random number: " << randomNumber << endl;
    cout << "Position of the number: " << position << endl;

    SortArray(arr3, position, 1);
    SortArray(arr3 + position + 1, size3 - position - 1, 0);

    cout << "Array after sorting:" << endl;
    ShowArray(arr3, size3);

    return 0;
}