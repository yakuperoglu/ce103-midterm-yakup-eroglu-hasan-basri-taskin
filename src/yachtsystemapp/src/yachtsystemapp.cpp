/**
 * @file yachtsystemapp.cpp
 * @brief A simple program to demonstrate the usage of the yachtsystem model class.
 *
 * This program process infix notations and calculate operations
 *
 */

// Standard Libraries
#include <iostream>
#include <sstream>
//#include "../../yachtsystem/header/yachtsystem.h"  Added library reference to consoleapp so we dont need to define path.
#include <vector>

#include "yachtsystem.h"  // Adjust this include path based on your project structure

using namespace Coruh::Yachtsystem;
using  namespace std;

// Created a function for separator
void printSeparator() {
  cout << "------------------------------------------------------------------\n";
}

//This function checks is string not an integer value
bool convertStringToInt(const string &str, int &number) {
  //It's a class for convert a string value to correct type (int, char,double,string)
  istringstream iss(str);
  //tries to append
  iss >> number;

  if (iss.fail()) {
    return false; // Conversion failed
  }

  return true; // Conversion successful
}

bool tryAppendIntegerToString(const string &input, int &choice) {
  if (!convertStringToInt(input, choice)) {
    cout << "Invalid input. Please enter a number.\n";
    return false;
  }

  return true;
}
void addYacht(vector<Yacht> &yachts) {
  //AddFunc
}

void removeYacht(vector<Yacht> &yachts) {
  //RemoveFunc
}

void listYachts(const vector<Yacht> &yachts) {
  //ListFunc
}
void handleYachtOperations() {
  string input;
  //If we want to store yachts in an array we must define vector. We can also say vectors, dynamic arrays.
  vector<Yacht> yachts;
  int choice;
  //As long as this variable is true, yacht menu runs always
  bool yachtRunning = true;

  while (yachtRunning) {
    cout << "\nYacht Operations:\n";
    printSeparator();
    cout << "1. Add Yacht\n";
    cout << "2. Remove Yacht\n";
    cout << "3. List Yachts\n";
    cout << "4. Return to Admin Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendIntegerToString(input, choice))
      continue;

    switch (choice) {
      case 1:
        addYacht(yachts);
        break;

      case 2:
        removeYacht(yachts);
        break;

      case 3:
        listYachts(yachts);
        break;

      case 4:
        yachtRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }
  }
}
void handleDockingAreas() {
  cout << "\n";
  cout << "Docking Areas Information...\n";
  printSeparator();
  cout << "azkar harbor (available)\n";
  cout << "feudal harbor (available)\n";
  cout << "lighthouse harbor (unavailable)\n";
  cout << "bigboy harbor (available)\n";
}

void handleMaintenanceInformation() {
  cout << "Maintenance Information...\n";
  // Buraya Maintenance ile ilgili kodlarý ekleyin
}

void handleRefuelingStations() {
  cout << "Refueling Stations Information...\n";
  // Buraya Refueling Stations ile ilgili kodlarý ekleyin
}

void handleMaintenanceCrewDetails() {
  cout << "Maintenance Crew Details...\n";
  // Buraya Maintenance Crew ile ilgili kodlarý ekleyin
}

void handleHarborServices() {
  string input;
  int choice;
  bool HarborRunning = true;

  while (HarborRunning) {
    printSeparator();
    cout << "Harbor Services...\n";
    cout << "1) Docking Areas\n";
    cout << "2) Maintenance Information\n";
    cout << "3) Refueling Stations\n";
    cout << "4) Maintenance Crew Details\n";
    cout << "5) Return to Admin Menu\n";
    cout << "Please enter your choice: ";
    getline(cin, input);

    if (!tryAppendIntegerToString(input, choice))
      continue;

    switch (choice) {
      case 1:
        handleDockingAreas();
        break;

      case 2:
        handleMaintenanceInformation();
        break;

      case 3:
        handleRefuelingStations();
        break;

      case 4:
        handleMaintenanceCrewDetails();
        break;

      case 5:
        HarborRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }
  }
}

void handleReservationServices() {
  cout << "Reservation Services...\n";
  // Booking system, payment processing, applying discounts here.
}

// This function for admin operations.
void handleAdminOperations() {
  string input;
  int choice;
  bool adminRunning = true;

  while (adminRunning) {
    printSeparator();
    cout << "Admin Operations:\n";
    cout << "1. Yacht and Boat Operations\n";
    cout << "2. Harbor Services\n";
    cout << "3. Reservation Services\n";
    cout << "4. Return to Main Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendIntegerToString(input, choice))
      continue;

    switch (choice) {
      case 1:
        handleYachtOperations();
        break;

      case 2:
        handleHarborServices();
        break;

      case 3:
        handleReservationServices();
        break;

      case 4:
        adminRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }
  }
}

//This function for user Operations
void handleUserOperations() {
  cout << "User Operations...\n";
  // We will add user operations future
}

void showMainMenu() {
  string input;
  int choice;
  bool mainRunning = true;

  while (mainRunning) {
    printSeparator();
    cout << "Marina and Yacht Management System\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "3. Exit\n";
    cout << "Please enter your choice (1-3): \n";
    getline(cin, input);

    if (!tryAppendIntegerToString(input, choice))
      continue;

    switch (choice) {
      case 1:
        handleAdminOperations();
        break;

      case 2:
        handleUserOperations();
        break;

      case 3:
        cout << "Exiting the program. Thank you!\n";
        mainRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 3.\n";
    }
  }
}
int main() {
  showMainMenu();
  return 0;
}
