#include "Vector.h"
#include <Windows.h>

void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

Vector::Vector()
{
    points = nullptr;
    countPoint = 0;
}

Vector::Vector(int countPoint)
{
    this->countPoint = countPoint;
    this->points = new Point[countPoint];
}

Vector::Vector(const Vector& other)
{
    this->countPoint = other.countPoint;
    this->points = new Point[countPoint];
    for (int i = 0; i < countPoint; i++)
    {
        this->points[i] = other.points[i];
    }
    cout << "Copy constructor" << endl;
}

Vector::Vector(Vector&& other)
{
    this->countPoint = other.countPoint;
    this->points = other.points;
    other.points = nullptr;
    other.countPoint = 0;
    cout << "Move constructor" << endl;
}

Vector& Vector::operator=(const Vector& other)
{
    if (this != &other)
    {
        this->countPoint = other.countPoint;
        if (points != nullptr)
            delete[]points;
        this->points = new Point[countPoint];
        for (int i = 0; i < countPoint; i++)
        {
            this->points[i] = other.points[i];
        }
    }
    cout << "Operator =" << endl;
    return *this;
}

Vector& Vector::operator=(Vector&& other)
{
    if (this != &other)
    {
        if (points != nullptr)
            delete[]points;
        this->points = other.points;
        this->countPoint = other.countPoint;
        other.points = nullptr;
        other.countPoint = 0;
    }
    cout << "Move operator =" << endl;
    return *this;
}

Vector::~Vector()
{
    if (points != nullptr)
        delete[]points;
}

void Vector::Add(Point point)
{
    Point* temp = new Point[countPoint + 1];
    for (int i = 0; i < countPoint; i++)
    {
        temp[i] = points[i];
    }
    temp[countPoint] = point;
    if (points != nullptr)
        delete[]points;
    countPoint++;
    points = temp;
}

void Vector::Print()const
{
    cout << "Count points : " << countPoint << endl;
    for (int i = 0; i < countPoint; i++)
    {
        SetPos(points[i].getX(), points[i].getY());
        cout << "Point " << i + 1 << " : ";
        points[i].Print();
    }
}
