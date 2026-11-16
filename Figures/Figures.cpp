#include <iostream>
#include <fstream>

#include <Windows.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void DrawLine(Point start, Point end)
{
    int x = start.x;
    int y = start.y;
    int dx = abs(end.x - start.x);
    int sx = start.x < end.x ? 1 : -1;
    int dy = -abs(end.y - start.y);
    int sy = start.y < end.y ? 1 : -1;
    int error = dx + dy;

    while (true)
    {
        gotoxy(x, y);
        cout << "*" << flush;

        if (x == end.x && y == end.y)
            break;

        int error2 = 2 * error;
        if (error2 >= dy)
        {
            error += dy;
            x += sx;
        }
        if (error2 <= dx)
        {
            error += dx;
            y += sy;
        }
    }
}

class Shape
{
private:
    string type;
protected:
    void PrintBaseInfo()const
    {
        cout << "Type : " << type << endl;
    }

    void SaveBaseInfo(ofstream& file)const
    {
        file << "Type : " << type << endl;
    }
public:
    Shape() : type("no type") {}
    Shape(string t) : type(t) {}

    virtual void Print()const = 0;
    virtual void Save(ofstream& file)const = 0;
    virtual ~Shape() = 0 {}
};

class Line : public Shape
{
private:
    Point start;
    Point end;
public:
    Line() : start{ 0, 0 }, end{ 0, 0 }, Shape("Line") {}
    Line(Point s, Point e) : start(s), end(e), Shape("Line") {}

    void Print()const override
    {
        cout << "----------------------Line-----------------" << endl;
        Shape::PrintBaseInfo();
        cout << "Start point : (" << start.x << ", " << start.y << ")" << endl;
        cout << "End point : (" << end.x << ", " << end.y << ")" << endl;

        DrawLine(start, end);
        gotoxy(0, end.y + 2);
    }

    void Save(ofstream& file)const override
    {
        SaveBaseInfo(file);
        file << "Start point : (" << start.x << ", " << start.y << ")" << endl;
        file << "End point : (" << end.x << ", " << end.y << ")" << endl;
        file << endl;
    }
};

class Rectangles : public Shape
{
private:
    Point topLeft;
    int width;
    int length;
public:
    Rectangles() : topLeft{ 0, 0 }, width(0), length(0), Shape("Rectangle") {}
    Rectangles(Point point, int w, int l)
        : topLeft(point), width(w), length(l), Shape("Rectangle") {
    }

    void Print()const override
    {
        cout << "----------------------Rectangle-----------------" << endl;
        Shape::PrintBaseInfo();
        cout << "Top left point : (" << topLeft.x << ", " << topLeft.y << ")" << endl;
        cout << "Width : " << width << endl;
        cout << "Length : " << length << endl;

        if (width > 0 && length > 0)
        {
            Point topRight{ topLeft.x + width, topLeft.y };
            Point bottomLeft{ topLeft.x, topLeft.y + length };
            Point bottomRight{ topLeft.x + width, topLeft.y + length };

            DrawLine(topLeft, topRight);
            DrawLine(topRight, bottomRight);
            DrawLine(bottomRight, bottomLeft);
            DrawLine(bottomLeft, topLeft);
            gotoxy(0, bottomRight.y + 2);
        }
    }

    void Save(ofstream& file)const override
    {
        SaveBaseInfo(file);
        file << "Top left point : (" << topLeft.x << ", " << topLeft.y << ")" << endl;
        file << "Width : " << width << endl;
        file << "Length : " << length << endl;
        file << endl;
    }
};

class Polylines : public Shape
{
private:
    Point* points;
    int countPoints;

    int GetMaxY()const
    {
        int maxY = 0;
        for (int i = 0; i < countPoints; i++)
        {
            if (points[i].y > maxY)
                maxY = points[i].y;
        }
        return maxY;
    }
public:
    Polylines() : points(nullptr), countPoints(0), Shape("Polyline") {}

    Polylines(initializer_list<Point> list)
        : points(nullptr), countPoints(list.size()), Shape("Polyline")
    {
        points = new Point[countPoints];

        int i = 0;
        for (Point point : list)
        {
            points[i] = point;
            i++;
        }
    }

    Polylines(const Polylines& other)
        : points(nullptr), countPoints(other.countPoints), Shape("Polyline")
    {
        if (countPoints > 0)
        {
            points = new Point[countPoints];
            for (int i = 0; i < countPoints; i++)
                points[i] = other.points[i];
        }
    }

    Polylines& operator=(const Polylines& other)
    {
        if (this != &other)
        {
            delete[] points;
            points = nullptr;
            countPoints = other.countPoints;

            if (countPoints > 0)
            {
                points = new Point[countPoints];
                for (int i = 0; i < countPoints; i++)
                    points[i] = other.points[i];
            }
        }
        return *this;
    }

    void Print()const override
    {
        cout << "----------------------Polyline-----------------" << endl;
        Shape::PrintBaseInfo();
        cout << "Number of points : " << countPoints << endl;
        cout << "Points : ";
        for (int i = 0; i < countPoints; i++)
            cout << "(" << points[i].x << ", " << points[i].y << ") ";
        cout << endl;

        if (countPoints == 1)
        {
            gotoxy(points[0].x, points[0].y);
            cout << "*" << flush;
        }
        else
        {
            for (int i = 0; i < countPoints - 1; i++)
                DrawLine(points[i], points[i + 1]);
        }

        gotoxy(0, GetMaxY() + 2);
    }

    void Save(ofstream& file)const override
    {
        SaveBaseInfo(file);
        file << "Number of points : " << countPoints << endl;
        file << "Points : ";
        for (int i = 0; i < countPoints; i++)
            file << "(" << points[i].x << ", " << points[i].y << ") ";
        file << endl << endl;
    }

    ~Polylines() override
    {
        delete[] points;
    }
};

int main()
{
    Shape* shapes[3]{
        new Line({ 5, 5 }, { 25, 5 }),
        new Rectangles({ 5, 15 }, 20, 6),
        new Polylines({ { 5, 26 }, { 12, 34 }, { 20, 30 }, { 28, 43 } })
    };

    ofstream file("shapes.txt");
    if (!file.is_open())
    {
        cout << "Error!!" << endl;
    } 

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->Print();
        if (file.is_open())
            shapes[i]->Save(file);
        cout << endl;
    } 

    if (file.is_open())
    {
        file.close();
        cout << " saved to shapes.txt" << endl;
    }

    for (int i = 0; i < 3; i++)
        delete shapes[i];
}
