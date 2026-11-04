#include <iostream>

using namespace std;

template<typename T>
class List
{
    struct Node
    {
        T value;
        Node* next;

        Node() : value(), next(nullptr) {}
        Node(T value, Node* next) : value(value), next(next) {}
    };

    Node* head;
    int count;

public:
    List()
    {
        head = nullptr;
        count = 0;
    }

    List(const List& other)
    {
        head = nullptr;
        count = 0;

        Node* current = other.head;
        while (current != nullptr)
        {
            AddToTail(current->value);
            current = current->next;
        }
    }

    List& operator = (const List& other)
    {
        if (this != &other)
        {
            Clear();

            Node* current = other.head;
            while (current != nullptr)
            {
                AddToTail(current->value);
                current = current->next;
            }
        }

        return *this;
    }

    ~List()
    {
        Clear();
    }

    void AddToHead(T value)
    {
        Node* newNode = new Node(value, head);
        head = newNode;
        count++;
    }

    void AddToTail(T value)
    {
        Node* newNode = new Node(value, nullptr);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
        }

        count++;
    }

    void DeleteFromHead()
    {
        if (head == nullptr)
        {
            return;
        }

        Node* current = head;
        head = head->next;
        delete current;
        count--;
    }

    void DeleteFromTail()
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            count--;
            return;
        }

        Node* current = head;

        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
        count--;
    }

    void Clear()
    {
        while (head != nullptr)
        {
            DeleteFromHead();
        }
    }

    int GetCount() const
    {
        return count;
    }

    void Print() const
    {
        Node* current = head;

        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }
};

class Point
{
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    explicit Point(int value)
    {
        this->x = value;
        this->y = value;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void Print() const
    {
        cout << "X : " << x << " . Y : " << y << endl;
    }

    friend ostream& operator << (ostream& out, const Point& point);
};

ostream& operator << (ostream& out, const Point& point)
{
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

class Vector
{
    int size;
    List<Point> points;

public:
    Vector()
    {
        size = 0;
    }

    Vector(initializer_list<Point> list)
    {
        size = 0;

        for (Point point : list)
        {
            AddToTail(point);
        }
    }

    Vector(const Vector& other)
    {
        size = other.size;
        points = other.points;
    }

    Vector& operator = (const Vector& other)
    {
        if (this != &other)
        {
            size = other.size;
            points = other.points;
        }

        return *this;
    }

    void AddToHead(Point point)
    {
        points.AddToHead(point);
        size++;
    }

    void AddToTail(Point point)
    {
        points.AddToTail(point);
        size++;
    }

    void DeleteFromHead()
    {
        if (size > 0)
        {
            points.DeleteFromHead();
            size--;
        }
    }

    void DeleteFromTail()
    {
        if (size > 0)
        {
            points.DeleteFromTail();
            size--;
        }
    }

    void Clear()
    {
        points.Clear();
        size = 0;
    }

    int GetSize() const
    {
        return size;
    }

    void Print() const
    {
        cout << "Vector size: " << size << endl;
        points.Print();
    }
};

int main()
{

    //List<int> numbers;
    //numbers.AddToHead(20);
    //numbers.AddToHead(10);
    //numbers.AddToTail(30);
    //numbers.Print();

    //numbers.DeleteFromHead();
    //numbers.Print();

    //List<string> words;
    //words.AddToHead("second");
    //words.AddToHead("first");
    //words.AddToTail("third");
    //words.Print();
    //words.DeleteFromHead();
    //words.Print();

    Vector points({ Point(1, 2), Point(3, 4), Point(5, 6) });
    points.Print();

    points.AddToHead(Point(-1, -2));
    points.AddToTail(Point(7, 8));
    points.Print();

    points.DeleteFromHead();
    points.DeleteFromTail();
    points.Print();

    Vector copy(points);
    copy.AddToTail(Point(100, 200));

    cout << endl << "Original vector:" << endl;
    points.Print();
    cout << "Copied vector:" << endl;
    copy.Print();

}
