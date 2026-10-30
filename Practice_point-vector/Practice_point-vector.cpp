#include "Point.h"

int main()
{
    Point point1(3, 4);
    Point point2(1, 1);

    point1.Print();
    ++point1;
    point1.Print();
    --point1;
    point1.Print();
    !point1;
    point1.Print();

    if (point1 > point2)
        cout << "Point 1 is farther from (0:0)" << endl;
    else
        cout << "Point 1 is closer to (0:0)" << endl;

    Point copy(point1);
    copy.Print();
}
