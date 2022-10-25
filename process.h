#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "structs.h"

using namespace std;

class Person;
class Employee;
class Client;
class Order;
class Countries;
class Package;
class Catalogue;
class Administrator;
class TourAgency;

class Package {
private:
	PackageStruct* package;
	long int size_struct;

public:
	/* Constructors */
	Package() {};
	Package(PackageStruct* p, int size_str) {
		package = new PackageStruct[size_struct];
		package = p;
		size_struct = size_str;
	};
	/* End Constructors */

	/* Getters and Setters */
	void setPackage(PackageStruct* package) {
		this->package = package;
	}
	PackageStruct* getPackage() {
		return this->package;
	}

	void setSizeStruct(int _size) {
		this->size_struct = _size;
	}
	int getSizeStruct() {
		return this->size_struct;
	}
	/* End Getters and Setters */
};

class Countries {
private:
	CountriesStruct* countries;
	long int size_struct;

public:
	/* Constructors */
	Countries() {};
	Countries(CountriesStruct* c, int size_str) {
		countries = new CountriesStruct[size_struct];
		countries = c;
		size_struct = size_str;
	};
	/* End Constructors */

	/* Getters and Setters */
	void setCountries(CountriesStruct* countries) {
		this->countries = countries;
	}
	CountriesStruct* getCountries() {
		return this->countries;
	}

	void setSizeStruct(int _size) {
		this->size_struct = _size;
	}
	int getSizeStruct() {
		return this->size_struct;
	}
	/* End Getters and Setters */
};

class Order {
private:
	Package package_ordr;
	Client clnt;
	Countries countries_ordr;
	Client* client_ordr;
	vector<OrderStruct> ordr;

public:
	/* Constructors */
	Order() {};
	Order(Client clnt) {
		this->clnt.fullname = clnt.fullname;
		this->clnt.pasport_id = clnt.pasp_id;
	};
	/* End Constructors */

	/* Getters and Setters */
	void setFullNameOrd(Client clnt){
		this->fullname = clnt.fullname;
	};
	string getFullNameOrd(Client clnt) {
		return this->clnt.fullname;
	};

	void setOrder(OrderStruct ordr_struct) {
		this->ordr.push_back(ordr_struct);
	};
	void changeOrder(OrderStruct ordr, int number) {
		this->ordr[number] = ordr;
	};
	vector<OrderStruct> getOrder() {
		return this->ordr;
	};

	void setPackage(Package package) {
		this->package_ordr = package;
	};

	void setCountry(Countries countries) {
		this->countries_ordr = countries;
	};

	Client* getClient() {
		return this->client_ordr;
	}
	void setClient(Client* client) {
		this->client_ordr = client;
	}

	/* End Getters and Setters , const string filepath*/

	/* Methods */
	void file_txt(OrderStruct order, const string filepath)
	{
		ofstream file(filepath, ios::app);
		file
			<< "Order ID: " << order._id << endl
			<< "Your full name: " << order.fullname << endl
			<< "Your passport ID: " << order.pasport_id << endl
			<< "Trip information" << endl
			<< "Country: " << order.countries.country << endl
			<< "Hotel: " << order.package.hotel << endl
			<< "Meal type: " << order.package.meal_type << endl
			<< "Total price: " << order.price << endl
			<< "Number days in trip: " << order.package.days << endl 
			<< "------------------------------" << endl;
		file.close();
	}
	void file_dat(OrderStruct order, const string filepath)
	{
		ofstream file(filepath, ios::out | ios::binary | ios::app);
		for (int i = 0; i < this->ordr.size(); i++)
		{
			file << setw(12) <<
				this->ordr[i]._id << setw(10) <<
				this->ordr[i].fullname << setw(10) <<
				this->ordr[i].pasport_id << setw(10) << endl;
		}
		file.close();
	}
	void createOrder(OrderStruct order) {
		file_txt(order, "order.txt");
		file_dat(order, "order.dat");
		setOrder(order);
	};
	/* End Methods */
};

class Person {
private:
	string name;
	string surname;
	string password;
	string adminpass = "admin";
	long int money = 20000;
	
public:
	/* Constructors */
	Person() {};
	Person(string name, string surname, string password) {
			this->name = name;
			this->surname = surname;
			this->password = password;
		};
	/* End Constructors */
		
	/* Getters and Setters */
	string getPassword() {
		return this->password; 
	};
	string getFullName() {
		return this->name + " " + this->surname;
	};

	void setNamae(string name) { 
		this->name = name; 
	};
	void setSurname(string surname) {
		this->surname = surname;
	};
	void setPassword(string password) {
		this->password = password; 
	};
	long int getMoney() { 
		return this->money; 
	};
	void setMoney(long int money) {
		this->money = money; 
	};

	/* End Getters and Setters */
		
	/* Methods */
	bool is_admin() { 
		return this->password == this->adminpass; 
	};
	/* End Methods */
};

class Employee
{
protected:
	string rectorName;
	double wage =  4000;
public:

	/* Getters and Setters */

	void setRectorName(string name)
	{
		this->rectorName = name;
	}

	string getRectorName()
	{
		return string(this->rectorName);
	}

	double getWage()
	{
		return this->wage;
	}
	/* End Getters and Setters */

};

class Client : public Person {
private:
	string fullname;
	string pasport_id;
	PackageStruct choice_client_package;
	CountriesStruct choice_client_countries;
	Package package_client_side;
	Countries countries_client_side;
	Order ordr;

public:
	Client() {};
	/* Constructors */
	Client(string name, string surname, string password, Package package, Countries countries) : Person(name, surname, password) {
		this->package_client_side = package;
		this->countries_client_side = countries;
	};
	/* End Constructors */
		
	/* Getters and Setters */
	string getPasportId() { 
		return this->pasport_id;
	};
	void setPasportId(string pasport_id) { 
		this->pasport_id = pasport_id; 
	};

	void setOrdr(Order ord) { 
		this->ordr = ord;
	}
	Order getOrdr() { 
		return this->ordr;
	}

	PackageStruct getChoiceClientPackage() {
		return this->choice_client_package;
	};
	CountriesStruct getChoiceClientCountries() {
		return this->choice_client_countries;
	};
	void setChoiceClientPackage(PackageStruct choice_client_package) {
		this->choice_client_package = choice_client_package;
	};
	void setChoiceClientCountries(CountriesStruct choice_client_countries) {
		this->choice_client_countries = choice_client_countries;
	};
	/* End Getters and Setters */
	
	/* Methods */
	PackageStruct getPackageByNumber(int number) {
		PackageStruct* p = package_client_side.getPackage();
		for (int i = 0; i < package_client_side.getSizeStruct(); i++) {
			if (p[i].package_id == number) {
				return p[i];
			};
		};
	};
	CountriesStruct getCountriesByNumber(int number) {
		CountriesStruct* c = countries_client_side.getCountries();
		for (int i = 0; i < countries_client_side.getSizeStruct(); i++) {
			if (c[i].country_id == number) {
				return c[i];
			};
		};
	};
	void showPackage() {
		PackageStruct* p = package_client_side.getPackage();
		for (int i = 0; i < package_client_side.getSizeStruct(); i++) {
			p[i].service_package();
		};
	};
	void showCountries() {
		CountriesStruct* c = countries_client_side.getCountries();
		for (int i = 0; i < countries_client_side.getSizeStruct(); i++) {
			c[i].country_selected();
		};
	};
	void showOrder() {
		for (int i = 0; i < this->ordr.getOrder().size(); i++)
		{
			this->ordr.getOrder()[i].print_order();
		}
	}
	/* End Methods */
};

class Administrator : public Person, private Employee {
private:
	Employee employee;
public:
	/* Constructors */
	Administrator() {};
	Administrator(string name, string surname, string password) : Person(name, surname, password){};
	/* End Constructors */


	/* Getters and Setters */
	void setEmployee(Employee empl)
	{
		this->employee = empl;
	}

	Employee getEmployee()
	{
		return Employee(this->employee);
	}
	/*End Getters and Setters */

	/* Methods */
	void showOrder(Order* ord)
	{
		for (int i = 0; i < ord->getOrder().size(); i++)
		{
			ord->getOrder()[i].print_order();
		}
	};
	void changeStatus(int number_app, string status_ordr, Client* cl, Order* ord)
	{
		vector<OrderStruct> orders = ord->getOrder();
		if (status_ordr == "Aprove") {
			for (int i = 0; i < orders.size(); i++)
			{
				if (orders[i]._id == number_app)
				{
					orders[i].status = status_ordr;
					ord->changeOrder(orders[i], i);
					cl->setMoney(cl->getMoney() - orders[i].price);
					return;
				}
			}
		}
		else if (status_ordr == "Reject")
		{
			for (int i = 0; i < orders.size(); i++)
			{
				if (orders[i]._id == number_app)
				{
					orders[i].status = status_ordr;
					ord->changeOrder(orders[i], i);
					return;
				}
			}
		}
	};
	/* End Methods */
};

class Catalogue {
private:
	Package package;
	Countries countries;
public:
	Catalogue(Countries cntries, Package pckg) {
		this->countries = cntries;
		this->package = pckg;
	}
	void showCountries() {
		CountriesStruct* c = countries.getCountries();
		cout << "\nChoice countries: \n";
		for (int i = 0; i < countries.getSizeStruct(); i++) {
			c[i].country_selected();
		};
	};
	void showPackage() {
		PackageStruct* p = package.getPackage();
		cout << "\nChoice package: \n";
		for (int i = 0; i < package.getSizeStruct(); i++) {
			p[i].service_package();
		};
	};	
};

class TourAgency {
private:
	Administrator* admin;
	string name_tours;
	string lastname_tours;
public:
	TourAgency(Administrator* admin = nullptr):admin(admin) {}

	string getFullName() { 
		return this->name_tours + " " + this->lastname_tours;
	}
};
