#pragma once // FlightBookings.h

#include "FlightBooking.h"

class FlightBookings {
    private:
        FlightBooking* bookings;
        int size_of_array;
        int getIndexOfId(int id);
    public:
        FlightBookings();
        FlightBookings(int init_size);
        bool createFlight(int id, int nbr_of_seats);
        bool deleteFlight(int id);
        bool addReservation(int id, int nbr_of_seats);
        bool cancelReservation(int id, int nbr_of_seats);
        void printBooking(int id);
        void printAll();
        ~FlightBookings();
};
