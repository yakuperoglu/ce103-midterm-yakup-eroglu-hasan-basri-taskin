#include "../header/yachtsystem.h"
#include <iostream>

using namespace Coruh::Yachtsystem;
using namespace std;
// Yachtsystem.cpp

// Yacht class methods
void Yacht::setName(const string &name) {
  this->name = name; //The value used to determine the name of the yacht object
}

void Yacht::setLength(int length) {
  this->length = length; //The value used to determine the length of the yacht object
}

void Yacht::displayInfo() const {
  cout << "Yacht Name: " << name << ", Length: " << length; //Displays the name and length values ​​of the Yacht object
}

// Harbor class methods
void Harbor::setLocation(const string &location) {
  this->location = location; //The value that determines the location of the Harbor object
}

void Harbor::setCapacity(int capacity) {
  this->capacity = capacity; //The value that determines the capacity of the Harbor object
}

void Harbor::displayInfo() const {
  cout << "Harbor Location: " << location << ", Capacity: " << capacity; //Displays the location and capacity values of the Harbor object
}

// Reservation class methods
void Reservation::setCustomerName(const string &name) {
  this->customerName = name; //The value used to determine the name of the customer
}

void Reservation::setReservationDate(const string &date) {
  this->reservationDate = date; //The value used to determine the date of the reservation
}

void Reservation::displayInfo() const {
  cout << "Reservation Name: " << customerName << ", Date: " << reservationDate; //Displays the customerName and reservarionDate
}
