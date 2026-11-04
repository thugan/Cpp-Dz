#include <iostream>
#include <string>

using namespace std;

class Document
{
    string fileName;
    string position;
    int priority;

public:
    Document()
    {
        fileName = "";
        position = "";
        priority = 0;
    }

    Document(string fileName, string position, int priority)
    {
        this->fileName = fileName;
        this->position = position;
        this->priority = priority;
    }

    int GetPriority() const
    {
        return priority;
    }

    void Print() const
    {
        cout << "File name: " << fileName << endl;
        cout << "Position: " << position << endl;
        cout << "Priority: " << priority << endl;
    }
};

template<typename T>
class Queue
{
    struct Element
    {
        T value;
        int priority;
    };

    Element* elements;
    int count;

public:
    Queue()
    {
        elements = nullptr;
        count = 0;
    }

    ~Queue()
    {
        if (elements != nullptr)
        {
            delete[]elements;
        }
    }

    void Enqueue(T value, int priority)
    {
        int index = 0;

        while (index < count && elements[index].priority >= priority)
        {
            index++;
        }

        Element* temp = new Element[count + 1];

        for (int i = 0; i < index; i++)
        {
            temp[i] = elements[i];
        }

        temp[index].value = value;
        temp[index].priority = priority;

        for (int i = index; i < count; i++)
        {
            temp[i + 1] = elements[i];
        }

        if (elements != nullptr)
        {
            delete[]elements;
        }

        elements = temp;
        count++;
    }

    bool IsEmpty() const
    {
        return count == 0;
    }

    int GetCount() const
    {
        return count;
    }

    T Dequeue()
    {
        if (!IsEmpty())
        {
            T first = elements[0].value;

            for (int i = 0; i < count - 1; i++)
            {
                elements[i] = elements[i + 1];
            }

            count--;
            return first;
        }

        return T();
    }

    void Print() const
    {

        for (int i = 0; i < count; i++)
        {
            cout << "Document " << i + 1 << endl;
            elements[i].value.Print();
            cout << "-----------------------------------------------" << endl;
        }
    }
};

void PrintMenu()
{
    cout << endl;
    cout << "1. Add document to the print queue" << endl;
    cout << "2. Print document" << endl;
    cout << "3. Show print queue" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

void PrintPositions()
{
    cout << "1. Guest - priority 1" << endl;
    cout << "2. Administrator - priority 2" << endl;
    cout << "3. Manager - priority 3" << endl;
    cout << "4. Director - priority 4" << endl;
}

string GetPositionName(int position)
{
    switch (position)
    {
    case 1:
        return "Guest";
    case 2:
        return "Administrator";
    case 3:
        return "Manager";
    case 4:
        return "Director";
    default:
        return "Unknown";
    }
}

int GetPriority(int position)
{
    return position;
}

void AddDocument(Queue<Document>& queue)
{
    string fileName;

    cin.ignore(10000, '\n');
    cout << "Enter file name: ";
    getline(cin, fileName);

    int position;
    PrintPositions();
    cout << "Choose a position: ";
    cin >> position;

    while (position < 1 || position > 4)
    {
        cout << "Incorrect position. Choose a number from 1 to 4: ";
        cin >> position;
    }

    string positionName = GetPositionName(position);
    int priority = GetPriority(position);
    Document document(fileName, positionName, priority);

    queue.Enqueue(document, document.GetPriority());
    cout << "Document added to the print queue." << endl;
}

void PrintDocument(Queue<Document>& queue)
{
    if (queue.IsEmpty())
    {
        cout << "The print queue is empty." << endl;
        return;
    }

    Document document = queue.Dequeue();
    cout << "Now printing:" << endl;
    document.Print();
}

int main()
{
    Queue<Document> printQueue;
    int choice;

    do
    {
        PrintMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddDocument(printQueue);
            break;
        case 2:
            PrintDocument(printQueue);
            break;
        case 3:
            printQueue.Print();
            break;
        case 0:
            cout << "Program finished." << endl;
            break;
        default:
            cout << "Incorrect option." << endl;
        }
    } while (choice != 0);

    return 0;
}
