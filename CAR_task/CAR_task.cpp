#include <iostream>
using namespace std;

class Engine
{
    string type;
    float volume;
    int horsePower;
    bool started;
public:
    Engine() : type("none"), volume(0), horsePower(0), started(false) {}
    Engine(string t, float v, int h)
        : type(t), volume(v), horsePower(h), started(false) {
    }

    void Start()
    {
        started = true;
        cout << "Engine started" << endl;
    }

    void Stop()
    {
        started = false;
        cout << "Engine stopped" << endl;
    }

    void ShowInfo()const
    {
        cout << "Engine type : " << type << endl;
        cout << "Engine volume : " << volume << " l" << endl;
        cout << "Horse power : " << horsePower << endl;
        cout << "Engine state : " << (started ? "started" : "stopped") << endl;
    }
};

class Body
{
    string type;
    string color;
    int doorsCount;
public:
    Body() : type("none"), color("none"), doorsCount(0) {}
    Body(string t, string c, int d)
        : type(t), color(c), doorsCount(d) {
    }

    void ShowInfo()const
    {
        cout << "Body type : " << type << endl;
        cout << "Body color : " << color << endl;
        cout << "Doors count : " << doorsCount << endl;
    }
};

class Wheel
{
    string brand;
    int diameter;
    bool winter;
public:
    Wheel() : brand("none"), diameter(0), winter(false) {}
    Wheel(string b, int d, bool w)
        : brand(b), diameter(d), winter(w) {
    }

    void Rotate()const
    {
        cout << "Wheel is rotating" << endl;
    }

    void ShowInfo()const
    {
        cout << "Wheel brand : " << brand << endl;
        cout << "Wheel diameter : " << diameter << " inches" << endl;
        cout << "Wheel type : " << (winter ? "winter" : "summer") << endl;
    }
};

class Door
{
    string type;
    bool opened;
public:
    Door() : type("none"), opened(false) {}
    Door(string t) : type(t), opened(false) {}

    void Open()
    {
        opened = true;
        cout << "Door opened" << endl;
    }

    void Close()
    {
        opened = false;
        cout << "Door closed" << endl;
    }

    void ShowInfo()const
    {
        cout << "Door type : " << type << endl;
        cout << "Door state : " << (opened ? "opened" : "closed") << endl;
    }
};

class Headlight
{
    string type;
    bool turnedOn;
public:
    Headlight() : type("none"), turnedOn(false) {}
    Headlight(string t) : type(t), turnedOn(false) {}

    void TurnOn()
    {
        turnedOn = true;
        cout << "Headlight turned on" << endl;
    }

    void TurnOff()
    {
        turnedOn = false;
        cout << "Headlight turned off" << endl;
    }

    void ShowInfo()const
    {
        cout << "Headlight type : " << type << endl;
        cout << "Headlight state : " << (turnedOn ? "on" : "off") << endl;
    }
};

class Driver
{
    string firstName;
    string lastName;
    int age;
    int experience;
public:
    Driver() : firstName("none"), lastName("none"), age(0), experience(0) {}
    Driver(string first, string last, int a, int e)
        : firstName(first), lastName(last), age(a), experience(e) {
    }

    void ShowInfo()const
    {
        cout << "First name : " << firstName << endl;
        cout << "Last name : " << lastName << endl;
        cout << "Age : " << age << endl;
        cout << "Driving experience : " << experience << " years" << endl;
    }
};

class Car
{
    string model;
    Engine engine;
    Body body;
    Wheel wheels[4];
    Door doors[4];
    Headlight lights[2];

    // Aggregation. Car does not create or delete the driver.
    Driver* driver;

    void InitializeParts()
    {
        for (int i = 0; i < 4; i++)
        {
            wheels[i] = Wheel("Michelin", 18, false);
            doors[i] = Door("side door");
        }

        lights[0] = Headlight("left headlight");
        lights[1] = Headlight("right headlight");
    }
public:
    Car()
        : model("none"), engine(), body(), driver(nullptr) {
    }

    Car(string m, Engine e, Body b)
        : model(m), engine(e), body(b), driver(nullptr)
    {
        InitializeParts();
    }

    Car(string m, Engine e, Body b, Driver* d)
        : model(m), engine(e), body(b), driver(d)
    {
        InitializeParts();
    }

    void AddDriver(Driver* driver)
    {
        this->driver = driver;
        cout << "Driver was added to the car" << endl;
    }

    bool RemoveDriver()
    {
        if (driver != nullptr)
        {
            driver = nullptr;
            cout << "Driver was removed from the car" << endl;
            return true;
        }

        cout << "There is no driver in the car" << endl;
        return false;
    }

    void Start()
    {
        cout << "Car " << model << " is starting" << endl;
        engine.Start();
    }

    void Stop()
    {
        engine.Stop();
        cout << "Car " << model << " stopped" << endl;
    }

    void OpenDoors()
    {
        for (int i = 0; i < 4; i++)
            doors[i].Open();
    }

    void CloseDoors()
    {
        for (int i = 0; i < 4; i++)
            doors[i].Close();
    }

    void TurnOnLights()
    {
        for (int i = 0; i < 2; i++)
            lights[i].TurnOn();
    }

    void TurnOffLights()
    {
        for (int i = 0; i < 2; i++)
            lights[i].TurnOff();
    }

    void Drive()
    {
        cout << "Car " << model << " is driving" << endl;
        for (int i = 0; i < 4; i++)
            wheels[i].Rotate();
    }

    void Show()const
    {
        cout << "==================== Car ====================" << endl;
        cout << "Model : " << model << endl;

        cout << endl << "Engine settings :" << endl;
        engine.ShowInfo();

        cout << endl << "Body settings :" << endl;
        body.ShowInfo();

        cout << endl << "Wheels :" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "Wheel " << i + 1 << endl;
            wheels[i].ShowInfo();
        }

        cout << endl << "Doors :" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "Door " << i + 1 << endl;
            doors[i].ShowInfo();
        }

        cout << endl << "Headlights :" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "Headlight " << i + 1 << endl;
            lights[i].ShowInfo();
        }

        cout << endl << "Driver :" << endl;
        if (driver != nullptr)
            driver->ShowInfo();
        else
            cout << "No driver" << endl;
    }

    void Print()const
    {
        Show();
    }
};

int main()
{
    Engine engine("petrol", 2.0, 150);
    Body body("sedan", "black", 4);
    Driver driver("Olena", "Ivanenko", 28, 7);

    Car car("Toyota", engine, body);
    car.AddDriver(&driver);
    car.Start();
    car.OpenDoors();
    car.CloseDoors();
    car.TurnOnLights();
    car.Drive();
    car.Show();

    cout << endl;
    car.TurnOffLights();
    car.Stop();
    car.RemoveDriver();
    car.Show();

    Driver secondDriver("Andrii", "Petrenko", 35, 12);
    Car secondCar("BMW", engine, body, &secondDriver);
    secondCar.Show();
}
