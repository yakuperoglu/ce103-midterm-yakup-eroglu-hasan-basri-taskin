/**
 * @file yachtsystem.h
 *
 * @brief Provides functions for yacht system utilities
 */

#ifndef YACHTSYSTEM_H
#define YACHTSYSTEM_H

#include "../../utility/header/commonTypes.h"
#include <string>

using namespace std;

namespace Coruh {
	namespace Yachtsystem {
		struct SeaVehicle {
			bool setName(const string& name);  // Set the name of the yacht
			bool setLength(int length);            // Set the length of the yacht
			bool setMaintanceStatus(const string& input);   // Set the maintance status of yacht
			bool setOwner(const string& name);    // Set the owner of the yacht
			int displayInfo() const;            // Display yacht information
			int displayExtendedInfo() const;       // Display extended yacht information

		private:
			bool maintanceStatus;
			string name;
			int length;
			string owner;
		};

		struct Reservation {
			bool setCustomerName(const string& name);   // Set the customer's name
			int displayInfo() const;       // Display reservation information

		private:
			string customerName;
			string reservationDate;
		};
	}
}

#endif // YACHTSYSTEM_H
