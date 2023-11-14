// Standard Libraries
#include <iostream>
#include <sstream>
//For dynamic arrays
#include <vector>
//#include "../../yachtsystem/header/yachtsystem.h"  Added library reference to consoleapp so we dont need to define path.
#include "yachtsystem.h"  // Adjust this include path based on your project structure

using namespace Coruh::Yachtsystem;
using  namespace std;

//Define all yachts to global.
//If we want to store yachts in an array we must define vector.We can also say vectors, dynamic arrays.
vector<Yacht> yachts;

// Created a function for separator
void printSeparator() {
	cout << "------------------------------------------------------------------\n";
}

//This function checks is string not an integer value
bool convertStringToInt(const string& str, int& number) {
	//It's a class for convert a string value to correct type (int, char,double,string)
	istringstream iss(str);
	//tries to append
	iss >> number;

	if (iss.fail()) {
		return false; // Conversion failed
	}

	return true; // Conversion successful
}

bool tryAppendIntegerToString(const string& input, int& choice) {
	if (!convertStringToInt(input, choice)) {
		cout << "Invalid input. Please enter a number.\n";
		return false;
	}

	return true;
}

void addYacht() {
	string name, lengthInput;
	int length;
	cout << "\n";
	printSeparator();
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
		if (tryAppendIntegerToString(lengthInput, length) && length > 0) {
			break; // The ýnput value is correct so contine the function
		}
		else {
			if (length < 0)
				cout << "Invalid input. Please enter a positive number." << endl;
		}
	}

	// Create a yacht and then add the list
	Yacht newYacht;
	newYacht.setName(name);
	newYacht.setLength(length);
	//push_back is a function of vectors. This function add the new yacht to list.
	yachts.push_back(newYacht);
	cout << "\nYacht added.\n";
	printSeparator();
}

void listYachts() {
	printSeparator();

	if (yachts.empty()) {
		cout << "\nThere is no yacht.\n" << endl;
		printSeparator();
		return;
	}

	cout << "\nListing all yachts:\n" << endl;
	int index = 1;

	for (const Yacht yacht : yachts) {
		cout << index++ << ". ";
		yacht.displayInfo();
		cout << endl;
	}

	cout << "";
	printSeparator();
}

void removeYacht() {
	if (yachts.empty()) {
		cout << "\nThere are no yachts to remove." << endl;
		return;
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
		if (tryAppendIntegerToString(input, choice) && choice > 0 && choice <= static_cast<int>(yachts.size())) {
			//erase is a function of vectors. It deletes by index.
			yachts.erase(yachts.begin() + choice - 1); // Index adjustment since vector index starts from 0
			cout << "Yacht removed." << endl;
			return; // Delete yacht and exit the function
		}
		else {
			cout << "Invalid input. Please try again." << endl;
		}
	}
}

void updateYacht() {
	if (yachts.empty()) {
		cout << "\nThere are no yachts to update." << endl;
		return;
	}

	int yachtIndex = -1;

	while (true) {
		listYachts();
		cout << "Enter the number of the yacht to update (or type 'exit' to cancel): ";
		string input;
		getline(cin, input);

		if (input == "exit") {
			cout << "Yacht update cancelled." << endl;
			return;
		}

		if (tryAppendIntegerToString(input, yachtIndex) && yachtIndex > 0 && yachtIndex <= static_cast<int>(yachts.size())) {
			yachtIndex--; // Adjust for 0-based index
			break;
		}
		else {
			cout << endl;

			if (yachtIndex <= 0) {
				cout << "Please enter a number higher than 0. ";
			}

			if (yachtIndex > static_cast<int>(yachts.size())) {
				cout << "Please enter a number lower than " << static_cast<int>(yachts.size()) << endl;
			}
		}
	}

	string updateChoice;

	while (true) {
		cout << "1. Update Name\n2. Update Length\n3. Update Both\nEnter your choice  (or type 'exit' to cancel): ";
		getline(cin, updateChoice);

		if (updateChoice == "exit") {
			cout << "Yacht update cancelled." << endl;
			return;
		}
		if (updateChoice == "1" || updateChoice == "2" || updateChoice == "3") {
			break;
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
		}
	}

	if (updateChoice == "1" || updateChoice == "3") {
		string newName;
		cout << "Enter new name: ";
		getline(cin, newName);
		yachts[yachtIndex].setName(newName); // Update name using setName method
	}

	if (updateChoice == "2" || updateChoice == "3") {
		while (true) {
			cout << "Enter new length: ";
			string inputLeng;
			getline(cin, inputLeng);
			int newLength;

			if (tryAppendIntegerToString(inputLeng, newLength) && newLength > 0) {
				yachts[yachtIndex].setLength(newLength); // Update length directly
				break;
			}
			else {
				cout << "Invalid length. Please try again." << endl;
			}
		}
	}

	cout << "Yacht updated successfully." << endl;
}


void handleYachtOperations() {
	string input;
	int choice;
	//As long as this variable is true, yacht menu runs always
	bool yachtRunning = true;

	while (yachtRunning) {
		cout << "\nYacht Operations:\n";
		printSeparator();
		cout << "1. Add Yacht\n";
		cout << "2. Remove Yacht\n";
		cout << "3. Update Yacht\n";
		cout << "4. List Yachts\n";
		cout << "5. Return to Admin Menu\n";
		cout << "Enter your choice: ";
		getline(cin, input);

		if (!tryAppendIntegerToString(input, choice))
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
			listYachts();
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
	cout << "\n";
	cout << "Docking Areas Information...\n";
	printSeparator();
	cout << "Azkar Harbor (available)\n";
	cout << "Feudal Harbor (available)\n";
	cout << "Bighthouse Harbor (unavailable)\n";
	cout << "Bigboy Harbor (available)\n";
}

void handleMaintenanceInformation() {
	cout << "\n";
	cout << "Maintenance Information...\n";
	printSeparator();
	cout << " yacht_name " << " yacht_condition " << "Last_maintenance " << " Next_maintenance\n";
}

void handleRefuelingStations() {
	cout << "\n";
	cout << "Refueling Stations Information...\n";
	printSeparator();
	cout << "Azkar Fuel Station (available)\n";
	cout << "Fuedal Fuel Station (available)\n";
	cout << "Bighthouse Fuel Station (unavailable)\n";
	cout << "Bigboy Fuel Station (unavailable)\n";
	cout << "Dunkin Po Fuel Station (available)\n";
}

void handleMaintenanceCrewDetails() {
	cout << "Maintenance Crew Details...\n";
	printSeparator();
	cout << "personal name " << " personal surname\n\n";
	cout << " alihan  " << "       tartar\n";
	cout << " mahmut  " << "       tuncer\n";
	cout << " erol    " << "          tas\n";
	cout << " enes    " << "          koy\n";
	cout << " dilara  " << "        batan\n";
	cout << " volkan  " << "         ucar\n";
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
		cout << "5) Return to Admin Menu\n\n";
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
		cout << "Please enter your choice (1-3): ";
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
