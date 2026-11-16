#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name;
    string place;
    int age;
    int maxAge;
    bool alive;
protected:
    void PrintBaseInfo()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Age : " << age << endl;
        cout << "Max age : " << maxAge << endl;
        cout << "Alive : " << (alive ? "yes" : "no") << endl;
    }
public:
    Animal()
        : name("no name"), place("no place"), age(0), maxAge(0), alive(true) {
    }

    Animal(string n, string p, int a, int max)
        : name(n), place(p), age(a > 0 ? a : 0), maxAge(max > 0 ? max : 0), alive(true) {
    }

    virtual void Show()const
    {
        PrintBaseInfo();
    }

    void GrowOlder()
    {
        if (!alive)
            return;

        age++;
        if (maxAge > 0 && age >= maxAge)
        {
            alive = false;
            cout << name << " died because of old age" << endl;
        }
    }

    void Die()
    {
        if (alive)
        {
            alive = false;
            cout << name << " died" << endl;
        }
    }

    bool IsAlive()const
    {
        return alive;
    }

    string GetName()const
    {
        return name;
    }
};

class Plant
{
private:
    string name;
    string place;
protected:
    int amount;
    void PrintBaseInfo()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Amount : " << amount << endl;
    }
public:
    Plant() : name("no name"), place("no place"), amount(0) {}
    Plant(string n, string p, int a)
        : name(n), place(p), amount(a > 0 ? a : 0) {
    }

    virtual void Show()const
    {
        PrintBaseInfo();
    }

    int GetAmount()const
    {
        return amount;
    }

    void Consume(int value)
    {
        if (value > 0)
        {
            amount -= value;
            if (amount < 0)
                amount = 0;
        }
    }
};

class Grass : public Plant
{
public:
    Grass() : Plant("Grass", "no place", 0) {}
    Grass(string p, int a) : Plant("Grass", p, a) {}

    void Show()const override
    {
        cout << "----------------------Grass-----------------" << endl;
        Plant::Show();
    }
};

class Rabbit : public Animal
{
public:
    Rabbit() : Animal("no rabbit", "no place", 0, 8) {}
    Rabbit(string n, string p, int a) : Animal(n, p, a, 8) {}

    void EatGrass(Grass& grass)
    {
        if (IsAlive() && grass.GetAmount() > 0)
        {
            grass.Consume(1);
            cout << GetName() << " eats grass" << endl;
        }
    }

    void Show()const override
    {
        cout << "----------------------Rabbit-----------------" << endl;
        Animal::Show();
    }
};

class Fox : public Animal
{
public:
    Fox() : Animal("no fox", "no place", 0, 12) {}
    Fox(string n, string p, int a) : Animal(n, p, a, 12) {}

    void EatRabbit(Rabbit& rabbit)
    {
        if (IsAlive() && rabbit.IsAlive())
        {
            cout << GetName() << " eats " << rabbit.GetName() << endl;
            rabbit.Die();
        }
    }

    void Show()const override
    {
        cout << "----------------------Fox-----------------" << endl;
        Animal::Show();
    }
};

class Life
{
private:
    static const int maxFoxes = 5;
    static const int maxRabbits = 20;
    string place;
    int day;
    Grass grass;
    Fox foxes[maxFoxes];
    Rabbit rabbits[maxRabbits];
    int foxCount;
    int rabbitCount;

    void RemoveDeadFoxes()
    {
        int i = 0;
        while (i < foxCount)
        {
            if (!foxes[i].IsAlive())
            {
                for (int j = i; j < foxCount - 1; j++)
                    foxes[j] = foxes[j + 1];

                foxCount--;
            }
            else
                i++;
        }
    }

    void RemoveDeadRabbits()
    {
        int i = 0;
        while (i < rabbitCount)
        {
            if (!rabbits[i].IsAlive())
            {
                for (int j = i; j < rabbitCount - 1; j++)
                    rabbits[j] = rabbits[j + 1];

                rabbitCount--;
            }
            else
                i++;
        }
    }

public:
    Life() : place("no place"), day(0), grass("no place", 0), foxCount(0), rabbitCount(0) {}

    Life(string p, int grassAmount)
        : place(p), day(0), grass(p, grassAmount), foxCount(0), rabbitCount(0) {
    }

    void AddFox(string name, int age)
    {
        if (foxCount >= maxFoxes)
        {
            cout << "There can be no more foxes in this place" << endl;
            return;
        }

        foxes[foxCount] = Fox(name, place, age);
        foxCount++;
        cout << name << " appeared in the place" << endl;
    }

    void AddRabbit(string name, int age)
    {
        if (rabbitCount >= maxRabbits)
        {
            cout << "There can be no more rabbits in this place" << endl;
            return;
        }

        rabbits[rabbitCount] = Rabbit(name, place, age);
        rabbitCount++;
        cout << name << " appeared in the place" << endl;
    }

    void LiveOneDay()
    {
        day++;
        cout << endl << "================ Day " << day << " ================" << endl;

        for (int i = 0; i < foxCount; i++)
            foxes[i].GrowOlder();

        for (int i = 0; i < rabbitCount; i++)
            rabbits[i].GrowOlder();

        RemoveDeadFoxes();
        RemoveDeadRabbits();

        if (grass.GetAmount() > rabbitCount)
        {
            cout << "There is more grass than rabbits. Grass will remain after feeding" << endl;
        }
        else
        {
            cout << "There is not enough grass. Rabbits eat all grass" << endl;
        }

        for (int i = 0; i < rabbitCount && grass.GetAmount() > 0; i++)
            rabbits[i].EatGrass(grass);

        if (rabbitCount < foxCount)
        {
            cout << "There are fewer rabbits than foxes. Foxes hunt" << endl;
            for (int i = 0; i < foxCount && rabbitCount > 0; i++)
            {
                foxes[i].EatRabbit(rabbits[0]);
                RemoveDeadRabbits();
            }
        }
        else
            cout << "There are enough rabbits. Foxes do not hunt today" << endl;
    }

    void Show()const
    {
        cout << endl << "******************** LIFE ********************" << endl;
        cout << "Place : " << place << endl;
        cout << "Day : " << day << endl;
        cout << "Foxes : " << foxCount << endl;
        for (int i = 0; i < foxCount; i++)
            foxes[i].Show();

        cout << "Rabbits : " << rabbitCount << endl;
        for (int i = 0; i < rabbitCount; i++)
            rabbits[i].Show();

        grass.Show();
    }
};

int main()
{
    Life forest("Forest", 2);

    forest.AddFox("Red fox", 11);
    forest.AddFox("Quick fox", 3);
    forest.AddFox("Old fox", 5);
    forest.AddFox("Small fox", 2);
    forest.AddFox("Hunter fox", 4);
    forest.AddFox("Extra fox", 1);

    forest.AddRabbit("White rabbit", 2);
    forest.AddRabbit("Gray rabbit", 1);

    forest.Show();
    forest.LiveOneDay();
    forest.Show();

    Life meadow("Meadow", 6);
    meadow.AddFox("Meadow fox", 2);
    meadow.AddRabbit("Meadow rabbit 1", 1);
    meadow.AddRabbit("Meadow rabbit 2", 1);
    meadow.AddRabbit("Meadow rabbit 3", 1);
    meadow.Show();
    meadow.LiveOneDay();
    meadow.Show();
}
