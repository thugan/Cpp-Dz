#include <iostream>

using namespace std;

class Employer
{
private:
    string fullName;
    double salary;
protected:
    void PrintCommonInfo()const
    {
        cout << "Full name : " << fullName << endl;
        cout << "Salary : " << salary << endl;
    }
public:
    Employer() : fullName("no name"), salary(0) {}
    Employer(string n, double s) : fullName(n), salary(s) {}

    virtual void Print()const = 0;
};

class President : public Employer
{
private:
    string company;
    int numberOfEmployees;
public:
    President() : company("no company"), numberOfEmployees(0), Employer() {}
    President(string n, double s, string c, int employees)
        : company(c), numberOfEmployees(employees), Employer(n, s) {
    }

    void Print()const override
    {
        cout << "----------------------President-----------------" << endl;
        Employer::PrintCommonInfo();
        cout << "Company : " << company << endl;
        cout << "Number of employees : " << numberOfEmployees << endl;
    }
};

class Manager : public Employer
{
private:
    string department;
    int numberOfEmployees;
public:
    Manager() : department("no department"), numberOfEmployees(0), Employer() {}
    Manager(string n, double s, string d, int employees)
        : department(d), numberOfEmployees(employees), Employer(n, s) {
    }

    void Print()const override
    {
        cout << "----------------------Manager-----------------" << endl;
        Employer::PrintCommonInfo();
        cout << "Department : " << department << endl;
        cout << "Managed employees : " << numberOfEmployees << endl;
    }
};

class Worker : public Employer
{
private:
    string profession;
    int experience;
public:
    Worker() : profession("no profession"), experience(0), Employer() {}
    Worker(string n, double s, string p, int e)
        : profession(p), experience(e), Employer(n, s) {
    }

    void Print()const override
    {
        cout << "----------------------Worker-----------------" << endl;
        Employer::PrintCommonInfo();
        cout << "Profession : " << profession << endl;
        cout << "Experience : " << experience << " years" << endl;
    }
};

void TestEmployer(Employer& employer)
{
    employer.Print();
}

class Vehicle
{
private:
    string name;
protected:
    double speed;
    int passengerCapacity;
    double cargoCapacity;
    double passengerPricePerKm;
    double cargoPricePerKm;

    void PrintCommonInfo()const
    {
        cout << "Name : " << name << endl;
        cout << "Speed : " << speed << " km/h" << endl;
        cout << "Passenger capacity : " << passengerCapacity << endl;
        cout << "Cargo capacity : " << cargoCapacity << " kg" << endl;
    }

    int GetPassengerTrips(int passengers)const
    {
        if (passengers <= 0 || passengerCapacity <= 0)
            return 0;

        return (passengers + passengerCapacity - 1) / passengerCapacity;
    }

    int GetCargoTrips(double cargoWeight)const
    {
        if (cargoWeight <= 0 || cargoCapacity <= 0)
            return 0;

        return static_cast<int>(ceil(cargoWeight / cargoCapacity));
    }

    double GetTime(double distance, int trips)const
    {
        if (distance <= 0 || speed <= 0 || trips <= 0)
            return 0;

        return distance / speed * trips;
    }

    double GetCost(double distance, int trips, double pricePerKm)const
    {
        if (distance <= 0 || trips <= 0)
            return 0;

        return distance * trips * pricePerKm;
    }

public:
    Vehicle()
        : name("no name"), speed(0), passengerCapacity(0), cargoCapacity(0),
        passengerPricePerKm(0), cargoPricePerKm(0) {
    }

    Vehicle(string n, double s, int passengerCount, double cargoWeight,
        double passengerPrice, double cargoPrice)
        : name(n), speed(s), passengerCapacity(passengerCount),
        cargoCapacity(cargoWeight), passengerPricePerKm(passengerPrice),
        cargoPricePerKm(cargoPrice) {
    }

    virtual void Print()const = 0;
    virtual double GetPassengerTime(double distance, int passengers)const = 0;
    virtual double GetPassengerCost(double distance, int passengers)const = 0;
    virtual double GetCargoTime(double distance, double cargoWeight)const = 0;
    virtual double GetCargoCost(double distance, double cargoWeight)const = 0;
};

class Car : public Vehicle
{
private:
    double fuelConsumption;
public:
    Car() : fuelConsumption(0), Vehicle() {}
    Car(string n, double s, int passengerCount, double cargoWeight,
        double passengerPrice, double cargoPrice, double fuel)
        : fuelConsumption(fuel),
        Vehicle(n, s, passengerCount, cargoWeight, passengerPrice, cargoPrice) {
    }

    void Print()const override
    {
        cout << "----------------------Car-----------------" << endl;
        Vehicle::PrintCommonInfo();
        cout << "Fuel consumption : " << fuelConsumption << " l/100 km" << endl;
    }

    double GetPassengerTime(double distance, int passengers)const override
    {
        return GetTime(distance, GetPassengerTrips(passengers));
    }

    double GetPassengerCost(double distance, int passengers)const override
    {
        return GetCost(distance, GetPassengerTrips(passengers), passengerPricePerKm);
    }

    double GetCargoTime(double distance, double cargoWeight)const override
    {
        return GetTime(distance, GetCargoTrips(cargoWeight));
    }

    double GetCargoCost(double distance, double cargoWeight)const override
    {
        return GetCost(distance, GetCargoTrips(cargoWeight), cargoPricePerKm);
    }
};

class Bicycle : public Vehicle
{
private:
    int numberOfGears;
public:
    Bicycle() : numberOfGears(0), Vehicle() {}
    Bicycle(string n, double s, int passengerCount, double cargoWeight,
        double passengerPrice, double cargoPrice, int gears)
        : numberOfGears(gears),
        Vehicle(n, s, passengerCount, cargoWeight, passengerPrice, cargoPrice) {
    }

    void Print()const override
    {
        cout << "----------------------Bicycle-----------------" << endl;
        Vehicle::PrintCommonInfo();
        cout << "Number of gears : " << numberOfGears << endl;
    }

    double GetPassengerTime(double distance, int passengers)const override
    {
        return GetTime(distance, GetPassengerTrips(passengers));
    }

    double GetPassengerCost(double distance, int passengers)const override
    {
        return GetCost(distance, GetPassengerTrips(passengers), passengerPricePerKm);
    }

    double GetCargoTime(double distance, double cargoWeight)const override
    {
        return GetTime(distance, GetCargoTrips(cargoWeight));
    }

    double GetCargoCost(double distance, double cargoWeight)const override
    {
        return GetCost(distance, GetCargoTrips(cargoWeight), cargoPricePerKm);
    }
};

class Cart : public Vehicle
{
private:
    int numberOfHorses;
public:
    Cart() : numberOfHorses(0), Vehicle() {}
    Cart(string n, double s, int passengerCount, double cargoWeight,
        double passengerPrice, double cargoPrice, int horses)
        : numberOfHorses(horses),
        Vehicle(n, s, passengerCount, cargoWeight, passengerPrice, cargoPrice) {
    }

    void Print()const override
    {
        cout << "----------------------Cart-----------------" << endl;
        Vehicle::PrintCommonInfo();
        cout << "Number of horses : " << numberOfHorses << endl;
    }

    double GetPassengerTime(double distance, int passengers)const override
    {
        return GetTime(distance, GetPassengerTrips(passengers));
    }

    double GetPassengerCost(double distance, int passengers)const override
    {
        return GetCost(distance, GetPassengerTrips(passengers), passengerPricePerKm);
    }

    double GetCargoTime(double distance, double cargoWeight)const override
    {
        return GetTime(distance, GetCargoTrips(cargoWeight));
    }

    double GetCargoCost(double distance, double cargoWeight)const override
    {
        return GetCost(distance, GetCargoTrips(cargoWeight), cargoPricePerKm);
    }
};

void TestVehicle(Vehicle& vehicle, double distance, int passengers, double cargoWeight)
{
    cout << "========================================" << endl;
    vehicle.Print();
    cout << "Distance : " << distance << " km" << endl;
    cout << "Passengers : " << passengers << endl;
    cout << "Passenger transportation time : "
        << vehicle.GetPassengerTime(distance, passengers) << " hours" << endl;
    cout << "Passenger transportation cost : "
        << vehicle.GetPassengerCost(distance, passengers) << endl;
    cout << "Cargo weight : " << cargoWeight << " kg" << endl;
    cout << "Cargo transportation time : "
        << vehicle.GetCargoTime(distance, cargoWeight) << " hours" << endl;
    cout << "Cargo transportation cost : "
        << vehicle.GetCargoCost(distance, cargoWeight) << endl;
}

int main()
{

    President president("Oleg Illich", 120000, "IT Company", 250);
    Manager manager("Andrii Petrenko", 65000, "Development", 12);
    Worker worker("Maksym Bondar", 35000, "Software developer", 4);
    TestEmployer(president);
    TestEmployer(manager);
    TestEmployer(worker);

    cout << endl;

    Car car("Family car", 80, 4, 500, 2.5, 3.0, 8.5);
    Bicycle bicycle("City bicycle", 15, 1, 20, 0.2, 0.3, 18);
    Cart cart("Farm cart", 10, 2, 500, 1.0, 1.5, 1);

    TestVehicle(car, 120, 5, 700);
    TestVehicle(bicycle, 12, 1, 15);
    TestVehicle(cart, 30, 3, 800);
}
