#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

struct Time
{
    short h;
    short m;
    short s;

    Time() : h(0), m(0), s(0) {}
    Time(short hour, short minute, short second)
        : h(hour), m(minute), s(second) {
    }

    bool operator<(const Time& other)const
    {
        if (h != other.h)
            return h < other.h;
        if (m != other.m)
            return m < other.m;
        return s < other.s;
    }
};

ostream& operator<<(ostream& out, const Time& time)
{
    if (time.h < 10)
        out << "0";
    out << time.h << ":";

    if (time.m < 10)
        out << "0";
    out << time.m << ":";

    if (time.s < 10)
        out << "0";
    out << time.s;
    return out;
}

istream& operator>>(istream& in, Time& time)
{
    char separator;
    in >> time.h >> separator >> time.m >> separator >> time.s;
    return in;
}

class Train
{
private:
    int number;
    Time departureTime;
    string destination;
public:
    Train() : number(0), departureTime(), destination("none") {}
    Train(int n, Time time, string destination)
        : number(n), departureTime(time), destination(destination) {
    }

    int getNumber()const
    {
        return number;
    }

    Time getDepartureTime()const
    {
        return departureTime;
    }

    string getDestination()const
    {
        return destination;
    }

    void setDepartureTime(Time time)
    {
        departureTime = time;
    }

    void Show()const
    {
        cout << "Train number : " << number << endl;
        cout << "Departure time : " << departureTime << endl;
        cout << "Destination : " << destination << endl;
    }

    bool operator<(const Train& other)const
    {
        return departureTime < other.departureTime;
    }

    friend ostream& operator<<(ostream& out, const Train& train);
    friend istream& operator>>(istream& in, Train& train);
};

ostream& operator<<(ostream& out, const Train& train)
{
    out << train.number << " "
        << train.departureTime << " "
        << train.destination;
    return out;
}

istream& operator>>(istream& in, Train& train)
{
    in >> train.number;
    in >> train.departureTime;
    in >> ws;
    getline(in, train.destination);
    return in;
}

class Railway
{
private:
    vector<Train> trains;
public:
    void AddTrain(const Train& train)
    {
        trains.push_back(train);
    }

    void ShowAll()const
    {
        cout << "================ ALL TRAINS ================" << endl;

        if (trains.empty())
        {
            cout << "No trains in the system" << endl;
            return;
        }

        for (int i = 0; i < trains.size(); i++)
        {
            cout << endl;
            trains[i].Show();
        }
    }

    bool ShowTrain(int number)const
    {
        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getNumber() == number)
            {
                cout << "============= TRAIN BY NUMBER =============" << endl;
                trains[i].Show();
                return true;
            }
        }

        cout << "Train with number " << number << " was not found" << endl;
        return false;
    }

    bool EditDepartureTime(int number, Time newTime)
    {
        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getNumber() == number)
            {
                trains[i].setDepartureTime(newTime);
                cout << "Departure time was changed" << endl;
                return true;
            }
        }

        cout << "Train with number " << number << " was not found" << endl;
        return false;
    }

    void SortByDepartureTime()
    {
        sort(trains.begin(), trains.end());
        cout << "Trains were sorted by departure time" << endl;
    }

    void ShowByDestination(string destination)const
    {
        cout << "======== TRAINS TO " << destination << " ========" << endl;
        bool found = false;

        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getDestination() == destination)
            {
                trains[i].Show();
                cout << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No trains to this destination" << endl;
    }

    bool SaveToFile(string fileName)const
    {
        ofstream file(fileName);
        if (!file.is_open())
            return false;

        for (int i = 0; i < trains.size(); i++)
            file << trains[i] << endl;

        file.close();
        return true;
    }

    bool LoadFromFile(string fileName)
    {
        ifstream file(fileName);
        if (!file.is_open())
            return false;

        trains.clear();
        Train train;
        while (file >> train)
            trains.push_back(train);

        file.close();
        return true;
    }
};

int main()
{
    Railway railway;
    railway.AddTrain(Train(101, Time(8, 30, 0), "Lviv"));
    railway.AddTrain(Train(205, Time(6, 15, 30), "Odesa"));
    railway.AddTrain(Train(312, Time(12, 45, 0), "Lviv"));
    railway.AddTrain(Train(410, Time(9, 10, 0), "Kharkiv"));
    railway.ShowAll();
    cout << endl;
    railway.ShowTrain(312);
    railway.ShowTrain(999);
    cout << endl;
    railway.EditDepartureTime(410, Time(5, 55, 0));
    railway.ShowTrain(410);
    cout << endl;
    railway.SortByDepartureTime();
    railway.ShowAll();
    cout << endl;
    railway.ShowByDestination("Lviv");
    string fileName = "trains.txt";
    if (railway.SaveToFile(fileName))
        cout << "Train list was saved to " << fileName << endl;
    else
        cout << "File cannot be opened for writing" << endl;
    Railway loadedRailway;
    if (loadedRailway.LoadFromFile(fileName))
    {
        cout << endl << "=========== LOADED FROM FILE ===========" << endl;
        loadedRailway.ShowAll();
    }
    else
        cout << "File cannot be opened for reading" << endl;
}
