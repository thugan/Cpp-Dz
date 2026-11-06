#include <iostream>

using namespace std;

struct Vagon
{
    int number;
    int places;
    int passengers;

    Vagon()
    {
        number = 0;
        places = 0;
        passengers = 0;
    }

    Vagon(int number, int places, int passengers)
    {
        this->number = number;
        this->places = places;
        this->passengers = passengers;
    }

    void Print() const
    {
        cout << "Vagon number: " << number << endl;
        cout << "Places: " << places << endl;
        cout << "Passengers: " << passengers << endl;
    }

    friend ostream& operator << (ostream& out, const Vagon& vagon);
};

ostream& operator << (ostream& out, const Vagon& vagon)
{
    out << "Vagon " << vagon.number
        << " [places: " << vagon.places
        << ", passengers: " << vagon.passengers << "]";
    return out;
}

template<typename T>
class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;

        Node() : prev(nullptr), value(), next(nullptr) {}

        Node(Node* prev, T value, Node* next)
            : prev(prev), value(value), next(next) {
        }
    };

    Node* head;
    Node* tail;

    Node* GetNode(int position) const
    {
        if (position < 1)
        {
            return nullptr;
        }

        Node* current = head;
        int currentPosition = 1;

        while (current != nullptr)
        {
            if (currentPosition == position)
            {
                return current;
            }

            current = current->next;
            currentPosition++;
        }

        return nullptr;
    }

public:
    List()
    {
        head = tail = nullptr;
    }

    List(const List& other)
    {
        head = tail = nullptr;

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

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    int GetCount() const
    {
        int count = 0;
        Node* current = head;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    void AddToHead(T value)
    {
        Node* newNode = new Node(nullptr, value, head);

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead()
    {
        if (IsEmpty())
        {
            return;
        }

        Node* current = head;
        head = head->next;

        if (head == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            head->prev = nullptr;
        }

        delete current;
    }

    void DeleteFromTail()
    {
        if (IsEmpty())
        {
            return;
        }

        Node* current = tail;
        tail = tail->prev;

        if (tail == nullptr)
        {
            head = nullptr;
        }
        else
        {
            tail->next = nullptr;
        }

        delete current;
    }

    bool AddAt(T value, int position)
    {
        int count = GetCount();

        if (position < 1 || position > count + 1)
        {
            return false;
        }

        if (position == 1)
        {
            AddToHead(value);
            return true;
        }

        if (position == count + 1)
        {
            AddToTail(value);
            return true;
        }

        Node* current = GetNode(position);
        Node* newNode = new Node(current->prev, value, current);

        current->prev->next = newNode;
        current->prev = newNode;
        return true;
    }

    bool DeleteAt(int position)
    {
        int count = GetCount();

        if (position < 1 || position > count)
        {
            return false;
        }

        if (position == 1)
        {
            DeleteFromHead();
            return true;
        }

        if (position == count)
        {
            DeleteFromTail();
            return true;
        }

        Node* current = GetNode(position);
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        return true;
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            DeleteFromHead();
        }
    }

    void PrintList() const
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }

        cout << endl;
    }

    ~List()
    {
        Clear();
    }
};

class Train
{
private:
    string model;
    int countVagons;
    List<Vagon> vagons;

public:
    Train()
    {
        model = "No model";
        countVagons = 0;
    }

    explicit Train(string model)
    {
        this->model = model;
        countVagons = 0;
    }

    Train(string model, initializer_list<Vagon> list)
    {
        this->model = model;
        countVagons = 0;

        for (Vagon vagon : list)
        {
            AddVagonToTail(vagon);
        }
    }

    Train(const Train& other)
    {
        model = other.model;
        countVagons = other.countVagons;
        vagons = other.vagons;
    }

    Train& operator = (const Train& other)
    {
        if (this != &other)
        {
            model = other.model;
            countVagons = other.countVagons;
            vagons = other.vagons;
        }

        return *this;
    }

    void AddVagonToHead(Vagon vagon)
    {
        vagons.AddToHead(vagon);
        countVagons++;
    }

    void AddVagonToTail(Vagon vagon)
    {
        vagons.AddToTail(vagon);
        countVagons++;
    }

    void DeleteVagonFromHead()
    {
        if (countVagons > 0)
        {
            vagons.DeleteFromHead();
            countVagons--;
        }
    }

    void DeleteVagonFromTail()
    {
        if (countVagons > 0)
        {
            vagons.DeleteFromTail();
            countVagons--;
        }
    }

    bool AddVagonAt(Vagon vagon, int position)
    {
        if (vagons.AddAt(vagon, position))
        {
            countVagons++;
            return true;
        }

        return false;
    }

    bool DeleteVagonAt(int position)
    {
        if (vagons.DeleteAt(position))
        {
            countVagons--;
            return true;
        }

        return false;
    }

    void Show() const
    {
        cout << "Train model: " << model << endl;
        cout << "Vagon count: " << countVagons << endl;
        cout << "Vagons: ";
        vagons.PrintList();
    }
};

int main()
{

    List<int> list;
    list.AddToTail(100);
    list.AddToTail(200);
    list.AddToTail(300);
    list.PrintList();

    list.DeleteFromHead();
    list.PrintList();


    Train train("Express", {
        Vagon(1, 60, 45),
        Vagon(2, 60, 50),
        Vagon(3, 40, 30)
        });

    train.Show();

    train.AddVagonToHead(Vagon(0, 50, 20));
    train.AddVagonToTail(Vagon(4, 60, 55));
    train.Show();

    train.DeleteVagonFromHead();
    train.DeleteVagonFromTail();
    train.Show();


    train.AddVagonAt(Vagon(10, 35, 15), 2);
    train.Show();

    train.DeleteVagonAt(2);
    train.Show();

    Train copy(train);
    copy.AddVagonToHead(Vagon(99, 70, 60));

    cout << "train 1:" << endl;
    train.Show();
    cout << "train 2:" << endl;
    copy.Show();
}