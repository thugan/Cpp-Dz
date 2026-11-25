#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;

	bool operator==(const Date& other) const
	{
		return day == other.day && month == other.month && year == other.year;
	}

	bool operator<(const Date& other) const
	{
		if (year != other.year)
			return year < other.year;
		if (month != other.month)
			return month < other.month;
		return day < other.day;
	}
};

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.day << "." << date.month << "." << date.year;
	return os;
}

istream& operator>>(istream& is, Date& date)
{
	char separator;
	is >> date.day >> separator >> date.month >> separator >> date.year;
	return is;
}

class TicketRequest
{
	string destination;
	int flightNumber;
	string passenger;
	Date departureDate;

public:
	TicketRequest() : flightNumber(0), departureDate{ 0, 0, 0 } {}

	TicketRequest(string destination, int flightNumber,
		string passenger, Date departureDate)
		: destination(destination), flightNumber(flightNumber),
		passenger(passenger), departureDate(departureDate) {
	}

	string GetDestination() const
	{
		return destination;
	}

	int GetFlightNumber() const
	{
		return flightNumber;
	}

	string GetPassenger() const
	{
		return passenger;
	}

	Date GetDepartureDate() const
	{
		return departureDate;
	}

	void Show() const
	{
		cout << "Destination: " << destination << endl;
		cout << "Flight number: " << flightNumber << endl;
		cout << "Passenger: " << passenger << endl;
		cout << "Departure date: " << departureDate << endl;
		cout << "------------------------------" << endl;
	}

	bool operator<(const TicketRequest& other) const
	{
		return departureDate < other.departureDate;
	}

	friend ostream& operator<<(ostream& os, const TicketRequest& request);
	friend istream& operator>>(istream& is, TicketRequest& request);
};

ostream& operator<<(ostream& os, const TicketRequest& request)
{
	
	os << request.destination << "|"
		<< request.flightNumber << "|"
		<< request.passenger << "|"
		<< request.departureDate;
	return os;
}

istream& operator>>(istream& is, TicketRequest& request)
{
	if (!getline(is, request.destination, '|'))
		return is;

	is >> request.flightNumber;
	is.ignore(1, '|');
	getline(is, request.passenger, '|');
	is >> request.departureDate;
	is.ignore(1000, '\n');
	return is;
}

bool CompareByDestination(const TicketRequest& request1,
	const TicketRequest& request2)
{
	return request1.GetDestination() < request2.GetDestination();
}

class TicketOffice
{
	list<TicketRequest> requests;

	void AddRequest()
	{
		string destination;
		int flightNumber;
		string passenger;
		Date departureDate;

		cout << "Enter destination: ";
		cin >> destination;
		cout << "Enter flight number: ";
		cin >> flightNumber;
		cout << "Enter passenger surname and initials: ";
		cin >> passenger;
		cout << "Enter departure date (day.month.year): ";
		cin >> departureDate;

		requests.push_back(TicketRequest(destination, flightNumber,
			passenger, departureDate));
		cout << "Request added." << endl;
	}

	void DeleteByPassenger()
	{
		string passenger;
		int deleted = 0;

		cout << "Enter passenger surname and initials: ";
		cin >> passenger;

		for (list<TicketRequest>::iterator i = requests.begin();
			i != requests.end();)
		{
			if (i->GetPassenger() == passenger)
			{
				i = requests.erase(i);
				deleted++;
			}
			else
				i++;
		}

		cout << "Deleted requests: " << deleted << endl;
	}

	void DeleteByFlight()
	{
		int flightNumber;
		int deleted = 0;

		cout << "Enter flight number: ";
		cin >> flightNumber;

		for (list<TicketRequest>::iterator i = requests.begin();
			i != requests.end();)
		{
			if (i->GetFlightNumber() == flightNumber)
			{
				i = requests.erase(i);
				deleted++;
			}
			else
				i++;
		}

		cout << "Deleted requests: " << deleted << endl;
	}

	void ShowByFlight() const
	{
		int flightNumber;
		bool found = false;

		cout << "Enter flight number: ";
		cin >> flightNumber;

		for (list<TicketRequest>::const_iterator i = requests.begin();
			i != requests.end(); i++)
		{
			if (i->GetFlightNumber() == flightNumber)
			{
				i->Show();
				found = true;
			}
		}

		if (!found)
			cout << "No requests with this flight number." << endl;
	}

	void ShowByDate() const
	{
		Date date;
		bool found = false;

		cout << "Enter departure date (day.month.year): ";
		cin >> date;

		for (list<TicketRequest>::const_iterator i = requests.begin();
			i != requests.end(); i++)
		{
			if (i->GetDepartureDate() == date)
			{
				i->Show();
				found = true;
			}
		}

		if (!found)
			cout << "No requests with this departure date." << endl;
	}

	void ShowAll() const
	{
		if (requests.empty())
		{
			cout << "The request list is empty." << endl;
			return;
		}

		for (list<TicketRequest>::const_iterator i = requests.begin();
			i != requests.end(); i++)
			i->Show();
	}

	void SortByDate()
	{
		requests.sort();
		cout << "Requests sorted by departure date." << endl;
	}

	void SortByDestination()
	{
		requests.sort(CompareByDestination);
		cout << "Requests sorted by destination." << endl;
	}

	void SaveToFile()
	{
		ofstream file("air_tickets.txt");

		if (!file)
		{
			cout << "Error opening file." << endl;
			return;
		}

		for (list<TicketRequest>::iterator i = requests.begin();
			i != requests.end(); i++)
			file << *i << endl;

		file.close();
		cout << "Requests saved to air_tickets.txt" << endl;
	}

	void LoadFromFile()
	{
		ifstream file("air_tickets.txt");

		if (!file)
		{
			cout << "Error opening file." << endl;
			return;
		}

		requests.clear();
		TicketRequest request;

		while (file >> request)
			requests.push_back(request);

		file.close();
		cout << "Requests loaded from air_tickets.txt" << endl;
	}

public:
	void Menu()
	{
		int choice;

		do
		{
			cout << endl;
			cout << "========== AIR TICKET OFFICE ==========" << endl;
			cout << "1. Add request" << endl;
			cout << "2. Delete requests by passenger" << endl;
			cout << "3. Delete requests by flight number" << endl;
			cout << "4. Show requests by flight number" << endl;
			cout << "5. Show requests by departure date" << endl;
			cout << "6. Show all requests" << endl;
			cout << "7. Sort requests by departure date" << endl;
			cout << "8. Sort requests by destination" << endl;
			cout << "9. Save requests to file" << endl;
			cout << "10. Load requests from file" << endl;
			cout << "0. Exit" << endl;
			cout << "Choose: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				AddRequest();
				break;
			case 2:
				DeleteByPassenger();
				break;
			case 3:
				DeleteByFlight();
				break;
			case 4:
				ShowByFlight();
				break;
			case 5:
				ShowByDate();
				break;
			case 6:
				ShowAll();
				break;
			case 7:
				SortByDate();
				break;
			case 8:
				SortByDestination();
				break;
			case 9:
				SaveToFile();
				break;
			case 10:
				LoadFromFile();
				break;
			case 0:
				cout << "Program finished." << endl;
				break;
			default:
				cout << "IDK WHAT IS THIS" << endl;
			}
		} while (choice != 0);
	}
};

int main()
{
	TicketOffice office;
	office.Menu();

	system("pause");
	return 0;
}
