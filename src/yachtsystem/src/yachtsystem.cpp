#include "../header/yachtsystem.h"
#include <iostream>

using namespace Coruh::Yachtsystem;
using namespace std;
// Yachtsystem.cpp

// SeaVehicle class methods
void SeaVehicle::setName(const string& name) {
	this->name = name; //The value used to determine the name of the yacht
}

void SeaVehicle::setLength(int length) {
	this->length = length; //The value used to determine the length of the yacht
}

void SeaVehicle::displayInfo() const {
	cout << "SeaVehicle Name: " << name << ", Length: " << length << ", SeaVehicle owner: " << owner; //Displays the name, length and yacht owner values ​​of the SeaVehicle
}

void SeaVehicle::displayExtendedInfo() const {
	cout << name  << " | " << length << " | " << owner << " | " << (maintanceStatus == true ? "Maintance necessary" : "Not necessary") << endl; //Displays the name, length, yachtOwner and maintanceStauts values ​​of the SeaVehicle
}

void SeaVehicle::setMaintanceStatus(string& input) {
	this->maintanceStatus = (input == "yes" ? true : false);  //The value used to determine the status of the yacht
}

void SeaVehicle::setOwner(string& ownerName) {
	this->owner = ownerName;//The value used to determine the owener of the yacht
}

// Harbor class methods
void Harbor::setLocation(const string& location) {
	this->location = location; //The value that determines the location of the Harbor
}

void Harbor::setCapacity(int capacity) {
	this->capacity = capacity; //The value that determines the capacity of the Harbor
}

void Harbor::displayInfo() const {
	cout << "Harbor Location: " << location << ", Capacity: " << capacity; //Displays the location and capacity values of the Harbor
}

// Reservation class methods
void Reservation::setCustomerName(const string& name) {
	this->customerName = name; //The value used to determine the name of the customer
}

void Reservation::setReservationDate(const string& date) {
	this->reservationDate = date; //The value used to determine the date of the reservation
}

void Reservation::displayInfo() const {
	cout << "Reservation Name: " << customerName << ", Date: " << reservationDate; //Displays the customerName and reservarionDate
}
