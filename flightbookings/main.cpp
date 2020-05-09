
#include <iostream>
#include <sstream>
#include <string>
#include "FlightBookings.h"

using namespace std;

int main() {
  FlightBookings bookings;
  int id, fjoldi;
  string input, skipun;

  do {
    cout << ">";
    getline(cin, input); //þetta er að taka inn heila línu
    stringstream ss;
    ss << input; //hér fer það in í eitthvað ss (veit ekki hvað er)
    ss >> skipun/*string*/ >> id/*int*/ >> fjoldi/*int*/; //það vill string, integer og annan integer
    if(skipun == "add") {
      if(bookings.addReservation(id, fjoldi) == false)
        cout << "Fann ekki flug með id " << id << endl;
    } else if(skipun == "cancel") {
        // Bæta við villuprófunum
        bookings.cancelReservation(id, fjoldi);
    } else if(skipun == "print") {
        bookings.printBooking(id);
    } else if(skipun == "create") {
        // Bæta við villuprófunum
        bookings.createFlight(id, fjoldi);
    } else if(skipun == "delete") {
        // Bæta við villuprófunum
        bookings.deleteFlight(id);
    } else if(skipun == "list") {
        bookings.printAll();
    }
  } while(skipun != "quit");
  return 0;
}