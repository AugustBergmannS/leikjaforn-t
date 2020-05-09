#pragma once

class FlightBooking {
public:
  FlightBooking();
  FlightBooking(int id, int capacity, int reserved = 0);
  bool reserveSeats(int number_of_seats);
  bool cancelReservations(int number_of_seats);
  void printStatus();
  int getId();
private:
  int id;
  int capacity;
  int reserved;
  int getBookingPercentage(); 
};