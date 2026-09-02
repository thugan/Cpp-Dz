#include <iostream>
using namespace std;

int main()
{
    int number1;
    int number2;
    int number3;
    cout << "Enter first number: ";
    cin >> number1;
    cout << "Enter second number: ";
    cin >> number2;
    cout << "Enter third number: ";
    cin >> number3;
    int sum = number1 + number2 + number3;
    cout << "Number 1 = " << number1 << endl;
    cout << "Number 2 = " << number2 << endl;
    cout << "Number 3 = " << number3 << endl;
    cout << "Sum = " << sum << endl;

    float numer1;
    float numer2;
    cout << "Enter first number: ";
    cin >> numer1;
    cout << "Enter second number: ";
    cin >> numer2;
    float average = (numer1 + numer2) / 2;
    cout << "Average = " << average << endl;

    float kilometers;

    cout << "Enter kilometers: ";
    cin >> kilometers;

    const int metersInOneKilometer = 1000;

    float resultMeters = kilometers * metersInOneKilometer;

    cout << "Meters = " << resultMeters << endl;

    const float price1 = 25.50;
    const float price2 = 40.00;
    const float price3 = 15.75;
    const float price4 = 100.00;
    int count1;
    int count2;
    int count3;
    int count4;
    cout << "Enter count of first product: ";
    cin >> count1;
    cout << "Enter count of second product: ";
    cin >> count2;
    cout << "Enter count of third product: ";
    cin >> count3;
    cout << "Enter count of fourth product: ";
    cin >> count4;
    float cost1 = price1 * count1;
    float cost2 = price2 * count2;
    float cost3 = price3 * count3;
    float cost4 = price4 * count4;
    float totalCost = cost1 + cost2 + cost3 + cost4;
    cout << "Total cost = " << totalCost << endl;
}