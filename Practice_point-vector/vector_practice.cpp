#include "Vector.h"

int main()
{
    Vector vector;
    Point point(2, 3);
    point.SetNewCoords(5, 2);
    vector.Add(point);
    vector.Add(Point(30, 5));
    vector.Add(Point(55, 8));
    vector.Print();

    Vector copyVector(vector);
    copyVector.Print();

    Vector movedVector(copyVector);
    movedVector.Print();

    Vector assignedVector;
    assignedVector = movedVector;
    assignedVector.Print();

}
