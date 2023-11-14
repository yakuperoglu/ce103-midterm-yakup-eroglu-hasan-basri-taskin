/**
 * @file yachtsystem.h
 *
 * @brief Provides functions for math. utilities
 */

#ifndef YACHTSYSTEM_H
#define YACHTSYSTEM_H

#include "../../utility/header/commonTypes.h"
using namespace std;

namespace Coruh {
namespace Yachtsystem {
struct SeaVehicle {
  void setName(const string &name);  // Set the name of the yacht
  void setLength(int length);         // Set the length of the yacht
  void setMaintanceStatus(string &input);         // Set the maintance status of yacht
  void setOwner(string &name);         // Set the length of the yacht
  //We setted const this function because this function just read our variables. It cannot be changed with this function.
  void displayInfo() const;              // Display yacht information
  void displayExtendedInfo() const;              // Display yacht information


 private:
  bool maintanceStatus;
  string name;
  int length;
  string owner;
};

struct Harbor {
  void setLocation(const string &location); // Set the location of the harbor
  void setCapacity(int capacity);              // Set the capacity of the harbor
  //We setted const this function because this function just read our variables. It cannot be changed with this function.
  void displayInfo() const;                     // Display harbor information

 private:
  string location;
  int capacity;
};

struct Reservation {
  void setCustomerName(const string &name);  // Set the customer's name
  void setReservationDate(const string &date); // Set the reservation date
  //We setted const this function because this function just read our variables. It cannot be changed with this function.
  void displayInfo() const;                         // Display reservation information


 private:
  string customerName;
  string reservationDate;
};
}
}

#endif // YACHTSYSTEM_H
