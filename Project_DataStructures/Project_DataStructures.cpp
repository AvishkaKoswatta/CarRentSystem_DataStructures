//This project is about a digital car renting system

#include <iostream>
#include<windows.h>
using namespace std;

void InvalidInputMessage() {
	system("cls");
	cout << "\n\n  \t\t\t\t\tINVALID INPUT!!!! \n  \t\t\t\t\tTRY AGAIN";
};


class Customer {
public:
	int  phone_number;
	string customer_name, customer_address, NIC_number;
	double   service_charge;

	Customer* next1;
	Customer* prev1;

	Customer() {//constructor

		phone_number = 0;
		customer_name = "NULL";
		customer_address = "NULL";
		NIC_number = "NULL";

		next1 = NULL;
		prev1 = NULL;
	}

	Customer(int phoneNumber, string customerName, string customerAddress, string NICNumber) { //overloaded constructor

		phone_number = phoneNumber;
		customer_name = customerName;
		customer_address = customerAddress;
		NIC_number = NICNumber;
		next1 = NULL;
		prev1 = NULL;
	}
};

class Car {
public:
	int  plateNo;
	string price, brand, model, color;
	

	Car* next2;
	Car* prev2;

	Car() {

		plateNo = 0;
		price = "NULL";
		brand = "NULL";
		model = "NULL";
		color = "NULL";
		

		next2 = NULL;
		prev2 = NULL;
	}

	Car(int PlateNo, string Price, string Brand, string Model, string Color) { //overloaded constructor

		plateNo = PlateNo;
		price = Price;
		brand = Brand;
		model = Model;
		color = Color;
		next2 = NULL;
		prev2 = NULL;
	}
};


class Doubly_Linked_List
{
private:
	Customer* head1;
	Customer* tail1;
	Car* head2;
	Car* tail2;
	int size;

public:
	Doubly_Linked_List() {
		head1 = NULL;
		tail1 = NULL;
		head2 = NULL;
		tail2 = NULL;
		size = 0;
	}

	void Exit()
	{
		int exit;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "<<< Press 1 to Home Page     " << endl;
		cout << "<<< Press 0 to Exit  " << endl;
		cout << endl;

		cout << "               ";
		cin >> exit;
		system("cls");
		if (exit == 1)printMenuPage();
	}



	Car* carAccess(int PlateNo) { //car access function
		Car* current2 = head2;
		for (int i = 0; i < size; i++) {
			if (current2->plateNo == PlateNo)
				return current2;

			current2 = current2->next2;
		}
		cout << "Not found plate number :" << PlateNo << endl;
		return NULL;
	};


	/*
		void undo() {
			Car* current2 = head2;
			if (current2 != NULL && current2->prev2 != NULL) {
				current2 = current2->prev2;
			};
	*/



	void addFirstCustomer(int phoneNumber, string customerName, string customerAddress, string NICNumber) {

		Customer* temp1 = new Customer(phoneNumber, customerName, customerAddress, NICNumber);


		head1 = temp1;
		tail1 = temp1;
		size++;


	}
	void addLastCustomer(int phoneNumber, string customerName, string customerAddress, string NICNumber) {

		Customer* temp1 = new Customer(phoneNumber, customerName, customerAddress, NICNumber);

		if (head1 == NULL) {
			head1 = temp1;
			tail1 = temp1;
			size++;
		}
		else {
			tail1->next1 = temp1;
			temp1->prev1 = tail1;
			tail1 = temp1;
			size++;
		}
	}


	void addFirstCar(int PlateNo, string Price, string Brand, string Model, string Color) {

		Car* temp2 = new Car(PlateNo, Price, Brand, Model, Color);


		head2 = temp2;
		tail2 = temp2;
		size++;
	}



	void addLastCar(int PlateNo, string Price, string Brand, string Model, string Color) {

		Car* temp2 = new Car(PlateNo, Price, Brand, Model, Color);

		if (head2 == NULL) {
			head2 = temp2;
			tail2 = temp2;
			size++;
		}
		else {
			tail2->next2 = temp2;
			temp2->prev2 = tail2;
			tail2 = temp2;
			size++;
		}
	}



	//search a customer
	void find_customer(string customer_name) {
		bool foundnotfound = 0;
		cout << "\n\nCustomer name ' " << customer_name << " ' ";
		Customer* current = head1;
		for (int i = 0; i < size; i++) {
			if (current->customer_name == customer_name) {
				foundnotfound = 1;

				cout << "\n                " << " \t Name      : " << current->customer_name;
				cout << "\n                " << " \t Address   : " << current->customer_address;
				cout << "\n                " << " \t Phone number   : " << current->phone_number;
				cout << "\n                " << " \t NIC   : " << current->NIC_number;
				Exit();
			}
			current = current->next1;
		}
		if (foundnotfound == 0)cout << "were not found";
		Exit();

	}

	//edit a car price
	void editCurrentCar(int PlateNo, string newPrice) {
		Car* current3 = carAccess(PlateNo);
		current3->price = newPrice;
	};




	void delete_Car(int PlateNo) {
		Car* current = carAccess(PlateNo);
		if (current->plateNo == PlateNo) {
			if (current == head2) {
				Car* temp = current;
				current = current->next2;
				head2 = current;
				delete temp;
			}
			else if (current == tail2) {
				Car* temp = current;
				current = current->next2;

				delete temp;
			}
			else {
				Car* temp = current;
				current = current->next2;

				delete temp;
			}
			size--;
		}

	}





	//display all cars available
	void displayAllCars()
	{

		Car* current = head2;

		while (current != NULL) {
			cout << current->plateNo << "\t\t ";
			cout << current->price << "\t\t ";
			cout << current->brand << "\t\t ";
			cout << current->model << "\t\t ";
			cout << current->color << " ";

			current = current->next2;
			cout << endl;
		}

		cout << endl;

	}

	//display all customers
	void displaycustomer()
	{

		Customer* current = head1;

		while (current != NULL) {
			cout << current->phone_number << "\t ";
			cout << current->customer_name << "\t ";
			cout << current->customer_address << "\t ";
			cout << current->NIC_number << "\t ";
			current = current->next1;
			cout << endl;
		}

		cout << endl;

	}


	//check if car is available and print it
	void find_car(int plateNo) {
		bool foundnotfound = 0;

		Car* current = head2;
		for (int i = 0; i < size; i++) {
			if (current->plateNo == plateNo) {
				foundnotfound = 1;

				cout << "\n                " << " \t Car brand      : " << current->brand;
				cout << "\n                " << " \t Color		: " << current->color;
				cout << "\n                " << " \t Car price      : " << current->price;
				cout << "\n                " << " \t Car model      : " << current->model;
				Exit();
			}
			current = current->next2;

		}
		if (foundnotfound == 0)cout << "were not found";
		Exit();
	}


	//check whether a given car exist (true or false)
	bool searchCar(int plateNo) {
		Car* current = head2;

		while (current != NULL) {
			if (current->plateNo == plateNo) {
				cout << "Car is available." << endl;
				cout << "You have requested " << plateNo << endl;
				delete_Car(plateNo);
				cout << endl;
				Exit();
				return true;
			}

			current = current->next2;
		}
		cout << "	       Car is not found" << endl;

		cout << endl;

		Exit();

	}



	//Mian menu page
	void printMenuPage() {

		cout << "\n\n\n";





		cout << "				xxxxxxxxxxxxxxxxxxx" << endl;
		cout << "			     xx	  	***        xx" << endl;
		cout << "		           xx	        ***          xx" << endl;
		cout << "                   xxxxxxx                           xxxxxx" << endl;
		cout << "                   xx  				          x" << endl;
		cout << "                   xx		                          x" << endl;
		cout << "                   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXX    W E  L   C    O      M        E.........." << endl;
		cout << "                       (xxxxxxx)	  (xxxxxxx) " << endl;
		cout << "                        (xxxxx)	           (xxxxx) " << endl;





		cout << "\n\n\n";

		cout << "						DIGITAL CAR RENTAL SYSTEM" << endl;
		cout << "				    ------------------------------------------------" << endl;

		cout << "\n\n";


		cout << "						01.Press 1 for Customer" << endl;
		cout << "						02.Press 2 for Admin" << endl;
		cout << "						03.Press 3 for Display all cars" << endl;
		cout << "						04.Press 4 to Back" << endl;


		int choice;
		cin >> choice;
		system("cls");
		if (choice == 1)printCustomerSection();
		else if (choice == 2)printAdminSection();
		else if (choice == 3)printCars();
		else if (choice == 4) return;
		else { InvalidInputMessage(); }

	};



	int  printCustomerSection()
	{
		cout << "\n\n\n";
		cout << "                                              CUSTOMER SECTION                          " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\n";
		cout << "<This is customer page>";
		cout << "\n\n";
		cout << "                                            01. Press 1  to  Search a car             " << endl;
		cout << "                                            02. Press 2  to  Request a car                            " << endl;
		cout << "                                            03. Press 0  to Back                             " << endl;


		cout << "                                                                                    \n\n" << endl;



		int choice;
		cin >> choice;
		system("cls");
		if (choice == 1)FindCar();
		else if (choice == 2)Requestcar();


		else if (choice == 0) { printMenuPage(); }
		else { InvalidInputMessage(); }

		return choice;
	};


	int printAdminSection()
	{
		cout << "\n\n\n";

		cout << "						ADMIN SECTION" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\n";
		cout << "<This is Admin page>";
		cout << "\n\n";

		cout << "					01.Press 1  to add a car" << endl;
		cout << "					02.Press 2  to remove a car " << endl;
		cout << "					03.Press 3  to view all the customers " << endl;
		cout << "					04.Press 4  to edit the price of a car " << endl;
		cout << "					05.Press 5  to search a customers " << endl;
		cout << "					00.Press 0  to back " << endl;


		cout << "               \n\n" << endl;

		int choice;
		cin >> choice;
		system("cls");
		if (choice == 0) printMenuPage();
		else if (choice == 1)Add_a_car();
		else if (choice == 2)Remove_a_car();
		else if (choice == 3)AllCustomers();
		else if (choice == 4)Edit_A_Car_Price();
		else if (choice == 5)A_customer();


		else {
			InvalidInputMessage();
			printAdminSection();
		}
		return choice;
	};



	void printCars()
	{
		cout << "\n\n\n";
		cout << "						ALL CARS" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\n";
		cout << "<Available all cars>";
		cout << "\n\n";

		displayAllCars();

		cout << "\n\n";
		cout << "[Price is for per day]" << endl;

		Exit();
	}




	void FindCar()
	{
		cout << "               \n\n" << endl;

		cout << "						FIND A CAR              " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\n";
		cout << "<You can find a car by entering car number plate>";
		cout << "\n\n";
		cout << "Enter car number plate: ";

		int carNo;
		cin >> carNo;
		find_car(carNo);
		//searchCar(carNo);
		Exit();
	}

	void Requestcar()
	{
		cout << "               \n\n" << endl;

		cout << "								REQUEST A CAR               " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << "\n\n";
		cout << "<You can request a car>";
		cout << "\n\n";
		int phNO;
		string cusName, cusAddress, cusNIC;
		cout << "Before request check the available car list.    \n";
		cout << "You have to enter phone number, name, address and NIC number    \n";
		cout << endl;
		cout << "Enter phone number\t\t:";
		cin >> phNO;
		cout << "Enter name\t\t\t:";
		cin >> cusName;
		cout << "Enter address(No space)\t\t:";
		cin >> cusAddress;
		cout << "Enter NIC number\t\t:";
		cin >> cusNIC;

		cout << endl;




		addLastCustomer(phNO, cusName, cusAddress, cusNIC);
		//displaycustomer(phNO, cusName, cusAddress, cusNIC);


		int RequestPlateNo;
		cout << "Enter the plate number of car you want to request:" << endl;
		cin >> RequestPlateNo;
		searchCar(RequestPlateNo);
		delete_Car(RequestPlateNo);
		//cout << "You have requested " << endl;



	}



	void Add_a_car()
	{
		cout << "               \n\n" << endl;

		cout << "						ADD A CAR TO THE SYSTEM               " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << "\n\n";

		int carPlateNo;
		string carPrice, carBrand, carModel, carColor;
		cout << "Enter plate number   :";
		cin >> carPlateNo;
		cout << "Enter price   :";
		cin >> carPrice;
		cout << "Enter brand   :";
		cin >> carBrand;
		cout << "Enter model   :";
		cin >> carModel;
		cout << "Enter color   :";
		cin >> carColor;

		addLastCar(carPlateNo, carPrice, carBrand, carModel, carColor);
		cout << endl;
		cout << "System has below cars:" << endl;
		cout << endl;
		displayAllCars();

		Exit();


	}



	void Remove_a_car()
	{
		cout << "               \n\n" << endl;

		cout << "								REMOVE CAR               " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << "\n\n";
		int carPlateNo;

		cout << "Enter plate number   :";
		cin >> carPlateNo;


		delete_Car(carPlateNo);
		cout << endl;
		cout << "Now only this cars will be available" << endl;
		cout << endl;
		displayAllCars();

		Exit();

	}


	void AllCustomers()
	{

		cout << "               \n\n" << endl;

		cout << "							ALL CUSTOMERS               " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\n";
		displaycustomer();

		Exit();
	}


	void Edit_A_Car_Price()
	{
		cout << "               \n\n\n" << endl;

		cout << "							EDIT CAR PRICE              " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << "\n\n";
		int PlateNumber;
		string NewCarPrice;
		cout << "Enter the plate number of the car" << endl;
		cin >> PlateNumber;
		cout << "Enter the new price" << endl;
		cin >> NewCarPrice;

		editCurrentCar(PlateNumber, NewCarPrice);
		cout << endl;
		displayAllCars();

		Exit();


	}

	void A_customer()
	{

		cout << "               \n\n" << endl;

		cout << "							SEARCH A CUSTOMER              " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------" << endl;

		cout << "Enter the name of a customer" << endl;


		string A_customer_name;
		cin >> A_customer_name;
		find_customer(A_customer_name);

		Exit();


	}


};




int main()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT srWindowRect = { 0, 0, 100, 50 }; // set the window size to 80x25 characters (0-based indexing)

	// set the console window size
	SetConsoleWindowInfo(hConsole, TRUE, &srWindowRect);

	//sample users 
	Doubly_Linked_List Customer_dll;
	Customer_dll.addFirstCustomer(0111222333, "Tom", "Lake_road", "001v");
	Customer_dll.addLastCustomer(0222111333, "Anne", "First_Lane", "002v");
	Customer_dll.addLastCustomer(0333111222, "Jane", "White_road", "003v");
	system("cls");

	Doubly_Linked_List Car_dll;
	//cout << "Plate No" << "\tPrice" << "\tBrand" << "\tModel" << "\tColor" << endl;

	Customer_dll.addFirstCar(12341, "10$", "Toyota", "Corlla", "Green");
	Customer_dll.addLastCar(12342, "15$", "Toyota", "Aqua", "Blue");
	Customer_dll.addLastCar(12343, "20$", "Honda", "Civic", "White");
	Customer_dll.addLastCar(12344, "20$", "Suzuki", "Alto", "Black");
	Customer_dll.addLastCar(12345, "21$", "suzuki", "WagonR", "White");
	Customer_dll.addLastCar(12346, "40$", "Nissan", "Solio", "White");
	system("cls");

	//start
	Customer_dll.printMenuPage();
	Car_dll.printMenuPage();

	//finish
	cout << "\n\n\n" << endl;

	cout << "                                                   THANK YOU !" << endl;

	cout << "\n\n\n" << endl;


}