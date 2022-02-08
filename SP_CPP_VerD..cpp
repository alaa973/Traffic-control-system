#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int kMax_fines_number = 100, kRoad_maximum_speed = 70, kNumber_of_drivers = 10, kMax_cars_number = 3;
int plate_number, counter, fine_choice;
bool hasFoundCar, hasFoundFine;
struct Date {
	int day, month, year;
};
struct Fine {
	int value;
	Date date;
	string status, steet_name;
};
struct Car {
	int plate_number;
	string model;
	Fine fines[kMax_fines_number];
	int production_year;
};
struct Driver {
	int total_unpaid;
	int license_number;
	string name;
	Date birthdate;
	Car cars[kMax_cars_number];
};
struct Update {
	int which_driver;
	int which_car;
	int which_fine;
};
Driver drivers[kNumber_of_drivers];
void SystemData() {
	drivers[0].license_number = 123456789;
	drivers[0].name = "Fathy Ahmed";
	drivers[0].birthdate = { 10, 2, 1990 };
	drivers[0].cars[0].plate_number = 123;
	drivers[0].cars[0].model = "Ferrari 488 Pista";
	drivers[0].cars[0].production_year = { 2019 };

	drivers[1].license_number = 123457789;
	drivers[1].name = "Wael Ahmed";
	drivers[1].birthdate = { 10, 5, 1995 };
	drivers[1].cars[0].plate_number = 125;
	drivers[1].cars[0].model = "Jeep Wrangler";
	drivers[1].cars[0].production_year = { 2017 };

	drivers[2].license_number = 126656789;
	drivers[2].name = "Yehia Fathy";
	drivers[2].birthdate = { 10, 1, 1999 };
	drivers[2].cars[0].plate_number = 873;
	drivers[2].cars[0].model = "Jeep Grand Cherokee";
	drivers[2].cars[0].production_year = { 2011 };

	drivers[3].license_number = 223456789;
	drivers[3].name = "Omnia Maher";
	drivers[3].birthdate = { 8, 2, 1998 };
	drivers[3].cars[0].plate_number = 223;
	drivers[3].cars[0].model = "MINI Hardtop";
	drivers[3].cars[0].production_year = { 2014 };

	drivers[4].license_number = 323456789;
	drivers[4].name = "Esraa Ramy";
	drivers[4].birthdate = { 16, 2, 1995 };
	drivers[4].cars[0].plate_number = 129;
	drivers[4].cars[0].model = "FIAT 500";
	drivers[4].cars[0].production_year = { 2018 };

	drivers[5].license_number = 423456789;
	drivers[5].name = "Elina Yassen";
	drivers[5].birthdate = { 10, 10, 1990 };
	drivers[5].cars[0].plate_number = 467;
	drivers[5].cars[0].model = "FIAT 500e";
	drivers[5].cars[0].production_year = { 2016 };

	drivers[6].license_number = 523456789;
	drivers[6].name = "peter David";
	drivers[6].birthdate = { 11, 12, 1999 };
	drivers[6].cars[0].plate_number = 758;
	drivers[6].cars[0].model = "FIAT 124 Spider";
	drivers[6].cars[0].production_year = { 2017 };

	drivers[7].license_number = 623456789;
	drivers[7].name = "Sayed emam";
	drivers[7].birthdate = { 5, 7, 1990 };
	drivers[7].cars[0].plate_number = 923;
	drivers[7].cars[0].model = "Toyota 86";
	drivers[7].cars[0].production_year = { 2017 };
	drivers[7].cars[1].plate_number = 953;
	drivers[7].cars[1].model = "Toyota Sequoia";
	drivers[7].cars[1].production_year = { 2012 };

	drivers[8].license_number = 723456785;
	drivers[8].name = "Ammar khalid";
	drivers[8].birthdate = { 10, 7, 1993 };
	drivers[8].cars[0].plate_number = 133;
	drivers[8].cars[0].model = "Toyota RAV4";
	drivers[8].cars[0].production_year = { 2020 };
	drivers[8].cars[1].plate_number = 533;
	drivers[8].cars[1].model = "Nissan Altima";
	drivers[8].cars[1].production_year = { 2018 };

	drivers[9].license_number = 128456789;
	drivers[9].name = "Hoda Malik";
	drivers[9].birthdate = { 10, 2, 1980 };
	drivers[9].cars[0].plate_number = 623;
	drivers[9].cars[0].model = "Nissan Rogue";
	drivers[9].cars[0].production_year = { 2015 };
	drivers[9].cars[1].plate_number = 727;
	drivers[9].cars[1].model = "Dodge Challenger";
	drivers[9].cars[1].production_year = { 2016 };
	drivers[9].cars[2].plate_number = 528;
	drivers[9].cars[2].model = "BMW 230";
	drivers[9].cars[2].production_year = { 2017 };
};
Update updates[3005];
void AssignFine() {
	cout << "Note: Maximum allowed road speed is 70 km/h.\n";
	hasFoundCar = false;
    int car_speed;
    string street_name;
	Date fine_assignment_date;
	cout << "Street name: ";
	cin.ignore();
	getline(cin, street_name);
	do {
		cout << "\nCar speed: ";
		cin >> car_speed;
		if (car_speed > 450)
			cout << "Speed can't exceed 450 km/h.";
		else if (car_speed < 0)
			cout << "Speed can't be a negative number.\n";
	} while (car_speed > 450 || car_speed < 0);
	cout << "\nCar plate number: ";
	cin >> plate_number;
	do {
		cout << "\nDate: Day) ";
		cin >> fine_assignment_date.day;
		if (fine_assignment_date.day <= 0 || fine_assignment_date.day > 31)
			cout << "Day must be a number from 1 to 31.";
	} while (fine_assignment_date.day <= 0 || fine_assignment_date.day > 31);
	do {
		cout << "Month) ";
		cin >> fine_assignment_date.month;
		if (fine_assignment_date.month <= 0 || fine_assignment_date.month > 12)
			cout << "Month must be a number from 1 to 12.\n";
	} while (fine_assignment_date.month <= 0 || fine_assignment_date.month > 12);
		cout << "Year) ";
		cin >> fine_assignment_date.year;
    if (car_speed <= kRoad_maximum_speed)
		cout << "No fine has been assigned, The Car speed didn't exceed maximum allowed road speed.\n";
	else {
		for (int drivers_counter = 0; drivers_counter < kNumber_of_drivers; drivers_counter++) {
			for (int cars_counter = 0; cars_counter < kMax_cars_number; cars_counter++) {
				for (int fines_counter = 0; fines_counter < kMax_fines_number; fines_counter++) {
					if (drivers[drivers_counter].cars[cars_counter].plate_number == plate_number &&
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value == 0) {
						hasFoundCar = true;
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value = (car_speed - kRoad_maximum_speed) * 2;
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date = fine_assignment_date;
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].status = "Unpaid.";
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].steet_name = street_name;
						drivers[drivers_counter].total_unpaid += (car_speed - kRoad_maximum_speed) * 2;
						cout << "Done !\n";
						return;
					}	
				}
			}
	    }
	if (!hasFoundCar)
		cout << "There is no car with this plate number.\n";
	}
}
void PayByPlate() {
	hasFoundFine = false;
	hasFoundCar = false;
	cout << "Please enter your plate number.\n";
    counter = 0;
	cin >> plate_number;
	for (int drivers_counter = 0; drivers_counter < kNumber_of_drivers; drivers_counter++) {
		for (int cars_counter = 0; cars_counter < kMax_cars_number; cars_counter++) {
		  if (drivers[drivers_counter].cars[cars_counter].plate_number == plate_number) {
			 hasFoundCar = true;
			for (int fines_counter = 0; fines_counter < kMax_fines_number; fines_counter++) {
				if (drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value != 0 &&
					drivers[drivers_counter].cars[cars_counter].fines[fines_counter].status == "Unpaid.") {
						hasFoundFine = true;
				  //to be displayed only once when the counter is equal to zero
				  if(!counter)
					cout << "\tList of fines\n";
					cout << counter + 1 << ") Value: " << drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value << "\nIn street: " <<
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].steet_name << "\nDate: Day)" <<
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.day << "\tMonth) " <<
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.month << "\tyear) " <<
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.year << "\n";;
					updates[counter] = { drivers_counter, cars_counter, fines_counter };
					counter++;
				}
			}
		  }
		}
	}
	if (!hasFoundCar)
		cout << "There is no car with this plate number.\n";
	else if (!hasFoundFine)
		cout << "There are no unpaid fines assigned to this car.\n";
	else {
		cout << "Enter the number of the fine you would like to pay.\n";
		    cin >> fine_choice;
 	     if(fine_choice <= counter && fine_choice != 0) {
				cout << "Done !\n";
				drivers[updates[fine_choice - 1].which_driver].cars[updates[fine_choice - 1].which_car].fines[updates[fine_choice - 1].which_fine].status = "Paid.";
				drivers[updates[fine_choice - 1].which_driver].total_unpaid -= drivers[updates[fine_choice - 1].which_driver].cars[updates[fine_choice - 1].which_car].
				fines[updates[fine_choice - 1].which_fine].value;
			}
			else
				cout << "Invalid choice !\n";
	}
}
void PayByName() {
	string name;
	cout << "Please enter your name. Make sure you capitalize the first letter of each name.\n";
	cin.ignore();
	getline(cin, name);
    counter = 0;
	hasFoundCar = false;
	hasFoundFine = false;
	for (int drivers_counter = 0; drivers_counter < kNumber_of_drivers; drivers_counter++) {
		if (drivers[drivers_counter].name == name) {
			hasFoundCar = true;
		  for (int cars_counter = 0; cars_counter < kMax_cars_number; cars_counter++) {
			  for (int fines_counter = 0; fines_counter < kMax_fines_number; fines_counter++) {
				  if(drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value != 0 &&
					  drivers[drivers_counter].cars[cars_counter].fines[fines_counter].status == "Unpaid.") {
					  hasFoundFine = true;
					  //to be displayed only once when the counter is equal to zero
					  if (!counter)
						  cout << "\tList of fines\n";
					  cout << counter + 1 << ")\nCar model: " << drivers[drivers_counter].cars[cars_counter].model << "\nValue: " <<
						  drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value << "\nIn street: " <<
						  drivers[drivers_counter].cars[cars_counter].fines[fines_counter].steet_name << "\nDate: Day)" <<
						  drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.day << "\tMonth) " <<
						  drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.month << "\tyear) " <<
						  drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.year << "\n";
					  updates[counter] = { drivers_counter, cars_counter, fines_counter };
					  counter++;
				  }
			  }
		  } 
	    }
	}
	if (!hasFoundCar)
		cout << "There's no driver with this name.\n";
	else if (!hasFoundFine)
		cout << "There are no unpaid fines assigned to this driver.\n";
	else {
		cout << "Enter the number of the fine you would like to pay.\n";
		cin >> fine_choice;
		if (fine_choice <= counter && fine_choice != 0) {
			drivers[updates[fine_choice - 1].which_driver].cars[updates[fine_choice - 1].which_car].fines[updates[fine_choice - 1].which_fine].status = "Paid.";
			drivers[updates[fine_choice - 1].which_driver].total_unpaid -=
			drivers[updates[fine_choice - 1].which_driver].cars[updates[fine_choice - 1].which_car].fines[updates[fine_choice - 1].which_fine].value;
			cout << "Done !\n";
		}
		else
			cout << "Invalid choice !\n";
	}
}
void PayByLicense() {
	int license_number;
	counter = 0;
	cout << "Please enter your license number.\n";
	cin >> license_number;
    hasFoundCar = false;
	hasFoundFine = false;
	for (int drivers_counter = 0; drivers_counter < kNumber_of_drivers; drivers_counter++) {
		if (drivers[drivers_counter].license_number == license_number) {
			hasFoundCar = true;
			for (int cars_counter = 0; cars_counter < kMax_cars_number; cars_counter++) {
				for (int fines_counter = 0; fines_counter < kMax_fines_number; fines_counter++) {
					if (drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value != 0 &&
						drivers[drivers_counter].cars[cars_counter].fines[fines_counter].status == "Unpaid.") {
						hasFoundFine = true;
						//to be displayed only once when the counter is equal to zero
						if (!counter)
							cout << "\tList of fines\n";
						    cout << counter + 1 << ")\nCar model: " << drivers[drivers_counter].cars[cars_counter].model << "\nValue: " <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value << "\nIn street: " <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].steet_name << "\nDate: Day)" <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.day << "\tMonth) " <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.month << "\tyear) " <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.year << "\n";
						updates[counter] = { drivers_counter, cars_counter, fines_counter };
						counter++;
					}
				}
			}
		}
	}
	if (!hasFoundCar)
		cout << "There's no driver with this license number.\n";
	else if (!hasFoundFine)
		cout << "There are no unpaid fines assigned to this driver.\n";
	else {
		cout << "Enter the number of the fine you would like to pay.\n";
		cin >> fine_choice;
		if (fine_choice <= counter && fine_choice != 0) {
			drivers[updates[fine_choice - 1].which_driver].cars[updates[fine_choice - 1].which_car].fines[updates[fine_choice - 1].which_fine].status = "Paid.";
			drivers[updates[fine_choice - 1].which_driver].total_unpaid -=
			drivers[updates[fine_choice - 1].which_driver].cars[updates[fine_choice - 1].which_car].fines[updates[fine_choice - 1].which_fine].value;
			cout << "Done !\n";
		}
		else
			cout << "Invalid choice !\n";
	}
}
void PayFine() {
	cout << "Would you like to choose a car using:\n1: Owner name ?\n2: Plate number ?\n3: License number ?\n";
	int payment_method;
	cin >> payment_method;
	switch (payment_method) {
	case 1:
		PayByName();
		break;
	case 2:
		PayByPlate();
		break;
	case 3:
		PayByLicense();
		break;
	default:
		cout << "Invalid choice !\n";
	}
}
void SearchByName() {
	cout << "Please enter a name. Make sure you capitalize each new name.\n";
	string name;
	hasFoundCar = false;
	cin.ignore();
	getline(cin, name);
	for (int drivers_counter = 0; drivers_counter < kNumber_of_drivers; drivers_counter++) {
		if (drivers[drivers_counter].name == name) {
			hasFoundCar = true;
			cout << "\tTotal unpaid fines: " << drivers[drivers_counter].total_unpaid << "\n";
			cout << "Driver's birthday: " << drivers[drivers_counter].birthdate.day << '/' << drivers[drivers_counter].birthdate.month << '/' <<
				drivers[drivers_counter].birthdate.year << ",\tDriver's license number: " << drivers[drivers_counter].license_number << ".\n";
			for (int cars_counter = 0; cars_counter < kMax_cars_number; cars_counter++) {
				//because Kmax_cars__number is 3 and the driver may own less cars.
				if (drivers[drivers_counter].cars[cars_counter].plate_number == 0)
					break;
				//to be displayed only once when the cars_counter is equal to zero
				if (!cars_counter)
					cout << "\tList of owned cars\n";
				cout << cars_counter + 1 << ")\n";
				cout << "Car model: " << drivers[drivers_counter].cars[cars_counter].model << ",\tCar plate number: " <<drivers[drivers_counter].
				cars[cars_counter].plate_number << ",\tCar production year: " << drivers[drivers_counter].cars[cars_counter].production_year << ".\n";
				    //there's no need to iterate over kMax fines_number if there isn't any fine assigned
					if (drivers[drivers_counter].cars[cars_counter].fines[0].value == 0) {
						cout << "There are no fines assigned to this car.\n";
						continue;
					}
				for (int fines_counter = 0; fines_counter < kMax_fines_number; fines_counter++) {
					if (drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value != 0) {
						//to be displayed only once when the fines_counter is equal to zero
						if (!fines_counter)
							cout << "\tFines list\n";
						    cout << fines_counter + 1 << ". Value: " << drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value <<
							", \tStatus: " << drivers[drivers_counter].cars[cars_counter].fines[fines_counter].status << "\nIn street: " <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].steet_name << "\nDate: Day)" <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.day << "\tMonth) " <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.month << "\tyear) " <<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.year << "\n";
					}
				}
			}
		}
	}
	if (!hasFoundCar)
		cout << "There is no driver with this name.\n";
}
void SearchByPlateNumber() {
	cout << "Please enter a car plate number.\n";
	cin >> plate_number;
    hasFoundCar = false;
	for (int drivers_counter = 0; drivers_counter < kNumber_of_drivers; drivers_counter++) {
			for (int cars_counter = 0; cars_counter < kMax_cars_number; cars_counter++) {
				if (drivers[drivers_counter].cars[cars_counter].plate_number == plate_number) {
			     hasFoundCar = true;
				 cout << "Driver's name: " << drivers[drivers_counter].name << "\n";
			     cout << "\tTotal unpaid fines: " << drivers[drivers_counter].total_unpaid << "\n";
			     cout << "Driver's birthday: " << drivers[drivers_counter].birthdate.day << '/' << drivers[drivers_counter].birthdate.month << '/' <<
				 drivers[drivers_counter].birthdate.year << ",\tDriver's license number: " << drivers[drivers_counter].license_number << ".\n";
				 cout << "Car model: " << drivers[drivers_counter].cars[cars_counter].model << ",\tCar plate number: " <<drivers[drivers_counter].
				cars[cars_counter].plate_number << ",\tCar production year: " << drivers[drivers_counter].cars[cars_counter].production_year << ".\n";
				//there's no need to iterate over kMax fines_number if there isn't any fine assigned
				if (drivers[drivers_counter].cars[cars_counter].fines[0].value == 0)
					cout << "There are no fines assigned to this car.\n";
				else {
				   for (int fines_counter = 0; fines_counter < kMax_fines_number; fines_counter++) {
					  if (drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value != 0) {
						//to be displayed only once when the fines_counter is equal to zero
						if (!fines_counter)
							cout << "\tFines list\n";
						    cout << fines_counter + 1 << ". Value: " << drivers[drivers_counter].cars[cars_counter].fines[fines_counter].value <<
							",\tStatus: " << drivers[drivers_counter].cars[cars_counter].fines[fines_counter].status << "\nIn street: "<<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].steet_name<<"\nDate: Day)"<<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.day<<"\tMonth) "<<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.month << "\tyear) "<<
							drivers[drivers_counter].cars[cars_counter].fines[fines_counter].date.year<<"\n";
					  }
				    }
				   }
				}
			}
	}
	if (!hasFoundCar)
		cout << "There is no car with this plate number.\n";
}
void ShowInformation() {
	int search_choice;
	cout << "You can search via:\n1: Owner name.\n2: Plate number.\n";
	cin >> search_choice;
	switch (search_choice) {
	case 1:
		SearchByName();
		break;
	case 2:
		  SearchByPlateNumber();
	      break;
	default:
		cout << "Invalid choice !\n";
	}
}
int main() {
	system("color F0");
	SystemData();
	int use_again, service_choice;
	do {
		cout << "\tMain menu\nWhat would you like to do ?\n";
		cout << "1: Assign a fine to a driver.\n2: Pay a fine.\n3: Show all information about a car.\n";
		cin >> service_choice;
		switch (service_choice) {
		case 1:
			AssignFine();
			break;
		case 2:
			PayFine();
			break;
		case 3:
			ShowInformation();
			break;
		default:
			cout << "Invalid choice !\n";
		}
		do {
			cout << "Would you like to go back to the main menu ?\n1: Yes.\n2: No.\n";
			cin >> use_again;
			if (use_again != 1 && use_again != 2)
				cout << "Invalid choice !\n";
		} while (use_again != 1 && use_again != 2);
	} while (use_again == 1);
	return 0;
}