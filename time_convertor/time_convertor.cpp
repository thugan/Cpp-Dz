#include <iostream>
using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;
public:
    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int seconds) {
        hours = seconds / 3600;
        minutes = (seconds / 60) % 60;
        this->seconds = seconds % 60;
    }
    Time(int hours, int minutes, int seconds) {
        this->seconds = seconds % 60;
        this->hours = hours;
        this->minutes = minutes % 60;
    }
    void PlusSecond() {
        seconds += 1;
        if (seconds >= 60) {
            seconds -= 60;
            minutes +=1;
        }
        if (minutes >= 60) {
            minutes -= 60;
            hours += 1;
        }
    }
    void PlusMinute() {
        minutes += 1;
        if (minutes >= 60) {
            minutes -= 60;
            hours +=1;
        }
    }
    void PlusHour() {
        hours += 1;
    }
    void print() {
        if (hours < 10) {
            cout << "0" << hours << ":";
        }
        else {
            cout << hours << ":";
        }
        if (minutes < 10) {
            cout << "0" << minutes << ":";
        }
        else {
            cout << minutes << ":";
        }
        if (seconds < 10) {
            cout << "0" << seconds << endl;
        }
        else {
            cout << seconds << endl;
        }
    }
    Time operator +(const Time& other)
    {
        Time res(this->hours + other.hours, this->minutes + other.minutes, this->seconds + other.seconds);
        return res;
    }
    Time operator -(const Time& other)
    {
        Time res(this->hours - other.hours, this->minutes + other.minutes, this->seconds - other.seconds);
        if (res.hours|| res.seconds|| res.minutes) {
            cout << "ERROR" << endl;
        }
        return res;
    }
    Time operator *(const Time& other)
    {
        Time res(this->hours * other.hours, this->minutes + other.minutes, this->seconds * other.seconds);
        return res;
    }
    Time operator /(const Time& other)
    {
        Time res(this->hours / other.hours, this->minutes / other.minutes, this->seconds / other.seconds);
        return res;
    }
};
int main()
{
    Time t1{ 1000,61,121 };
    t1.print();
    Time t2{ 1000,61,121 };
    t2.print();
    (t1 + t2).print();
}