#include <iostream>
#include <fstream>
using namespace std;

void WriteShoppingList()
{
    ofstream out("shopping_list.txt");


    char product[100];

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter name of product " << i + 1 << ": ";
        cin >> product;

        out << product << endl;
    }

    out.close();
}

// Задача 1. Читання списку покупок
void ReadShoppingList()
{
    ifstream in("shopping_list.txt");

    char product[100];
    int number = 1;

    cout << "\nList" << endl;

    while (in >> product)
    {
        cout << number << ". " << product << endl;
        number++;
    }

    in.close();
}

void WriteNumbers()
{
    ofstream out("numbers.txt");

    int number;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> number;

        out << number << endl;
    }

    out.close();
}

// Задача 2. Читання чисел і підрахунок суми
void ReadNumbers()
{
    ifstream in("numbers.txt");


    int number;
    int sum = 0;

    while (in >> number)
    {
        sum += number;
    }

    in.close();

    cout << "\nSum: " << sum << endl;
}

int main()
{
    WriteShoppingList();
    ReadShoppingList();

    cout << endl;

    WriteNumbers();
    ReadNumbers();

    return 0;
}