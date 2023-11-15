#include "../header/yachtsystem.h"
#include <iostream>

using namespace Coruh::Yachtsystem;

// SeaVehicle structs methods
bool SeaVehicle::setName(const string& name) {
	//name couldnt empty
	if (name.empty())
		return false;

	this->name = name;
	return true;
}

bool SeaVehicle::setLength(int length) {
	//length couldn't lower or equal to 0
	if (length <= 0)
		return false;

	this->length = length;
	return true;
}

bool SeaVehicle::setMaintanceStatus(const string& input) {
	//input must be just yes or no, other values is incorrect.
	if (input != "yes" && input != "no")
		return false;

	this->maintanceStatus = (input == "yes");
	return true;
}

bool SeaVehicle::setOwner(const string& ownerName) {
	//owner value cant be null.
	if (ownerName.empty())
		return false;

	this->owner = ownerName;
	return true;
}

int SeaVehicle::displayInfo() const {
	//its just show the info 
	cout << "SeaVehicle Name: " << name << ", Length: " << length << ", SeaVehicle owner: " << owner << endl;
	return 0;
}

int SeaVehicle::displayExtendedInfo() const {
	//its just show the info 
	cout << name << " | " << length << " | " << owner << " | " << (maintanceStatus ? "Maintance necessary" : "Not necessary") << endl;
	return 0;
}

// Reservation Struct methods
bool Reservation::setCustomerName(const string& name) {
	//customer name cant be empty
	if (name.empty())
		return false;

	this->customerName = name;
	return true;
}

int Reservation::displayInfo() const {
	//its just show the info 
	cout << "Reservation Name: " << customerName << ", Date: " << reservationDate << endl;
	return 0;
}
