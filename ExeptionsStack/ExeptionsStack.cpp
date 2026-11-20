#include <iostream>
using namespace std;

class Stack
{
    enum { EMPTY = -1 };
    int* arr;
    int size;
    int topIndex;
public:
    Stack() = delete;

    Stack(int size) : arr(nullptr), size(size), topIndex(EMPTY)
    {
        if (size <= 0)
            throw invalid_argument("Stack size must be greater than zero");

        arr = new int[size] {};
    }

    Stack(const Stack& other)
        : arr(new int[other.size] {}), size(other.size), topIndex(other.topIndex)
    {
        for (int i = 0; i <= topIndex; i++)
            arr[i] = other.arr[i];
    }

    Stack& operator=(const Stack& other)
    {
        if (this != &other)
        {
            int* temp = new int[other.size] {};
            for (int i = 0; i <= other.topIndex; i++)
                temp[i] = other.arr[i];

            delete[] arr;
            arr = temp;
            size = other.size;
            topIndex = other.topIndex;
        }
        return *this;
    }

    bool IsFull()const
    {
        return topIndex == size - 1;
    }

    bool IsEmpty()const
    {
        return topIndex == EMPTY;
    }

    void Push(int elem)
    {
        if (IsFull())
            throw overflow_error("Cannot push into a full stack");

        arr[++topIndex] = elem;
    }

    int Pop()
    {
        if (IsEmpty())
            throw underflow_error("Cannot pop from an empty stack");

        return arr[topIndex--];
    }

    int Peek()const
    {
        if (IsEmpty())
            throw underflow_error("Cannot peek at an empty stack");

        return arr[topIndex];
    }

    int GetCount()const
    {
        return topIndex + 1;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    void Print()const
    {
        cout << "Capacity : " << size << endl;
        cout << "Size : " << GetCount() << endl;
        for (int i = 0; i <= topIndex; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

template<typename T>
class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;

        Node(Node* p, T v, Node* n) : prev(p), value(v), next(n) {}
    };

    Node* head;
    Node* tail;
    int count;

    Node* GetNode(int position)const
    {
        if (IsEmpty())
            throw underflow_error("Cannot get an element from an empty list");

        if (position < 1 || position > count)
            throw out_of_range("List position is out of range");

        Node* current = head;
        for (int i = 1; i < position; i++)
            current = current->next;

        return current;
    }
public:
    List() : head(nullptr), tail(nullptr), count(0) {}
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    bool IsEmpty()const
    {
        return head == nullptr;
    }

    int GetCount()const
    {
        return count;
    }

    void AddToHead(T value)
    {
        Node* newNode = new Node(nullptr, value, head);
        if (IsEmpty())
            head = tail = newNode;
        else
        {
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void AddToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (IsEmpty())
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void AddByPosition(T value, int position)
    {
        if (position < 1 || position > count + 1)
            throw out_of_range("Position for adding is out of range");

        if (position == 1)
        {
            AddToHead(value);
            return;
        }

        if (position == count + 1)
        {
            AddToTail(value);
            return;
        }

        Node* current = GetNode(position);
        Node* newNode = new Node(current->prev, value, current);
        current->prev->next = newNode;
        current->prev = newNode;
        count++;
    }

    T GetElement(int position)const
    {
        return GetNode(position)->value;
    }

    void DeleteFromHead()
    {
        if (IsEmpty())
            throw underflow_error("Cannot delete from the head of an empty list");

        Node* temp = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        delete temp;
        count--;
    }

    void DeleteFromTail()
    {
        if (IsEmpty())
            throw underflow_error("Cannot delete from the tail of an empty list");

        Node* temp = tail;
        tail = tail->prev;

        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;

        delete temp;
        count--;
    }

    void DeleteByPosition(int position)
    {
        if (IsEmpty())
            throw underflow_error("Cannot delete from an empty list");

        if (position < 1 || position > count)
            throw out_of_range("Position for deleting is out of range");

        if (position == 1)
        {
            DeleteFromHead();
            return;
        }

        if (position == count)
        {
            DeleteFromTail();
            return;
        }

        Node* current = GetNode(position);
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        count--;
    }

    void PrintList()const
    {
        for (Node* current = head; current != nullptr; current = current->next)
            cout << current->value << " ";
        cout << endl;
    }

    ~List()
    {
        while (!IsEmpty())
            DeleteFromHead();
    }
};

void TestStack()
{
    
    Stack stack(3);

    try
    {
        stack.Pop();
    }
    catch (const underflow_error& error)
    {
        cout << "Exception: " << error.what() << endl;
    }

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Print();

    try
    {
        stack.Push(40);
    }
    catch (const overflow_error& error)
    {
        cout << "Exception: " << error.what() << endl;
    }

    cout << "Top element : " << stack.Peek() << endl;
    cout << "Deleted element : " << stack.Pop() << endl;
    stack.Clear();

    try
    {
        cout << stack.Peek() << endl;
    }
    catch (const underflow_error& error)
    {
        cout << "Exception: " << error.what() << endl;
    }

    try
    {
        Stack invalidStack(0);
    }
    catch (const invalid_argument& error)
    {
        cout << "Exception: " << error.what() << endl;
    }
}

void TestList()
{
    List<int> list;

    try
    {
        list.DeleteFromHead();
    }
    catch (const underflow_error& error)
    {
        cout << "Exception: " << error.what() << endl;
    }

    list.AddToTail(100);
    list.AddToTail(300);
    list.AddByPosition(200, 2);
    list.PrintList();

    try
    {
        cout << "Element 5 : " << list.GetElement(5) << endl;
    }
    catch (const out_of_range& error)
    {
        cout << "Exception: " << error.what() << endl;
    }

    try
    {
        list.AddByPosition(400, 0);
    }
    catch (const out_of_range& error)
    {
        cout << "Exception: " << error.what() << endl;
    }

    list.DeleteByPosition(2);
    list.PrintList();
    list.DeleteFromHead();
    list.DeleteFromTail();

    try
    {
        list.DeleteFromTail();
    }
    catch (const underflow_error& error)
    {
        cout << "Exception: " << error.what() << endl;
    }
}

int main()
{
    try
    {
        TestStack();
        TestList();
    }
    catch (const bad_alloc& error)
    {
        cout << "Memory allocation exception: " << error.what() << endl;
    }
    catch (const exception& error)
    {
        cout << "Unexpected exception: " << error.what() << endl;
    }
}
