#include <iostream>
using namespace std;
class Abonent {
    string name;
    string surname;
    string fathername;
    string phonenumber;
    string info;
    static int count;
public:
    Abonent() :name("no name"), surname("no surname"), fathername("no fethername"), phonenumber("+380123456789"), info("Idk enything") { count++; }

    Abonent(string name) : Abonent()
    {
        this->name = name;
    }
    Abonent(string name, string surname) : Abonent(name)
    {
        this->surname = surname;
    }
    Abonent(string name, string surname, string fathername) : Abonent(name, surname)
    {
        this->fathername = fathername;
    }
    Abonent(string name, string surname, string fathername, string phonenumber) : Abonent(name, surname, fathername)
    {
        this->phonenumber = phonenumber;
    }
    Abonent(string name, string surname, string fathername, string phonenumber, string info) : Abonent(name, surname, fathername, phonenumber)
    {
        this->info = info;
    }
    static int getCount()
    {
        return count;
    }
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Surname : " << surname << endl;
        cout << "Fathername : " << fathername << endl;
        cout << "Phonenumber : " << phonenumber << endl;
        cout << "Info : " << info << endl << endl;
    }
};
int Abonent::count = 0;
int main()
{

    Abonent a1{ "Oleg","Kolesnuk","Olegovuch","+380979881111","Funny" };
    cout << "Count humans : " << Abonent::getCount() << endl;
    a1.Print();
    Abonent a2{ "Oleg","Kolesnuk","Olegovuch","+380979881111","Funny" };
    cout << "Count humans : " << Abonent::getCount() << endl;
    a2.Print();
    Abonent a3{ "Oleg","Kolesnuk","Olegovuch","+380979881111","Funny" };
    cout << "Count humans : " << Abonent::getCount() << endl;
    a3.Print();
}