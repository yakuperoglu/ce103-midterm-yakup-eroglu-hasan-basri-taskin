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
#include "yachtsystem.h"  // Adjust this include path based on your project structure

using namespace Coruh::Yachtsystem;
using  namespace std;

void handleYachtOperations() {
  cout << "Yacht Operations...\n";
}

void handleHarborServices() {
  cout << "Harbor Services...\n";
  // Information about docking spaces, fuel stations, maintenance crew bla bla.
}

void handleReservationServices() {
  cout << "Reservation Services...\n";
  // Booking system, payment processing, applying discounts here.
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
// Created a function for separator
void printSeparator() {
  std::cout << "------------------------------------------------------------------\n";
}

// This function for admin operations.
void handleAdminOperations() {
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
    cin >> choice;

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
  printSeparator();
  cout << "Marina and Yacht Management System\n";
  cout << "1. Admin\n";
  cout << "2. User\n";
  cout << "3. Exit\n";
  cout << "Please enter your choice (1-3): \n";
}

int main() {
  string input;
  int choice;
  bool mainRunning = true;

  while (mainRunning) {
    showMainMenu();
    getline(cin, input);

    if (!convertStringToInt(input, choice)) {
      cout << "Invalid input. Please enter a number.\n";
      continue;
    }

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

  return 0;
}
