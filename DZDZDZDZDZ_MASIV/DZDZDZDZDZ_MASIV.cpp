#include <iostream>

using namespace std;

class Array
{
    long* arr;
    int size;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    Array(int size)
    {
        this->size = size;
        arr = new long[size];

        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    Array(const Array& other)
    {
        this->size = other.size;
        this->arr = new long[size];

        for (int i = 0; i < size; i++)
            this->arr[i] = other.arr[i];
    }

    void FillDefault(long value)
    {
        for (int i = 0; i < size; i++)
            arr[i] = value;
    }

    void FillFromKeyboard()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void Add(long value)
    {
        long* temp = new long[size + 1];

        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        temp[size] = value;

        if (arr != nullptr)
            delete[] arr;

        arr = temp;
        size++;
    }

    void DeleteByIndex(int index)
    {
        long* temp = new long[size - 1];

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != index)
            {
                temp[j] = arr[i];
                j++;
            }
        }

        if (arr != nullptr)
            delete[] arr;

        arr = temp;
        size--;
    }

    void DeleteByValue(long value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                DeleteByIndex(i);
                break;
            }
        }
    }

    void SortAscending()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    long temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void SortDescending()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] < arr[j])
                {
                    long temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    long GetMin()
    {
        long min = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (arr[i] < min)
                min = arr[i];
        }

        return min;
    }

    long GetMax()
    {
        long max = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }

        return max;
    }

    double GetAverage()
    {
        long sum = 0;

        for (int i = 0; i < size; i++)
            sum += arr[i];

        return (double)sum / size;
    }

    ~Array()
    {
        if (arr != nullptr)
            delete[] arr;
    }
};

int main()
{
    Array numbers(5);

    numbers.FillDefault(5);
    numbers.Add(10);
    numbers.Add(2);

    cout << "Array : ";
    numbers.Print();

    numbers.DeleteByIndex(1);
    cout << "After delete by index : ";
    numbers.Print();

    numbers.DeleteByValue(10);
    cout << "After delete by value : ";
    numbers.Print();

    numbers.SortAscending();
    cout << "Ascending : ";
    numbers.Print();

    numbers.SortDescending();
    cout << "Descending : ";
    numbers.Print();

    cout << "Min : " << numbers.GetMin() << endl;
    cout << "Max : " << numbers.GetMax() << endl;
    cout << "Average : " << numbers.GetAverage() << endl;

    Array copy = numbers;

    cout << "Copy : ";
    copy.Print();
}