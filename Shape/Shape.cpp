#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape
{
private:
    string name;
    string type;
public:
    Shape() : name("no name"), type("no type") {}
    Shape(string n, string t) : name(n), type(t) {}

    virtual void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Type : " << type << endl;
    }

    virtual double GetArea()const
    {
        return 0;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;
public:
    Rectangle() : width(0), height(0), Shape("no name", "Rectangle") {}
    Rectangle(string n, double w, double h)
        : width(w), height(h), Shape(n, "Rectangle") {
    }

    void Show()const override
    {
        Shape::Show();
        cout << "Width : " << width << endl;
        cout << "Height : " << height << endl;
    }

    double GetArea()const override
    {
        return width * height;
    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle() : radius(0), Shape("no name", "Circle") {}
    Circle(string n, double r)
        : radius(r), Shape(n, "Circle") {
    }

    void Show()const override
    {
        Shape::Show();
        cout << "Radius : " << radius << endl;
    }

    double GetArea()const override
    {
        const double PI = 3.141592653589793;
        return PI * radius * radius;
    }
};

class RightTriangle : public Shape
{
private:
    double firstLeg;
    double secondLeg;
public:
    RightTriangle() : firstLeg(0), secondLeg(0), Shape("no name", "Right triangle") {}
    RightTriangle(string n, double first, double second)
        : firstLeg(first), secondLeg(second), Shape(n, "Right triangle") {
    }

    void Show()const override
    {
        Shape::Show();
        cout << "First leg : " << firstLeg << endl;
        cout << "Second leg : " << secondLeg << endl;
    }

    double GetArea()const override
    {
        return firstLeg * secondLeg / 2;
    }
};

class Triangle : public Shape
{
private:
    double firstSide;
    double secondSide;
    double thirdSide;
public:
    Triangle() : firstSide(0), secondSide(0), thirdSide(0), Shape("no name", "Triangle") {}
    Triangle(string n, double first, double second, double third)
        : firstSide(first), secondSide(second), thirdSide(third), Shape(n, "Triangle") {
    }

    void Show()const override
    {
        Shape::Show();
        cout << "First side : " << firstSide << endl;
        cout << "Second side : " << secondSide << endl;
        cout << "Third side : " << thirdSide << endl;
    }

    double GetArea()const override
    {
        double halfPerimeter = (firstSide + secondSide + thirdSide) / 2;

        if (firstSide <= 0 || secondSide <= 0 || thirdSide <= 0)
            return 0;

        if (firstSide + secondSide <= thirdSide ||
            firstSide + thirdSide <= secondSide ||
            secondSide + thirdSide <= firstSide)
            return 0;

        return sqrt(halfPerimeter *
            (halfPerimeter - firstSide) *
            (halfPerimeter - secondSide) *
            (halfPerimeter - thirdSide));
    }
};

class Trapezoid : public Shape
{
private:
    double firstBase;
    double secondBase;
    double height;
public:
    Trapezoid() : firstBase(0), secondBase(0), height(0), Shape("no name", "Trapezoid") {}
    Trapezoid(string n, double first, double second, double h)
        : firstBase(first), secondBase(second), height(h), Shape(n, "Trapezoid") {
    }

    void Show()const override
    {
        Shape::Show();
        cout << "First base : " << firstBase << endl;
        cout << "Second base : " << secondBase << endl;
        cout << "Height : " << height << endl;
    }

    double GetArea()const override
    {
        return (firstBase + secondBase) * height / 2;
    }
};

void TestShape(Shape& shape)
{
    cout << "------------------------------" << endl;
    shape.Show();
    cout << "Area : " << shape.GetArea() << endl;
}

int main()
{
    Rectangle rectangle("Room rectangle", 8, 5);
    Circle circle("Round window", 4);
    RightTriangle rightTriangle("Construction triangle", 6, 8);
    Triangle triangle("Regular triangle", 5, 5, 6);
    Trapezoid trapezoid("Roof trapezoid", 10, 6, 4);

    TestShape(rectangle);
    TestShape(circle);
    TestShape(rightTriangle);
    TestShape(triangle);
    TestShape(trapezoid);
}
