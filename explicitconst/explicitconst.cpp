#include <iostream>

using namespace std;

//class Book
//{
//private:
//    string author;
//    string title;
//    string publisher;
//    int year;
//    int quantity;
//    int pages;
//
//public:
//    explicit Book(string author, string title, string publisher,
//        int year, int quantity, int pages)
//        : author(author), title(title), publisher(publisher),
//        year(year), quantity(quantity), pages(pages)
//    {
//    }
//
//    string getAuthor() const
//    {
//        return author;
//    }
//
//    string getPublisher() const
//    {
//        return publisher;
//    }
//
//    int getYear() const
//    {
//        return year;
//    }
//
//    void Print() const
//    {
//        cout << "Author: " << author << endl;
//        cout << "Title: " << title << endl;
//        cout << "Publisher: " << publisher << endl;
//        cout << "Year: " << year << endl;
//        cout << "Quantity: " << quantity << endl;
//        cout << "Pages: " << pages << endl;
//        cout << "-----------------------------" << endl;
//    }
//};
//
//void PrintBooksByAuthor(const Book books[], int count, string author)
//{
//    bool found = false;
//
//    for (int i = 0; i < count; i++)
//    {
//        if (books[i].getAuthor() == author)
//        {
//            books[i].Print();
//            found = true;
//        }
//    }
//
//    if (!found)
//    {
//        cout << "Books by the selected author were not found." << endl;
//    }
//}
//
//void PrintBooksByPublisher(const Book books[], int count, string publisher)
//{
//    bool found = false;
//
//    for (int i = 0; i < count; i++)
//    {
//        if (books[i].getPublisher() == publisher)
//        {
//            books[i].Print();
//            found = true;
//        }
//    }
//
//    if (!found)
//    {
//        cout << "Books by the selected publisher were not found." << endl;
//    }
//}
//
//void PrintBooksAfterYear(const Book books[], int count, int year)
//{
//    bool found = false;
//
//    for (int i = 0; i < count; i++)
//    {
//        if (books[i].getYear() > year)
//        {
//            books[i].Print();
//            found = true;
//        }
//    }
//
//    if (!found)
//    {
//        cout << "Books published after the selected year were not found." << endl;
//    }
//}

class Worker
{
private:
    string fullName;
    string position;
    int employmentYear;
    double salary;

public:
    explicit Worker(string fullName, string position,
        int employmentYear, double salary)
        : fullName(fullName), position(position),
        employmentYear(employmentYear), salary(salary)
    {
    }

    string getPosition() const
    {
        return position;
    }

    double getSalary() const
    {
        return salary;
    }

    int getExperience(int currentYear) const
    {
        return currentYear - employmentYear;
    }

    void Print() const
    {
        cout << "Full name: " << fullName << endl;
        cout << "Position: " << position << endl;
        cout << "Employment year: " << employmentYear << endl;
        cout << "Salary: " << salary << endl;
        cout << "-----------------------------" << endl;
    }
};

void PrintWorkersByExperience(const Worker workers[], int count,
    int currentYear, int requiredYears)
{
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (workers[i].getExperience(currentYear) > requiredYears)
        {
            workers[i].Print();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Workers with the selected experience were not found." << endl;
    }
}

void PrintWorkersBySalary(const Worker workers[], int count, double salary)
{
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (workers[i].getSalary() > salary)
        {
            workers[i].Print();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Workers with a higher salary were not found." << endl;
    }
}

void PrintWorkersByPosition(const Worker workers[], int count,
    string position)
{
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (workers[i].getPosition() == position)
        {
            workers[i].Print();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Workers with the selected position were not found." << endl;
    }
}

int main()
{
    /*const int bookCount = 5;
    Book books[bookCount] =
    {
        Book("Taras Shevchenko", "Kobzar", "Folio", 2019, 3, 352),
        Book("Lina Kostenko", "Marusia Churai", "A-BA-BA-HA-LA-MA-HA", 2018, 2, 336),
        Book("Taras Shevchenko", "Haidamaky", "Folio", 2021, 4, 128),
        Book("George Orwell", "1984", "Family Leisure Club", 2022, 5, 320),
        Book("Lina Kostenko", "Notes of a Ukrainian Madman", "A-BA-BA-HA-LA-MA-HA", 2010, 1, 416)
    };

    cout << "TASK 1. BOOKS" << endl;
    cout << endl << "Books by the selected author:" << endl;
    PrintBooksByAuthor(books, bookCount, "Taras Shevchenko");

    cout << endl << "Books by the selected publisher:" << endl;
    PrintBooksByPublisher(books, bookCount, "Folio");

    cout << endl << "Books published after 2020:" << endl;
    PrintBooksAfterYear(books, bookCount, 2020);*/

    const int workerCount = 5;
    Worker workers[workerCount] =
    {
        Worker("Ivanenko Ivan Ivanovych", "programmer", 2016, 42000),
        Worker("Petrenko Olena Serhiivna", "manager", 2021, 30000),
        Worker("Sydorenko Andrii Oleksandrovych", "programmer", 2018, 50000),
        Worker("Kovalenko Mariia Ihorivna", "accountant", 2014, 38000),
        Worker("Melnyk Dmytro Vasylovych", "designer", 2023, 28000)
    };

    const int currentYear = 2026;

    cout << endl << "Workers with more than 5 years of experience:" << endl;
    PrintWorkersByExperience(workers, workerCount, currentYear, 5);

    cout << endl << "Workers with a salary greater than 35000:" << endl;
    PrintWorkersBySalary(workers, workerCount, 35000);

    cout << endl << "Workers with the programmer position:" << endl;
    PrintWorkersByPosition(workers, workerCount, "programmer");

    return 0;
}
