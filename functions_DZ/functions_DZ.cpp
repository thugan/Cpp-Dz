#include <iostream>
using namespace std;

bool vis(int y)
{
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    {
        return true;
        }
    return false;
}

int dn(int m, int y)
{
    int a[12] = { 31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31 };

    if (m == 2 && vis(y))
    {
        return 29;
        }
    return a[m - 1];
}

int data(int d, int m, int y)
{
    int s = 0;
    for (int i = 1; i < y; i++)
    {
        s += 365;
        if (vis(i))
        {
            s++;
        }
    }
    for (int i = 1; i < m; i++)
    {
        s += dn(i, y);
    }

    s += d;
    return s;
}

int rizn(int d1, int m1, int y1,
    int d2, int m2, int y2)
{
    int a = data(d1, m1, y1);
    int b = data(d2, m2, y2);

    int r = a - b;
    if (r < 0)
    {
        r = -r;
    }
    return r;
}

double ser(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }
    return (double)s / n;
}

void kil(int a[], int n, int& p, int& m, int& z)
{
    p = 0;
    m = 0;
    z = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            p++;
        }
        else if (a[i] < 0)
        {
            m++;
        }
        else
        {
            z++;
        }
    }
}

int main()
{
    cout << "Days = "
        << rizn(1, 1, 2024, 1, 1, 2025) << endl;
    int a[10] = { 5, -2, 0, 8, -7, 0, 4, -1, 3, 0 };
    cout << "Ser = " << ser(a, 10) << endl;

    int p;
    int m;
    int z;
    kil(a, 10, p, m, z);
    cout << "Plus = " << p << endl;
    cout << "Minus = " << m << endl;
    cout << "Null = " << z << endl;
}