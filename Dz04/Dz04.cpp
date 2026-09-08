#include <iostream>
using namespace std;

int main()
{
    int i, n, count;
    int a, b, temp;
    float number, sum, product;

    i = 14;
    while (i <= 123)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    i = 1;
    while (i <= 100)
    {
        cout << i << " ";
        i += 2;
    }
    cout << endl;

    cout << "Enter N > 0: ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Enter N > 0: ";
        cin >> n;
    }

    count = 0;
    i = 0;
    while (i < n)
    {
        cout << "Enter number: ";
        cin >> number;
        if (number < 0)
        {
            count++;
        }
        i++;
    }
    cout << "Negative numbers: " << count << endl;
    sum = 0;
    product = 1;
    i = 0;
    while (i < 8)
    {
        cout << "Enter number: ";
        cin >> number;
        sum += number;
        product *= number;
        i++;
    }
    cout << "Product: " << product << endl;
    cout << "Average: " << sum / 8 << endl;
    ;
    i = 100;
    do
    {
        cout << i << " ";
        i -= 2;
    } while (i >= 2);
    cout << 1 << endl;

    product = 1;
    i = 0;
    do
    {
        cout << "Enter number: ";
        cin >> number;
        product *= number;
        i++;
    } while (i < 5);
    cout << "Product: " << product << endl;

    sum = 0;
    i = 4;
    while (i < 50)
    {
        sum += i;
        i += 4;
    }
    cout << "Sum (while): " << sum << endl;

    sum = 0;
    i = 4;
    do
    {
        sum += i;
        i += 4;
    } while (i < 50);
    cout << "Sum (do while): " << sum << endl;

    cout << "Enter integer: ";
    cin >> n;

    i = 0;
    if (n >= 0)
    {
        while (i <= n)
        {
            cout << i << " ";
            i++;
        }
    }
    else
    {
        while (i >= n)
        {
            cout << i << " ";
            i--;
        }
    }
    cout << endl;

    cout << "Enter two limits: ";
    cin >> a >> b;

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    cout << "All numbers: ";
    i = a;
    while (i <= b)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    cout << "Even numbers: ";
    i = a;
    while (i <= b)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;

    cout << "Odd numbers: ";
    i = a;
    while (i <= b)
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;

    cout << "Multiples of 7: ";
    i = a;
    while (i <= b)
    {
        if (i % 7 == 0)
        {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;

    cout << "Enter two limits: ";
    cin >> a >> b;

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    sum = 0;
    i = a;
    while (i <= b)
    {
        sum += i;
        i++;
    }
    cout << "Sum: " << sum << endl;

    sum = 0;
    do
    {
        cout << "Enter number (0 to stop): ";
        cin >> number;
        sum += number;
    } while (number != 0);
    cout << "Sum: " << sum << endl;

    return 0;
}