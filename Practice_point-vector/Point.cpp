#include "Point.h"

Point::Point()
{
    x = y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other)
{
    this->x = other.x;
    this->y = other.y;
}

void Point::Print()const
{
    cout << "X : " << x << " Y : " << y << endl;
}

int Point::getX()const
{
    return x;
}

int Point::getY()const
{
    return y;
}

Point Point::operator++()
{
    this->x++;
    this->y++;
    return *this;
}

Point Point::operator--()
{
    this->x--;
    this->y--;
    return *this;
}

Point Point::operator!()
{
    this->x = -this->x;
    this->y = -this->y;
    return *this;
}

bool Point::operator>(const Point& other)const
{
    return (x * x + y * y) > (other.x * other.x + other.y * other.y);
}

bool Point::operator<(const Point& other)const
{
    return (x * x + y * y) < (other.x * other.x + other.y * other.y);
}
