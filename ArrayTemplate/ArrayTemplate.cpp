#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

template<typename T>
class Array
{
    T* arr;
    int size;
public:
    Array()
    {
        size = 0;
        arr = nullptr;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new T[size]{};
    }
    Array(int size, T value)
    {
        this->size = size;
        arr = new T[size];
        for (int i = 0; i < size; i++)
            arr[i] = value;
    }
    Array(initializer_list<T> list)
    {
        this->size = list.size();
        this->arr = new T[size];
        int i = 0;
        for (T element : list)
        {
            arr[i] = element;
            i++;
        }
    }
    void Fill(initializer_list<T> list)
    {
        if (arr != nullptr)
            delete[]arr;
        this->size = list.size();
        this->arr = new T[size];
        int i = 0;
        for (T element : list)
        {
            arr[i] = element;
            i++;
        }
    }
    Array& operator=(initializer_list<T> list)
    {
        Fill(list);
        return *this;
    }
    ~Array()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    int getSize()const
    {
        return size;
    }
    T getValue(int index)const
    {
        return arr[index];
    }
    void setValue(T value, int index)
    {
        arr[index] = value;
    }
    void display(int index)const;
};

template<typename T>
void Array<T>::display(int index)const
{
    cout << arr[index] << " ";
}

template<typename T>
void PrintArray(const Array<T>& array)
{
    for (int i = 0; i < array.getSize(); i++)
    {
        array.display(i);
    }
    cout << endl;
}

template<typename T>
T GetMax(const Array<T>& array)
{
    T max = array.getValue(0);
    for (int i = 1; i < array.getSize(); i++)
    {
        if (array.getValue(i) > max)
            max = array.getValue(i);
    }
    return max;
}

template<typename T>
T GetMin(const Array<T>& array)
{
    T min = array.getValue(0);
    for (int i = 1; i < array.getSize(); i++)
    {
        if (array.getValue(i) < min)
            min = array.getValue(i);
    }
    return min;
}

template<typename T>
void Sort(Array<T>& array)
{
    for (int i = 0; i < array.getSize() - 1; i++)
    {
        for (int j = 0; j < array.getSize() - i - 1; j++)
        {
            if (array.getValue(j) > array.getValue(j + 1))
            {
                T temp = array.getValue(j);
                array.setValue(array.getValue(j + 1), j);
                array.setValue(temp, j + 1);
            }
        }
    }
}

template<typename T>
int BinarySearch(const Array<T>& array, T value)
{
    int left = 0;
    int right = array.getSize() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (array.getValue(middle) == value)
            return middle;
        if (array.getValue(middle) < value)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

template<typename T>
void ReplaceElement(Array<T>& array, int index, T value)
{
    array.setValue(value, index);
}

int main()
{
    Array<int> numbers = { 5, 2, 9, 1, 7 };
    PrintArray(numbers);

    cout << "Maximum: " << GetMax(numbers) << endl;
    cout << "Minimum: " << GetMin(numbers) << endl;

    Sort(numbers);
    PrintArray(numbers);
    cout << "Index of 7: " << BinarySearch(numbers, 7) << endl;

    ReplaceElement(numbers, 2, 10);
    PrintArray(numbers);

    numbers = { 8, 6, 4 };
    PrintArray(numbers);

    Array<double> values = { 2.5, 7.1, 1.4 };
    Sort(values);
    PrintArray(values);

    Array<string> colors = { "red", "green", "blue" };
    PrintArray(colors);
}
