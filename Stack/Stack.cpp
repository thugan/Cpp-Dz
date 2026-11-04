#include <iostream>
using namespace std;

class StaticStack
{
    enum { EMPTY = -1, FULL = 9 };
    char arr[FULL + 1];
    int topIndex;

public:
    StaticStack()
    {
        topIndex = EMPTY;
    }

    bool Push(char elem)
    {
        if (!IsFull())
        {
            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }

    char Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
        return '\0';
    }

    int GetCount() const
    {
        return topIndex + 1;
    }

    bool IsEmpty() const
    {
        return topIndex == EMPTY;
    }

    bool IsFull() const
    {
        return topIndex == FULL;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    char Peek() const
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
        return '\0';
    }

    void Print() const
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class DynamicStack
{
    enum { EMPTY = -1 };
    char* arr;
    int size;
    int topIndex;

    void Resize()
    {
        int newSize = size * 2;
        char* temp = new char[newSize];

        for (int i = 0; i <= topIndex; i++)
        {
            temp[i] = arr[i];
        }

        delete[]arr;
        arr = temp;
        size = newSize;
    }

public:
    explicit DynamicStack(int size)
    {
        if (size <= 0)
        {
            size = 1;
        }

        this->size = size;
        arr = new char[size];
        topIndex = EMPTY;
    }

    ~DynamicStack()
    {
        if (arr != nullptr)
        {
            delete[]arr;
        }
    }

    bool Push(char elem)
    {
        if (IsFull())
        {
            Resize();
        }

        arr[++topIndex] = elem;
        return true;
    }

    char Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
        return '\0';
    }

    int GetCount() const
    {
        return topIndex + 1;
    }

    int GetSize() const
    {
        return size;
    }

    bool IsEmpty() const
    {
        return topIndex == EMPTY;
    }

    bool IsFull() const
    {
        return topIndex == size - 1;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    char Peek() const
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
        return '\0';
    }

    void Print() const
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

template<typename T>
class Stack
{
    enum { EMPTY = -1 };
    T* arr;
    int size;
    int topIndex;

    void Resize()
    {
        int newSize = size * 2;

        if (newSize <= 0)
        {
            newSize = 1;
        }

        T* temp = new T[newSize];

        for (int i = 0; i <= topIndex; i++)
        {
            temp[i] = arr[i];
        }

        delete[]arr;
        arr = temp;
        size = newSize;
    }

public:
    Stack()
    {
        arr = nullptr;
        size = 0;
        topIndex = EMPTY;
    }

    explicit Stack(int size)
    {
        if (size <= 0)
        {
            size = 1;
        }

        this->size = size;
        arr = new T[size];
        topIndex = EMPTY;
    }

    Stack(int size, initializer_list<T> list)
    {
        this->size = size;

        if (this->size < list.size())
        {
            this->size = list.size();
        }

        if (this->size <= 0)
        {
            this->size = 1;
        }

        arr = new T[this->size];
        topIndex = EMPTY;

        for (T elem : list)
        {
            Push(elem);
        }
    }

    ~Stack()
    {
        if (arr != nullptr)
        {
            delete[]arr;
        }
    }

    bool Push(T elem)
    {
        if (IsFull())
        {
            Resize();
        }

        arr[++topIndex] = elem;
        return true;
    }

    T Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
        return T();
    }

    int GetCount() const
    {
        return topIndex + 1;
    }

    int GetSize() const
    {
        return size;
    }

    bool IsEmpty() const
    {
        return topIndex == EMPTY;
    }

    bool IsFull() const
    {
        return topIndex == size - 1;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    T Peek() const
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
        return T();
    }

    void Print() const
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
 /*   StaticStack staticStack;
    staticStack.Push('A');
    staticStack.Push('B');
    staticStack.Push('C');
    staticStack.Print();
    cout << "Top element: " << staticStack.Peek() << endl;
    cout << "Deleted element: " << staticStack.Pop() << endl;
    cout << "Count: " << staticStack.GetCount() << endl;
    staticStack.Clear();
    cout << "Is empty: " << staticStack.IsEmpty() << endl;*/

    DynamicStack dynamicStack(2);
    dynamicStack.Push('A');
    dynamicStack.Push('B');
    dynamicStack.Push('C');
    dynamicStack.Push('D');
    dynamicStack.Print();
    cout << "Capacity after resizing: " << dynamicStack.GetSize() << endl;
    cout << "Top element: " << dynamicStack.Peek() << endl;

    Stack<char> charStack(3, { 'A', 'B', 'C' });
    charStack.Push('D');
    charStack.Print();
    cout << "Capacity after resizing: " << charStack.GetSize() << endl;

    Stack<int> intStack(3, { 10, 20, 30, 40 });
    intStack.Print();
    cout << "Top element: " << intStack.Peek() << endl;

    Stack<double> doubleStack(2, { 1.1, 2.2 });
    doubleStack.Print();

}
