#include <iostream>
using namespace std;

int main()
{
    float a, b;
    cout << "Enter side a : "; cin >> a;
    cout << "Enter side b : "; cin >> b;
    if (a == b)
        cout << "This is a square" << endl;
    else
        cout << "This is a rectangle" << endl;

    int age;
    cout << "Enter age : "; cin >> age;
    if (age >= 3 && age < 6)
        cout << "Kindergarten" << endl;
    else if (age >= 6 && age <= 17)
        cout << "School" << endl;
    else if (age < 3)
        cout << "Too young" << endl;
    else
        cout << "School age is over" << endl;

    int c, d, e;
    cout << "Enter number a : "; cin >> c;
    cout << "Enter number b : "; cin >> d;
    cout << "Enter number c : "; cin >> e;
    if ((c < 0 && d < 0 && e >= 0) || (c < 0 && e < 0 && d >= 0) || (d < 0 && e < 0 && c >= 0))
        cout << "Exactly two negative" << endl;
    else
        cout << "No" << endl;

    float num;
    cout << "Enter number : "; cin >> num;
    if ((num >= 2 && num <= 5) || (num >= -1 && num <= 1))
        cout << "Belongs" << endl;
    else
        cout << "Does not belong" << endl;

    int x, y, z;
    cout << "Enter number a : "; cin >> x;
    cout << "Enter number b : "; cin >> y;
    cout << "Enter number c : "; cin >> z;
    if ((x == y && x != z) || (x == z && x != y) || (y == z && y != x))
        cout << "Exactly two are equal" << endl;
    else
        cout << "No" << endl;

    int n1, n2, n3;
    cout << "Enter number a : "; cin >> n1;
    cout << "Enter number b : "; cin >> n2;
    cout << "Enter number c : "; cin >> n3;
    if (n1 % 2 != 0 && n2 % 2 != 0 && n3 % 2 != 0)
        cout << "All odd" << endl;
    else
        cout << "Not all odd" << endl;

    int q, w, temp;
    cout << "Enter number a : "; cin >> q;
    cout << "Enter number b : "; cin >> w;
    if (q != w)
    {
        temp = q;
        q = w;
        w = temp;
    }
    cout << "a = " << q << endl;
    cout << "b = " << w << endl;

    int number;
    cout << "Enter three digit number : "; cin >> number;
    int first = number / 100;
    int middle = number / 10 % 10;
    int last = number % 10;
    int sum = first + middle + last;
    cout << "Number of digits = 3" << endl;
    cout << "Sum = " << sum << endl;
    cout << "First = " << first << "  Last = " << last << endl;

    int hours, minutes, seconds;
    cout << "Enter hours : "; cin >> hours;
    cout << "Enter minutes : "; cin >> minutes;
    cout << "Enter seconds : "; cin >> seconds;
    if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59)
        cout << "Correct time" << endl;
    else
        cout << "Incorrect time" << endl;

    int hour;
    cout << "Enter hour : "; cin >> hour;
    if (hour >= 0 && hour < 6)
        cout << "Good night" << endl;
    else if (hour >= 6 && hour < 12)
        cout << "Good morning" << endl;
    else if (hour >= 12 && hour < 18)
        cout << "Good day" << endl;
    else if (hour >= 18 && hour <= 23)
        cout << "Good evening" << endl;
    else
        cout << "Error hour" << endl;

    int m1, m2, m3, minimum;
    cout << "Enter number a : "; cin >> m1;
    cout << "Enter number b : "; cin >> m2;
    cout << "Enter number c : "; cin >> m3;
    minimum = m1;
    if (m2 < minimum)
        minimum = m2;
    if (m3 < minimum)
        minimum = m3;
    cout << "Minimum = " << minimum << endl;
}