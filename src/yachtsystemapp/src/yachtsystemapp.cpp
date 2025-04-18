// Standard Libraries
#include <iostream>
#include <sstream>
//For dynamic arrays
#include <vector>
//#include "../../seaVehicleystem/header/seaVehicleystem.h"  Added library reference to consoleapp so we dont need to define path.
#include "yachtsystem.h"  // Adjust this include path based on your project structure
#include <cstdlib> // For system("clear") function on Linux

using namespace Coruh::Yachtsystem;
using  namespace std;

//Define all seaVehicle to global.
//If we want to store seaVehicle in an array we must define vector.We can also say vectors, dynamic arrays.
vector<SeaVehicle> seaVehicle;

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
    cout << "Invalid input. Please enter a number.\n";
    return false;
  }

  return true;
}

void addSeaVehicle() {
  string name, lengthInput, ownerName, maintanceStatus;
  int length;
  clearScreen();

  while (true) {
    cout << "Enter Sea Vehicle Name (or type 'exit' to cancel): ";
    getline(cin, name);

    if (name == "exit") {
      cout << "Sea Vehicle addition cancelled." << endl;
      return; // Abort the proceess and exit function.
    }

    if (name.empty()) {
      cout << "Please enter valid yacht name\n\n";
    } else {
      break;
    }
  }

  while (true) {
    cout << "Enter Sea Vehicle Length (or type 'exit' to cancel): ";
    getline(cin, lengthInput);

    if (lengthInput == "exit") {
      cout << "Sea Vehicle addition cancelled." << endl;
      return; // Abort the proceess and exit function.
    }

    //Check the length must be higher than 0 or must be integer.
    if (tryAppendStringToInteger(lengthInput, length) && length > 0) {
      break; // The �nput value is correct so contine the function
    } else {
      if (length < 0)
        cout << "Invalid input. Please enter a positive number." << endl;
    }
  }

  while (true) {
    cout << "Enter Sea ehicle owner name (or type 'exit' to cancel): ";
    getline(cin, ownerName);

    if (ownerName == "exit") {
      cout << "Sea Vehicle addition cancelled." << endl;
      return; // Abort the proceess and exit function.
    }

    if (ownerName.empty()) {
      cout << "Please enter valid yacht owner name.\n\n";
    } else {
      break;
    }
  }

  while (true) {
    cout << "Enter Sea Vehicle maintance status. if okey type 'yes' if not type 'no' (or type 'exit' to cancel): ";
    getline(cin, maintanceStatus);

    if (maintanceStatus == "exit") {
      cout << "Sea Vehicle addition cancelled." << endl;
      return; // Abort the proceess and exit function.
    }

    if (maintanceStatus.empty()) {
      cout << "Please enter valid yacht status.\n\n";
    } else {
      if (maintanceStatus == "yes" || maintanceStatus == "no") {
        break;
      } else {
        cout << "Please just type 'yes' or 'no'\n";
      }
    }
  }

  // Create a yacht and then add the list
  SeaVehicle newSeaVehicle;
  newSeaVehicle.setName(name);
  newSeaVehicle.setLength(length);
  newSeaVehicle.setOwner(ownerName);
  newSeaVehicle.setMaintanceStatus(maintanceStatus);
  //push_back is a function of vectors. This function add the new yacht to list.
  seaVehicle.push_back(newSeaVehicle);
  cout << "\nSea Vehicle added.\n";
  printSeparator();
}

void listSeaVehicles() {
  if (seaVehicle.empty()) {
    cout << "There is no yacht.\n" << endl;
  } else {
    cout << "Listing all seaVehicle:\n" << endl;
    int index = 1;

    for (const SeaVehicle yacht : seaVehicle) {
      cout << index++ << ". ";
      yacht.displayInfo();
      cout << endl;
    }
  }
}

void listSeaVehiclesAdminPanel() {
  clearScreen();
  listSeaVehicles();

  while (true) {
    string input;
    cout << "Type something to return to yacht operations: ";
    getline(cin, input);
    return;
  }
}

void removeSeaVehicle() {
  clearScreen();

  if (seaVehicle.empty()) {
    cout << "There are no seaVehicle to remove.\n" << endl;

    while (seaVehicle.empty() == true) {
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
    listSeaVehicles();
    cout << "Enter the number of the yacht to remove (or type 'exit' to cancel): ";
    string input;
    getline(cin, input);

    if (input == "exit") {
      cout << "Sea Vehicle removal cancelled." << endl;
      break; // Cancel the proccess and exit the function.
    }

    int choice;

    //Check if input string or lower than 0 or higher than yacht size enter new value to user.
    if (tryAppendStringToInteger(input, choice) && choice > 0 && choice <= static_cast<int>(seaVehicle.size())) {
      //erase is a function of vectors. It deletes by index.
      seaVehicle.erase(seaVehicle.begin() + choice - 1); // Index adjustment since vector index starts from 0
      cout << "Sea Vehicle removed." << endl;
      return; // Delete yacht and exit the function
    } else {
      clearScreen();
      cout << "Invalid input. Please try again." << endl;
    }
  }
}

void updateSeaVehicle() {
  clearScreen();

  if (seaVehicle.empty()) {
    cout << "There are no seaVehicle to update.\n" << endl;

    while (true) {
      string input;
      cout << "Type something to return to yacht operations: ";
      getline(cin, input);
      return;
    }
  }

  int yachtIndex = 1;

  while (true) {
    listSeaVehicles();
    cout << "\n";
    cout << "Enter the number of the yacht to update (or type 'exit' to cancel): ";
    string input;
    getline(cin, input);

    if (input == "exit") {
      cout << "Sea Vehicle update cancelled." << endl;
      return;
    }

    clearScreen();

    if (tryAppendStringToInteger(input, yachtIndex) && yachtIndex > 0 && yachtIndex <= static_cast<int>(seaVehicle.size())) {
      yachtIndex--; // Adjust for 0-based index
      break;
    } else {
      cout << endl;

      if (yachtIndex <= 0) {
        cout << "Please enter a number higher than 0.\n" << endl;
      }

      if (yachtIndex > static_cast<int>(seaVehicle.size())) {
        cout << "Please enter a number lower than " << static_cast<int>(seaVehicle.size()) << endl;
      }
    }
  }

  string updateChoice;

  while (true) {
    cout << "1. Update Name\n2. Update Length\n3. Update Owner Name\n4. Update Maintance Status \n5. Update All of them\nEnter your choice  (or type 'exit' to cancel): ";
    getline(cin, updateChoice);

    if (updateChoice == "exit") {
      cout << "Sea Vehicle update cancelled." << endl;
      return;
    }

    if (updateChoice == "1" || updateChoice == "2" || updateChoice == "3" || updateChoice == "4" || updateChoice == "5") {
      break;
    } else {
      clearScreen();
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  if (updateChoice == "1" || updateChoice == "5") {
    string newName;
    cout << "Enter new name: ";
    getline(cin, newName);
    seaVehicle[yachtIndex].setName(newName); // Update name using setName method
  }

  if (updateChoice == "2" || updateChoice == "5") {
    while (true) {
      cout << "Enter new length: ";
      string inputLeng;
      getline(cin, inputLeng);
      int newLength;

      if (tryAppendStringToInteger(inputLeng, newLength) && newLength > 0) {
        seaVehicle[yachtIndex].setLength(newLength); // Update length directly
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
    seaVehicle[yachtIndex].setOwner(newOwnerName); // Update owner name using setOwner method
  }

  if (updateChoice == "4" || updateChoice == "5") {
    string newStatus;
    cout << "Enter new status: ";
    getline(cin, newStatus);
    seaVehicle[yachtIndex].setMaintanceStatus(newStatus); // Update status using setMaintanceStatus method
  }

  cout << "Sea Vehicle updated successfully." << endl;
}


void yachtOperations() {
  string input;
  int choice;
  //As long as this variable is true, yacht menu runs always
  bool yachtRunning = true;

  while (yachtRunning) {
    clearScreen();
    cout << "Sea Vehicle Operations:\n";
    cout << "1. Add Sea Vehicle\n";
    cout << "2. Remove Sea Vehicle\n";
    cout << "3. Update Sea Vehicle\n";
    cout << "4. List Sea Vehicles\n";
    cout << "5. Return to Admin Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        addSeaVehicle();
        break;

      case 2:
        removeSeaVehicle();
        break;

      case 3:
        updateSeaVehicle();
        break;

      case 4:
        listSeaVehiclesAdminPanel();
        break;

      case 5:
        yachtRunning = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 5.\n";
    }
  }
}

void dockingAreas() {
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
    cout << "Type something to return to Harbor Services: ";
    getline(cin, input);
    return;
  }
}

void maintenanceInformation() {
  clearScreen();
  cout << "Maintenance Information...\n";
  printSeparator();
  cout << " yacht_name " << " yacht_condition " << "Maintance Status " << endl;
  printSeparator();

  for (const SeaVehicle yacht : seaVehicle) {
    yacht.displayExtendedInfo();
  }

  while (true) {
    string input;
    cout << "Type something to return to Harbor Services: ";
    getline(cin, input);
    return;
  }
}

void refuelingStations() {
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
    cout << "Type something to return to Harbor Services: ";
    getline(cin, input);
    return;
  }
}

void maintenanceCrewDetails() {
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
    cout << "Type something to return to Harbor Services: ";
    getline(cin, input);
    return;
  }
}

void harborServices() {
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
        dockingAreas();
        break;

      case 2:
        maintenanceInformation();
        break;

      case 3:
        refuelingStations();
        break;

      case 4:
        maintenanceCrewDetails();
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

void reservationServices() {
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
void adminOperations() {
  string input;
  int choice;
  bool adminRunning = true;

  while (adminRunning) {
    clearScreen();
    cout << "Admin Operations:\n";
    cout << "1. Sea Vehicle and Boat Operations\n";
    cout << "2. Harbor Services\n";
    cout << "3. Return to Main Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        yachtOperations();
        break;

      case 2:
        harborServices();
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
void userOperations() {
  string input;
  int choice;
  bool userRunning = true;

  while (userRunning) {
    clearScreen();
    cout << "User Operations:\n";
    cout << "1. Reservation Services\n";
    cout << "2. Return to Main Menu\n";
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        reservationServices();
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
    cout << "Marina and Sea Vehicle Management System\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "3. Exit\n";
    cout << "Please enter your choice (1-3): ";
    getline(cin, input);

    if (!tryAppendStringToInteger(input, choice))
      continue;

    switch (choice) {
      case 1:
        adminOperations();
        break;

      case 2:
        userOperations();
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
