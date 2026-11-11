#include <iostream>
#include <string>
using namespace std;

class Student
{
    string fullName;
    int age;
    string group;
public:
    Student() : fullName("no name"), age(0), group("no group") {}
    Student(string n, int a, string g) : fullName(n), age(a), group(g) {}

    void Print()const
    {
        cout << "Full name : " << fullName << endl;
        cout << "Age : " << age << endl;
        cout << "Group : " << group << endl;
    }
};

class Aspirant : public Student
{
    string dissertationTopic;
    int writtenPages;
    bool defended;
public:
    Aspirant() : dissertationTopic("no topic"), writtenPages(0), defended(false), Student() {}
    Aspirant(string n, int a, string g, string topic)
        : dissertationTopic(topic), writtenPages(0), defended(false), Student(n, a, g) {
    }

    void WriteDissertation(int pages)
    {
        if (pages > 0)
        {
            writtenPages += pages;
            cout << "Pages written : " << pages << endl;
        }
    }

    void DefendDissertation()
    {
        if (writtenPages > 0)
        {
            defended = true;
            cout << "Dissertation defended successfully" << endl;
        }
        else
            cout << "The dissertation has no written pages" << endl;
    }

    void Print()const
    {
        cout << "----------------------Aspirant-----------------" << endl;
        Student::Print();
        cout << "Dissertation topic : " << dissertationTopic << endl;
        cout << "Written pages : " << writtenPages << endl;
        cout << "Defended : " << (defended ? "yes" : "no") << endl;
    }
};

class Passport
{
    string fullName;
    string dateOfBirth;
    string citizenship;
    string passportNumber;
public:
    Passport()
        : fullName("no name"), dateOfBirth("no date"),
        citizenship("Ukraine"), passportNumber("no number") {
    }

    Passport(string n, string date, string c, string number)
        : fullName(n), dateOfBirth(date), citizenship(c), passportNumber(number) {
    }

    void Print()const
    {
        cout << "Full name : " << fullName << endl;
        cout << "Date of birth : " << dateOfBirth << endl;
        cout << "Citizenship : " << citizenship << endl;
        cout << "Passport number : " << passportNumber << endl;
    }
};

class ForeignPassport : public Passport
{
    string foreignPassportNumber;
    string visas[10];
    int countVisas;
public:
    ForeignPassport()
        : foreignPassportNumber("no number"), countVisas(0), Passport() {
    }

    ForeignPassport(string n, string date, string c, string number, string foreignNumber)
        : foreignPassportNumber(foreignNumber), countVisas(0), Passport(n, date, c, number) {
    }

    void AddVisa(string visa)
    {
        if (countVisas < 10)
        {
            visas[countVisas] = visa;
            countVisas++;
        }
        else
            cout << "Visa list is full" << endl;
    }

    void Print()const
    {
        cout << "------------------Foreign passport------------------" << endl;
        Passport::Print();
        cout << "Foreign passport number : " << foreignPassportNumber << endl;
        cout << "Visas : " << endl;

        if (countVisas == 0)
            cout << "No visas" << endl;
        else
            for (int i = 0; i < countVisas; i++)
                cout << i + 1 << ". " << visas[i] << endl;
    }
};

int main()
{

    Aspirant aspirant("Mark Tsyganenko",13,"PD-621","Object oriented programming in C++");

    aspirant.Print();
    aspirant.WriteDissertation(15);
    aspirant.WriteDissertation(20);
    aspirant.DefendDissertation();
    aspirant.Print();
    cout << endl;

    ForeignPassport passport("Petruk Ivanovuch","09.06.2002","Ukraine","AA123456","ER123456");

    passport.AddVisa("Poland, 2026");
    passport.AddVisa("Germany, 2027");
    passport.Print();
}
