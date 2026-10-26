#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Abonent
{
    string name;
    string surname;
    string fathername;
    string phonenumber;
    string info;
    static int count;

public:
    Abonent()
        : name("no name"),
        surname("no surname"),
        fathername("no fathername"),
        phonenumber("+380123456789"),
        info("I don't know anything")
    {
        count++;
    }

    Abonent(string name) : Abonent()
    {
        this->name = name;
    }

    Abonent(string name, string surname) : Abonent(name)
    {
        this->surname = surname;
    }

    Abonent(string name, string surname, string fathername)
        : Abonent(name, surname)
    {
        this->fathername = fathername;
    }

    Abonent(string name, string surname, string fathername, string phonenumber)
        : Abonent(name, surname, fathername)
    {
        this->phonenumber = phonenumber;
    }

    Abonent(string name, string surname, string fathername,
        string phonenumber, string info)
        : Abonent(name, surname, fathername, phonenumber)
    {
        this->info = info;
    }

    static int getCount()
    {
        return count;
    }

    string getName() const
    {
        return name;
    }

    string getSurname() const
    {
        return surname;
    }

    string getFathername() const
    {
        return fathername;
    }

    string getPhonenumber() const
    {
        return phonenumber;
    }

    string getInfo() const
    {
        return info;
    }

    string getFullName() const
    {
        return name + " " + surname + " " + fathername;
    }

    void Print() const
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Fathername: " << fathername << endl;
        cout << "Phonenumber: " << phonenumber << endl;
        cout << "Info: " << info << endl << endl;
    }
};

int Abonent::count = 0;

class PhoneBook
{
    Abonent* abonents;
    int countAbonent;

    int FindByPhone(string phone) const
    {
        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].getPhonenumber() == phone)
            {
                return i;
            }
        }

        return -1;
    }

public:
    PhoneBook() : abonents(nullptr), countAbonent(0)
    {
    }

    ~PhoneBook()
    {
        if (abonents != nullptr)
        {
            delete[] abonents;
        }
    }

    void Add(Abonent a)
    {
        if (FindByPhone(a.getPhonenumber()) != -1)
        {
            cout << "An abonent with this phone number already exists."
                << endl;
            return;
        }

        // Такий спосіб зміни розміру масиву використовується в прикладах
        // Library з навчального репозиторію.
        Abonent* temp = new Abonent[countAbonent + 1];

        for (int i = 0; i < countAbonent; i++)
        {
            temp[i] = abonents[i];
        }

        temp[countAbonent] = a;

        if (abonents != nullptr)
        {
            delete[] abonents;
        }

        abonents = temp;
        countAbonent++;
    }

    void Delete(string phone)
    {
        int index = FindByPhone(phone);

        if (index == -1)
        {
            cout << "Abonent was not found." << endl;
            return;
        }

        Abonent* temp = nullptr;

        if (countAbonent > 1)
        {
            temp = new Abonent[countAbonent - 1];

            for (int i = 0, j = 0; i < countAbonent; i++)
            {
                if (i != index)
                {
                    temp[j] = abonents[i];
                    j++;
                }
            }
        }

        delete[] abonents;
        abonents = temp;
        countAbonent--;

        cout << "Abonent was deleted." << endl;
    }

    void SearchByName(string name) const
    {
        bool found = false;

        for (int i = 0; i < countAbonent; i++)
        {
            // Пошук працює як за повним ПІБ, так і за окремою його частиною.
            if (abonents[i].getFullName().find(name) != string::npos)
            {
                abonents[i].Print();
                found = true;
            }
        }

        if (!found)
        {
            cout << "Abonent was not found." << endl;
        }
    }

    void SearchByPhone(string phone) const
    {
        int index = FindByPhone(phone);

        if (index == -1)
        {
            cout << "Abonent was not found." << endl;
            return;
        }

        abonents[index].Print();
    }

    void ShowAll() const
    {
        if (countAbonent == 0)
        {
            cout << "Phone book is empty." << endl;
            return;
        }

        for (int i = 0; i < countAbonent; i++)
        {
            cout << "Abonent #" << i + 1 << endl;
            abonents[i].Print();
        }
    }

    bool SaveToFile(string fileName, string phone) const
    {
        int index = FindByPhone(phone);

        if (index == -1)
        {
            cout << "Abonent was not found." << endl;
            return false;
        }

        ofstream fout(fileName);

        if (!fout)
        {
            cout << "Could not open file for writing." << endl;
            return false;
        }

        const Abonent& a = abonents[index];
        fout << a.getName() << endl;
        fout << a.getSurname() << endl;
        fout << a.getFathername() << endl;
        fout << a.getPhonenumber() << endl;
        fout << a.getInfo() << endl;

        fout.close();
        cout << "One abonent was saved to the file." << endl;
        return true;
    }

    bool LoadFromFile(string fileName)
    {
        ifstream fin(fileName);

        if (!fin)
        {
            cout << "Could not open file for reading." << endl;
            return false;
        }

        string name;
        string surname;
        string fathername;
        string phonenumber;
        string info;

        if (!getline(fin, name) ||
            !getline(fin, surname) ||
            !getline(fin, fathername) ||
            !getline(fin, phonenumber) ||
            !getline(fin, info))
        {
            cout << "The file does not contain one complete abonent." << endl;
            return false;
        }

        if (FindByPhone(phonenumber) != -1)
        {
            cout << "An abonent with this phone number already exists." << endl;
            return false;
        }

        Add(Abonent(name, surname, fathername, phonenumber, info));
        cout << "One abonent was loaded from the file." << endl;
        return true;
    }

    int getCountAbonent() const
    {
        return countAbonent;
    }
};

string ReadLine(string message)
{
    cout << message;
    string value;
    getline(cin, value);
    return value;
}

void PrintMenu()
{
    cout << "\n===== PHONE BOOK =====" << endl;
    cout << "1. Add abonent" << endl;
    cout << "2. Delete abonent by phone" << endl;
    cout << "3. Search by full name" << endl;
    cout << "4. Search by phone" << endl;
    cout << "5. Show all abonents" << endl;
    cout << "6. Save one abonent to file" << endl;
    cout << "7. Load one abonent from file" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

int main()
{
    PhoneBook phoneBook;
    int choice;

    do
    {
        PrintMenu();

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a number from the menu." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
        {
            string name = ReadLine("Name: ");
            string surname = ReadLine("Surname: ");
            string fathername = ReadLine("Fathername: ");
            string phone = ReadLine("Phone number: ");
            string info = ReadLine("Info: ");

            phoneBook.Add(Abonent(name, surname, fathername, phone, info));
            break;
        }
        case 2:
            phoneBook.Delete(ReadLine("Phone number: "));
            break;
        case 3:
            phoneBook.SearchByName(ReadLine("Full name or part of it: "));
            break;
        case 4:
            phoneBook.SearchByPhone(ReadLine("Phone number: "));
            break;
        case 5:
            phoneBook.ShowAll();
            break;
        case 6:
        {
            string fileName = ReadLine("File name: ");
            string phone = ReadLine("Phone number of abonent: ");
            phoneBook.SaveToFile(fileName, phone);
            break;
        }
        case 7:
            phoneBook.LoadFromFile(ReadLine("File name: "));
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Unknown menu option." << endl;
        }
    } while (choice != 0);

    return 0;
}
