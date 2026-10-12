#include <iostream>
#include <string>

using namespace std;

class Student
{
    string fullName;
    string birthDate;
    string phone;
    string city;
    string country;

    string universityName;
    string universityCity;
    string universityCountry;

    int groupNumber;

public:
    void InitStudent()
    {
        
        cin.ignore();

        cout << "Enter full name: ";
        getline(cin, fullName);

        cout << "Enter birth date: ";
        getline(cin, birthDate);

        cout << "Enter phone: ";
        getline(cin, phone);

        cout << "Enter city: ";
        getline(cin, city);

        cout << "Enter country: ";
        getline(cin, country);

        cout << "Enter educational institution: ";
        getline(cin, universityName);

        cout << "Enter institution city: ";
        getline(cin, universityCity);

        cout << "Enter institution country: ";
        getline(cin, universityCountry);

        cout << "Enter group number: ";
        cin >> groupNumber;
    }

    void PrintStudent()
    {
        cout << "\nStudent information:\n";
        cout << "Full name: " << fullName << endl;
        cout << "Birth date: " << birthDate << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "Educational institution: " << universityName << endl;
        cout << "Institution city: " << universityCity << endl;
        cout << "Institution country: " << universityCountry << endl;
        cout << "Group number: " << groupNumber << endl;
    }

    // Аксесори для отримання даних
    string getFullName()
    {
        return fullName;
    }

    string getPhone()
    {
        return phone;
    }

    int getGroupNumber()
    {
        return groupNumber;
    }

    void setFullName(string fullName)
    {
        this->fullName = fullName;
    }

    void setPhone(string phone)
    {
        this->phone = phone;
    }

    void setGroupNumber(int groupNumber)
    {
        this->groupNumber = groupNumber;
    }
};

int main()
{
    Student student;

    student.InitStudent();
    student.PrintStudent();
    cout<<student.getFullName() << endl;

    return 0;
}