#include "../header/yachtsystem.h"
#include <iostream>

using namespace Coruh::Yachtsystem;
using namespace std;
// Yachtsystem.cpp

// Yacht class methods
void Yacht::setName(const string &name) {
  this->name = name;
}

void Yacht::setLength(int length) {
  this->length = length;
}

void Yacht::displayInfo() const {
  cout << "Yacht Name: " << name << ", Length: " << length ;
}

// Harbor class methods
void Harbor::setLocation(const string &location) {
  this->location = location;
}

void Harbor::setCapacity(int capacity) {
  this->capacity = capacity;
}

void Harbor::displayInfo() const {
  cout << "Harbor Location: " << location << ", Capacity: " << capacity ;
}

// Reservation class methods
void Reservation::setCustomerName(const string &name) {
  this->customerName = name;
}

void Reservation::setReservationDate(const string &date) {
  this->reservationDate = date;
}

void Reservation::displayInfo() const {
  cout << "Reservation Name: " << customerName << ", Date: " << reservationDate ;
}
