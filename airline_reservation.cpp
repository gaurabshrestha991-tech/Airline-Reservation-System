#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Flight
{
    string flightNumber;
    string origin;
    string destination;
    int capacity;
    int bookedSeats;
};

void displayFlightDetails(const Flight& f)
{
    cout << "Flight Number: " << f.flightNumber << endl;
    cout << "Origin: " << f.origin << endl;
    cout << "Destination: " << f.destination << endl;
    cout << "Capacity: " << f.capacity << endl;
    cout << "Booked Seats: " << f.bookedSeats << endl;
}

void bookSeat(Flight& f)
{
    if(f.bookedSeats < f.capacity)
    {
        f.bookedSeats++;
        cout << "Seat Booked Successfully!" << endl;
    }
    else 
    {
        cout << "Sprry, the flight is full.No seats available." << endl;
    }
}

int main ()
{
    vector<Flight> flights = {
        { "F101", "New York", "Los Angeles", 200, 0},
        { "F102", "Los Angeles", "Chicago", 150, 0},
        { "F103", "Chicago", "Houston", 180, 0}
    };

    int choice, flightIndex;

    do
    {
        cout << "\nAirline Reservation System\n";
        cout << "1. Display Flight Details\n";
        cout << "2. Book a Seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nFlight Details\n";
                cout <<"----------------------------------" << endl;
                for (size_t i = 0; i < flights.size(); i++)
                {
                    cout << i + 1 << ". ";
                    displayFlightDetails(flights[i]);
                    cout << "------------------------------" << endl;
                }
                break;

            case 2:
                cout << "Enter the index of the flight to  book a seat: ";
                cin >> flightIndex;

                if (flightIndex >= 1 && flightIndex <= flights.size())
                {
                    bookSeat(flights[flightIndex - 1]);
                }
                else 
                {
                    cout << "Invaild flight index. " << endl;
                }
                break;

                case 3:
                    cout << "Exiting...." << endl;
                    cout << "Thank You for using Airline Reservation System 😊" << endl;
                    break;
                default:
                    cout << "Invalid choice.Please enter a number from 1 to 3." << endl;
        }
    } while (choice != 3);
    
    return 0;
}