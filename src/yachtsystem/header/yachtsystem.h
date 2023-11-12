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
  Yacht(const string &name, int length);  // Constructor
  void displayInfo() const;  // Show yacht info

 private:
  string name;
  int length;
};

class Harbor {
 public:
  Harbor(const string &location, int capacity);  // Constructor
  void displayInfo() const;  // Show harbor info

 private:
  string location;
  int capacity;
};

class Reservation {
 public:
  Reservation(const string &customerName, const string &date);  // Constructor
  void displayInfo() const;  // show reservation infos

 private:
  string customerName;
  string reservationDate;
};
}
}

#endif // YACHTSYSTEM_H
