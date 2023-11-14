// Standard Libraries
#include <iostream>
#include <sstream>
//For dynamic arrays
#include <vector>
//#include "../../yachtsystem/header/yachtsystem.h"  Added library reference to consoleapp so we dont need to define path.
#include "yachtsystem.h"  // Adjust this include path based on your project structure
#include <cstdlib> // For system("clear") function on Linux

using namespace Coruh::Yachtsystem;
using  namespace std;

//Define all yachts to global.
//If we want to store yachts in an array we must define vector.We can also say vectors, dynamic arrays.
vector<Yacht> yachts;

// Created a function for separator
void printSeparator() {
  cout << "------------------------------------------------------------------\n";
}
void clearScreen() {
  // Clear the screen based on the operating system
#ifdef _WIN32
  system("cls"); // For Windows
#else
  system("clear"); // For Linux
#endif
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

bool tryAppendStringToInteger(const string &input, int &choice) {
  if (!convertStringToInt(input, choice)) {
    cout << "Invalid input. Please enter a number.";
    return false;
  }

  return true;
}

void addYacht() {
  string name, lengthInput, ownerName, maintanceStatus;
  int length;
  clearScreen();
  cout << "Enter Yacht Name (or type 'exit' to cancel): ";
  getline(cin, name);

  if (name == "exit") {
    cout << "Yacht addition cancelled." << endl;
    return; // Abort the proceess and exit function.
  }

  while (true) {
    cout << "Enter Yacht Length (or type 'exit' to cancel): ";
    getline(cin, lengthInput);

    if (lengthInput == "exit") {
      cout << "Yacht addition cancelled." << endl;
      return; // Abort the proceess and exit function.
    }

    //Check the length must be higher than 0 or must be integer.
    if (tryAppendStringToInteger(lengthInput, length) && length > 0) {
      break; // The ýnput value is correct so contine the function
    } else {
      if (length < 0)
        cout << "Invalid input. Please enter a positive number." << endl;
    }
  }

  cout << "Enter Yacht owner name (or type 'exit' to cancel): ";
  getline(cin, ownerName);

  if (ownerName == "exit") {
    cout << "Yacht addition cancelled." << endl;
    return; // Abort the proceess and exit function.
  }

  cout << "Enter Yacht maintance status. if okey type 'yes' if not type 'no' (or type 'exit' to cancel): ";
  getline(cin, maintanceStatus);

  if (maintanceStatus == "exit") {
    cout << "Yacht addition cancelled." << endl;
    return; // Abort the proceess and exit function.
  }

  // Create a yacht and then add the list
  Yacht newYacht;
  newYacht.setName(name);
  newYacht.setLength(length);
  newYacht.setOwner(ownerName);
  newYacht.setMaintanceStatus(maintanceStatus);
  //push_back is a function of vectors. This function add the new yacht to list.
  yachts.push_back(newYacht);
  cout << "\nYacht added.\n";
  printSeparator();
}

void listYachts() {
  if (yachts.empty()) {
    cout << "There is no yacht.\n" << endl;
  } else {
    cout << "Listing all yachts:\n" << endl;
    int index = 1;

    for (const Yacht yacht : yachts) {
      cout << index++ << ". ";
      yacht.displayInfo();
      cout << endl;
    }
  }
}

void listYachtsAdminPanel() {
  clearScreen();
  listYachts();

  while (true) {
    string input;
    cout << "Type 'exit' to return to yacht operations: ";
    getline(cin, input);

    if (input == "exit") {
      cout << "Returning to yacht operations...\n";
      return;
    }
  }
}

void removeYacht() {
  clearScreen();

  if (yachts.empty()) {
    cout << "There are no yachts to remove.\n" << endl;

    while (yachts.empty() == true) {
      string input;
      cout << "Type 'exit' to return to yacht operations: ";
      getline(cin, input);

      if (input == "exit") {
        cout << "Returning to yacht operations...\n";
        return;
      }
    }
  }

  while (true) {
    listYachts();
    cout << "Enter the number of the yacht to remove (or type 'exit' to cancel): ";
    string input;
    getline(cin, input);

    if (input == "exit") {
      cout << "Yacht removal cancelled." << endl;
      break; // Cancel the proccess and exit the function.
    }

    int choice;

    //Check if input string or lower than 0 or higher than yacht size enter new value to user.
    if (tryAppendStringToInteger(input, choice) && choice > 0 && choice <= static_cast<int>(yachts.size())) {
      //erase is a function of vectors. It deletes by index.
      yachts.erase(yachts.begin() + choice - 1); // Index adjustment since vector index starts from 0
      cout << "Yacht removed." << endl;
      return; // Delete yacht and exit the function
    } else {
      clearScreen();
      cout << "Invalid input. Please try again." << endl;
    }
  }
}

void updateYacht() {
  clearScreen();

  if (yachts.empty()) {
    cout << "There are no yachts to update.\n" << endl;

    while (true) {
      string input;
      cout << "Type 'exit' to return to yacht operations: ";
      getline(cin, input);

      if (input == "exit") {
        cout << "Returning to yacht operations...\n";
        return;
      }
    }
  }

  int yachtIndex = 1;

  while (true) {
    listYachts();
    cout << "\n";
    cout << "Enter the number of the yacht to update (or type 'exit' to cancel): ";
    string input;
    getline(cin, input);

    if (input == "exit") {
      cout << "Yacht update cancelled." << endl;
      return;
    }

    clearScreen();

    if (tryAppendStringToInteger(input, yachtIndex) && yachtIndex > 0 && yachtIndex <= static_cast<int>(yachts.size())) {
      yachtIndex--; // Adjust for 0-based index
      break;
    } else {
      cout << endl;

      if (yachtIndex <= 0) {
        cout << "Please enter a number higher than 0.\n" << endl;
      }

      if (yachtIndex > static_cast<int>(yachts.size())) {
        cout << "Please enter a number lower than " << static_cast<int>(yachts.size()) << endl;
      }
    }
  }

  string updateChoice;

  while (true) {
    cout << "1. Update Name\n2. Update Length\n 3. Update Owner Name\n 4. Update Maintance Status \n 5. Update All of them\nEnter your choice  (or type 'exit' to cancel): ";
    getline(cin, updateChoice);

    if (updateChoice == "exit") {
      cout << "Yacht update cancelled." << endl;
      return;
    }

    if (updateChoice == "1" || updateChoice == "2" || updateChoice == "3" || updateChoice == "4" || updateChoice == "5") {
      break;
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  if (updateChoice == "1" || updateChoice == "5") {
    string newName;
    cout << "Enter new name: ";
    getline(cin, newName);
    yachts[yachtIndex].setName(newName); // Update name using setName method
  }

  if (updateChoice == "2" || updateChoice == "5") {
    while (true) {
      cout << "Enter new length: ";
      string inputLeng;
      getline(cin, inputLeng);
      int newLength;

      if (tryAppendStringToInteger(inputLeng, newLength) && newLength > 0) {
        yachts[yachtIndex].setLength(newLength); // Update length directly
        break;
      } else {
        cout << "Invalid length. Please try again." << endl;
      }
    }
  }

  if (updateChoice == "3" || updateChoice == "5") {
    string newOwnerName;
    cout << "Enter new owner name: ";
    getline(cin, newOwnerName);
    yachts[yachtIndex].setOwner(newOwnerName); // Update owner name using setOwner method
  }

  if (updateChoice == "4" || updateChoice == "5") {
    string newStatus;
    cout << "Enter new name: ";
    getline(cin, newStatus);
    yachts[yachtIndex].setMaintanceStatus(newStatus); // Update status using setMaintanceStatus method
  }

  cout << "Yacht updated successfully." << endl;
}


void handleYachtOperations() {
  string input;
  int choice;
  //As long as this variable is true, yacht menu runs always
  bool yachtRunning = true;

  while (yachtRunning) {
    clearScreen();
    cout << "Yacht Operations:\n";
    cout << "1. Add Yacht\n";
    cout << "2. Remove Yacht\n";
    cout << "3. Update Yacht\n";
    cout << "4. List Yachts\n";
    cout << "5. Return to Admin Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        addYacht();
        break;

      case 2:
        removeYacht();
        break;

      case 3:
        updateYacht();
        break;

      case 4:
        listYachtsAdminPanel();
        break;

      case 5:
        yachtRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 5.\n";
    }
  }
}

void handleDockingAreas() {
  clearScreen();
  cout << "Docking Areas Information...\n";
  printSeparator();
  cout << "Azkar Harbor (available)\n";
  cout << "Feudal Harbor (available)\n";
  cout << "Bighthouse Harbor (unavailable)\n";
  cout << "Bigboy Harbor (available)\n";
  printSeparator();

  while (true) {
    string input;
    cout << "Type 'exit' to return to Harbor Services: ";
    getline(cin, input);

    if (input == "exit") {
      cout << "Returning to Harbor Services...\n";
      return;
    }
  }
}

void handleMaintenanceInformation() {
  clearScreen();
  cout << "Maintenance Information...\n";
  printSeparator();
  cout << " yacht_name " << " yacht_condition " << "Last_maintenance " << " Next_maintenance\n";
  printSeparator();

  while (true) {
    string input;
    cout << "Type 'exit' to return to Harbor Services: ";
    getline(cin, input);

    if (input == "exit") {
      cout << "Returning to Harbor Services...\n";
      return;
    }
  }
}

void handleRefuelingStations() {
  clearScreen();
  cout << "Refueling Stations Information...\n";
  printSeparator();
  cout << "Azkar Fuel Station (available)\n";
  cout << "Fuedal Fuel Station (available)\n";
  cout << "Bighthouse Fuel Station (unavailable)\n";
  cout << "Bigboy Fuel Station (unavailable)\n";
  cout << "Dunkin Po Fuel Station (available)\n";
  printSeparator();

  while (true) {
    string input;
    cout << "Type 'exit' to return to Harbor Services: ";
    getline(cin, input);

    if (input == "exit") {
      cout << "Returning to Harbor Services...\n";
      return;
    }
  }
}

void handleMaintenanceCrewDetails() {
  clearScreen();
  cout << "Maintenance Crew Details...\n";
  printSeparator();
  cout << "personal name " << " personal surname\n\n";
  cout << " alihan  " << "       tartar\n";
  cout << " mahmut  " << "       tuncer\n";
  cout << " erol    " << "          tas\n";
  cout << " enes    " << "          koy\n";
  cout << " dilara  " << "        batan\n";
  cout << " volkan  " << "         ucar\n";
  printSeparator();

  while (true) {
    string input;
    cout << "Type 'exit' to return to Harbor Services: ";
    getline(cin, input);

    if (input == "exit") {
      cout << "Returning to Harbor Services...\n";
      return;
    }
  }
}

void handleHarborServices() {
  string input;
  int choice;
  bool HarborRunning = true;

  while (HarborRunning) {
    clearScreen();
    cout << "Harbor Services...\n";
    cout << "1) Docking Areas\n";
    cout << "2) Maintenance Information\n";
    cout << "3) Refueling Stations\n";
    cout << "4) Maintenance Crew Details\n";
    cout << "5) Return to Admin Menu\n\n";
    cout << "Please enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
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
void yachtReservation() {
}
void boatReservation() {
}
void paymentMethods() {
}

void handleReservationServices() {
  string input;
  int choice;
  bool ReservationRunning = true;

  while (ReservationRunning) {
    clearScreen();
    cout << "Reservation Services...\n";
    cout << "1) yacht reservation \n";
    cout << "2) boat reservation\n";
    cout << "3) payment methods\n";
    cout << "4) Return to Admin Menu\n\n";
    cout << "Please enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        yachtReservation();
        break;

      case 2:
        boatReservation();
        break;

      case 3:
        paymentMethods();
        break;

      case 4:
        ReservationRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }
  }
}

// This function for admin operations.
void handleAdminOperations() {
  string input;
  int choice;
  bool adminRunning = true;

  while (adminRunning) {
    clearScreen();
    cout << "Admin Operations:\n";
    cout << "1. Yacht and Boat Operations\n";
    cout << "2. Harbor Services\n";
    cout << "3. Return to Main Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        handleYachtOperations();
        break;

      case 2:
        handleHarborServices();
        break;

      case 3:
        adminRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }
  }
}

//This function for user Operations
void handleUserOperations() {
  string input;
  int choice;
  bool userRunning = true;

  while (userRunning) {
    clearScreen();
    cout << "User Operations:\n";
    cout << "1. reservationServices\n";
    cout << "2. Return to Main Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        handleReservationServices();
        break;

      case 2:
        userRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }
  }
}

void showMainMenu() {
  string input;
  int choice;
  bool mainRunning = true;

  while (mainRunning) {
    clearScreen();
    cout << "Marina and Yacht Management System\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "3. Exit\n";
    cout << "Please enter your choice (1-3): ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
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
