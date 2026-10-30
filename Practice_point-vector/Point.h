#pragma once
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point(const Point& other);
    void Print()const;
    void SetNewCoords(int newX, int newY);
    int getX()const;
    int getY()const;
    Point operator++();
    Point operator--();
    Point operator!();
    bool operator>(const Point& other)const;
    bool operator<(const Point& other)const;
};
