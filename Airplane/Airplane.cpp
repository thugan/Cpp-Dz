#include <iostream>

using namespace std;

class Airplane
{
    string model;
    string type;
    int passengers;
    int maxPassengers;
public:
    Airplane()
    {
        this->model = "No model";
        this->type = "No type";
        this->passengers = 0;
        this->maxPassengers = 0;
    }
    Airplane(string model, string type, int passengers, int maxPassengers)
    {
        this->model = model;
        this->type = type;
        this->passengers = passengers;
        this->maxPassengers = maxPassengers;
    }
    void Print()const
    {
        cout << "Model: " << model << endl;
        cout << "Type: " << type << endl;
        cout << "Passengers: " << passengers << endl;
        cout << "Maximum passengers: " << maxPassengers << endl;
    }
    Airplane operator++()
    {
        if (this->passengers < this->maxPassengers)
            this->passengers++;
        return *this;
    }
    Airplane operator--()
    {
        this->passengers--;
        return *this;
    }
    void operator()(int count)
    {
        if (this->passengers + count <= this->maxPassengers)
            this->passengers += count;
    }
    friend bool operator==(const Airplane& left, const Airplane& right);
    friend bool operator>(const Airplane& left, const Airplane& right);
};

bool operator==(const Airplane& left, const Airplane& right)
{
    return left.type == right.type;
}

bool operator>(const Airplane& left, const Airplane& right)
{
    return left.maxPassengers > right.maxPassengers;
}

int main()
{
    Airplane airplane1("Boeing 737", "Passenger", 100, 180);
    Airplane airplane2("Airbus A320", "Passenger", 150, 186);
    Airplane airplane3("F-16", "Military", 1, 1);

    airplane1.Print();
    cout << endl;

    if (airplane1 == airplane2)
        cout << "Airplane types are equal" << endl;
    else
        cout << "Airplane types are different" << endl;

    if (airplane1 > airplane2)
        cout << "The first airplane can carry more passengers" << endl;
    else
        cout << "The second airplane can carry more passengers" << endl;

    ++airplane1;
    airplane1(15);
    --airplane1;
    airplane1.Print();
    cout << endl;

    airplane3(15);
    airplane3.Print();
}
