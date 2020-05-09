#include "FlightBooking.h"
#include <iostream>

using namespace std;

FlightBooking::FlightBooking() {
  this->id = 0;
  this->capacity = 0;
  this->reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
  this->id = id;
  this->capacity = capacity > 0 ? capacity : 0;
  this->reserved = reserved > 0 ? reserved : 0;
  if(this->getBookingPercentage() > 105) {
    this->reserved = (105 * this->capacity) / 100;
  }
}

void FlightBooking::printStatus() {
  cout << "Flight " << this->id << ": " << this->reserved << "/" << this->capacity << "(" << this->getBookingPercentage() << "%) seats reserved." << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
  if(number_of_seats < 0 || 100 * (number_of_seats + this->reserved) > this->capacity * 105)
    return false;
  this->reserved += number_of_seats;
  return true;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
  if(number_of_seats < 0 || number_of_seats > this->reserved)
    return false;
  this->reserved -= number_of_seats;
  return true;
}

int FlightBooking::getBookingPercentage() {
  if(this->capacity > 0)
    return 100 * this->reserved / this->capacity;
  return 1;
}

int FlightBooking::getId() { return this->id; }