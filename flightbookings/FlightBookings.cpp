// FlightBookings.cpp



#include "FlightBookings.h"
//getindexofid er að ná í ákveðið id
int FlightBookings::getIndexOfId(int id) {
    for(int i = 0; i < this->size_of_array; i++){
        if(this->bookings[i].getId() == id){
            return i;
        }
    }
    //ef það kemur hingað þá var ekki fundið id-ið
    return -1;
}

FlightBookings::FlightBookings() {
    this->size_of_array = 5;//stærðin fyrir FlightBooking bókunina
    this->bookings = new FlightBooking[this->size_of_array]();
}

FlightBookings::FlightBookings(int init_size) {
    this->size_of_array = init_size;
    this->bookings = new FlightBooking[this->size_of_array]();
}

bool FlightBookings::createFlight(int id, int nbr_of_seats) {
    if(this->getIndexOfId(id) >= 0)
        return false;
        //þetta id er núþegar til
    int index = getIndexOfId(0);
    if(index != -1){
        this->bookings[index] = FlightBooking(id, nbr_of_seats);
        return true;
        //id-ið er laust
    }
    else//array-ið er fullt
    {
        FlightBooking* temp = new FlightBooking[this->size_of_array * 2];
        for(int i = 0; i < this->size_of_array; i++){
            temp[i] = this->bookings[i];

        }
                                                                    //personal note: pointers eru breytur sem geyma tölu
        delete [] bookings;
        //það er eitt pointer-inum bookings og síðan látið hann verða að temp
        this->bookings = temp;
        this->bookings[this->size_of_array] = FlightBooking(id, nbr_of_seats);
        return true;
    }
    //temp breytan 
    
}

bool FlightBookings::deleteFlight(int id) {
    int index = this->getIndexOfId(id);//hér er verið að fara yfir í getindexofid sem er hér að ofan
    if(index != -1){//ef það er ekki fundið id-ið þá mun það skila -1 og fer ekki inn hér
        this->bookings[index] = FlightBooking();
        //ef id finst þá skilar þetta true
        return true;
    }
    //ef id finst ekki þá skilar þetta false
    return false;
}

bool FlightBookings::addReservation(int id, int nbr_of_seats) {
    int index = this->getIndexOfId(id);
    if(index != -1)
        return this->bookings[index].reserveSeats(nbr_of_seats);
    return false;
}

bool FlightBookings::cancelReservation(int id, int nbr_of_seats) {
    int index = this->getIndexOfId(id);
    if(index != -1)
        return this->bookings[index].cancelReservations(nbr_of_seats);
    return false;
}

void FlightBookings::printBooking(int id) {//þetta á að skila bókuninni sem leitað er að
    int index = this->getIndexOfId(id);
    if(index != -1)
        this->bookings[index].printStatus();
}

void FlightBookings::printAll() {//þetta á að skila allar bókanirnar
    for (int i = 0; i < this->size_of_array; i++)
        if(this->bookings[i].getId() != 0)
            this->bookings[i].printStatus();
}

FlightBookings::~FlightBookings() {//þetta er deconstructer hann eyðir hlutum
    delete [] this->bookings; // veit ekki með þetta var ekki að fylgjast með nógu vel
}