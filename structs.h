#pragma once

#include <iostream>
#include "process.h"

using namespace std;

enum StartMenu
{
	CATALOGUE = 1,
	MY_BALANCE = 2,
	CHOICE_COUNTRIES = 3,
	CHOICE_PACKAGES = 4,
	SHOW_CHOICES_COUNTRIES = 5,
	SHOW_CHOICES_PACKAGES = 6,
	SHOW_ORDER_CLIENT = 7,
	CREATE_ORDER = 8,
	ADMIN_PANEL = 9,
	RE_ENTER_PASSWORD = 10,
	EXIT = 11
};

enum AdminMenu
{
	SHOW_ORDER_ADMIN = 12,
	CHANGE_STATUS_APPLICATION = 13,
	EXIT_ADMIN = 14
};

struct CountriesStruct {
	int country_id;
	string country;
	long int price;
	void country_selected() {
		cout
			<< endl << "Country ID: " << country_id << endl
			<< "Country: " << country << endl
			<< "Price: " << price << endl;
	}	
};

struct PackageStruct {
	int package_id;
	string hotel;
	int days;
	string meal_type;
	long int price;
	void service_package() {
		cout
			<< endl << "Package ID: " << package_id << endl
			<< "Hotel name: " << hotel << endl
			<< "Number days of stay: " << days << endl
			<< "Enter type of meals: " << meal_type << endl
			<< "Package price: " << price << endl;
	}
};

struct OrderStruct {
	unsigned long long _id;
	CountriesStruct countries;
	PackageStruct package;
	string fullname;
	string pasport_id;
	string status;
	int price = package.price + countries.price;
	void print_order() {
		cout
			<< "Order ID: " << _id << endl
			<< "Client full name: " << fullname << endl
			<< "Client passport ID: " << pasport_id << endl
			<< "Trip information" << endl
			<< "Country: " << countries.country << endl
			<< "Hotel: " << package.hotel << endl
			<< "Meal type: " << package.meal_type << endl
			<< "Total price: " << price << endl
			<< "Number days of trip: " << package.days << endl
			<< "Status: " << status << endl;
	}
};
