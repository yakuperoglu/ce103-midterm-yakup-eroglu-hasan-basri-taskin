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
class Yacht {
 public:
  void setName(const string &name);  // Set the name of the yacht
  void setLength(int length);         // Set the length of the yacht
  void setOwner(string &name);         // Set the length of the yacht
  //We setted const this function because this function just read our variables. It cannot be changed with this function.
  void displayInfo() const;              // Display yacht information


 private:
  string name;
  int length;
  string owner;
};

class Harbor {
 public:
  void setLocation(const string &location); // Set the location of the harbor
  void setCapacity(int capacity);              // Set the capacity of the harbor
  //We setted const this function because this function just read our variables. It cannot be changed with this function.
  void displayInfo() const;                     // Display harbor information

 private:
  string location;
  int capacity;
};

class Reservation {
 public:
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
