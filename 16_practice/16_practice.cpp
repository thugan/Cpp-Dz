#include <iostream>
using namespace std;

struct WashingMachine
{
	char company[20];
	char color[20];
	float width;
	float length;
	float height;
	int power;
	int spin_speed;
	int temperature;
};

struct Iron
{
	char company[20];
	char model[20];
	char color[20];
	int min_temperature;
	int max_temperature;
	bool steam;
	int power;
};

struct Boiler
{
	char company[20];
	char color[20];
	int power;
	int volume;
	int temperature;
};

union CarNumber
{
	int number;
	char word[9];
};

struct Car
{
	char color[20];
	char model[20];
	CarNumber number;
	bool is_number;
};

void ShowWashingMachine(WashingMachine& machine)
{
	cout << "\n------ Washing Machine ------" << endl;
	cout << "Company : " << machine.company << endl;
	cout << "Color : " << machine.color << endl;
	cout << "Width : " << machine.width << endl;
	cout << "Length : " << machine.length << endl;
	cout << "Height : " << machine.height << endl;
	cout << "Power : " << machine.power << endl;
	cout << "Spin speed : " << machine.spin_speed << endl;
	cout << "Temperature : " << machine.temperature << endl;
}

void ShowIron(Iron& iron)
{
	cout << "\n------ Iron ------" << endl;
	cout << "Company : " << iron.company << endl;
	cout << "Model : " << iron.model << endl;
	cout << "Color : " << iron.color << endl;
	cout << "Min temperature : " << iron.min_temperature << endl;
	cout << "Max temperature : " << iron.max_temperature << endl;

	if (iron.steam)
		cout << "Steam : Yes" << endl;
	else
		cout << "Steam : No" << endl;

	cout << "Power : " << iron.power << endl;
}

void ShowBoiler(Boiler& boiler)
{
	cout << "\n------ Boiler ------" << endl;
	cout << "Company : " << boiler.company << endl;
	cout << "Color : " << boiler.color << endl;
	cout << "Power : " << boiler.power << endl;
	cout << "Volume : " << boiler.volume << endl;
	cout << "Temperature : " << boiler.temperature << endl;
}

void InputCar(Car& car)
{
	cout << "Enter color : ";
	cin >> car.color;

	cout << "Enter model : ";
	cin >> car.model;

	cout << "Enter 1 if number is five-digit, 0 if it is a word : ";
	cin >> car.is_number;

	if (car.is_number)
	{
		cout << "Enter number : ";
		cin >> car.number.number;
	}
	else
	{
		cout << "Enter word : ";
		cin >> car.number.word;
	}
}

void ShowCar(Car& car)
{
	cout << "\n------ Car ------" << endl;
	cout << "Color : " << car.color << endl;
	cout << "Model : " << car.model << endl;

	if (car.is_number)
		cout << "Number : " << car.number.number << endl;
	else
		cout << "Number : " << car.number.word << endl;
}

void EditCar(Car& car)
{
	cout << "\n------ Edit Car ------" << endl;

	cout << "Enter color : ";
	cin >> car.color;

	cout << "Enter model : ";
	cin >> car.model;

	cout << "Enter 1 if number is five-digit, 0 if it is a word : ";
	cin >> car.is_number;

	if (car.is_number)
	{
		cout << "Enter number : ";
		cin >> car.number.number;
	}
	else
	{
		cout << "Enter word : ";
		cin >> car.number.word;
	}
}

void ShowAllCars(Car cars[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nCar #" << i + 1 << endl;
		ShowCar(cars[i]);
	}
}

void SearchCar(Car cars[], int size)
{
	int search_number;

	cout << "\nEnter number to search : ";
	cin >> search_number;

	for (int i = 0; i < size; i++)
	{
		if (cars[i].is_number && cars[i].number.number == search_number)
		{
			cout << "Car found!" << endl;
			ShowCar(cars[i]);
			return;
		}
	}

	cout << "Car not found!" << endl;
}

int main()
{
	WashingMachine machine = {
		"Samsung",
		"White",
		60,
		65,
		85,
		2000,
		1200,
		90
	};

	ShowWashingMachine(machine);

	Iron iron = {
		"Philips",
		"GC4909",
		"Blue",
		80,
		240,
		true,
		3000
	};

	ShowIron(iron);

	Boiler boiler = {
		"Bosch",
		"White",
		2000,
		80,
		75
	};

	ShowBoiler(boiler);

	Car car;

	InputCar(car);
	ShowCar(car);

	Car cars[10];

	for (int i = 0; i < 10; i++)
	{
		cout << "\nEnter car #" << i + 1 << endl;
		InputCar(cars[i]);
	}

	ShowAllCars(cars, 10);

	int index;

	cout << "\nEnter car number to edit (1-10) : ";
	cin >> index;

	if (index >= 1 && index <= 10)
	{
		EditCar(cars[index - 1]);
	}

	ShowAllCars(cars, 10);

	SearchCar(cars, 10);
}