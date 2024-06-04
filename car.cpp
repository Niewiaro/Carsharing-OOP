#pragma hdrstop
#include "car.h"
#include <iostream>
using namespace std;

void blink(int amount) {
    for(int i= 0; i< amount; i++){
        cout << "blink ";
    }
    cout << endl;
}

int Car::amountActive= 0;
int Car::amountOnline= 0;
int Car::amountDriving= 0;
long long int Car::startSerialNumber= 99999999999;

int Car::getAmountOfActiveCars() {
  return amountActive;
}

int Car::getAmountOfOnlineCars() {
  return amountOnline;
}

int Car::getAmountOfDrivingCars() {
  return amountDriving;
}

Car::Car(string brand, char type, char driving): brand(brand), type(type), driving(driving), serialNumber( ++startSerialNumber ) {
    start= false;
    drive= false;

    amountActive++;
}

bool Car::startCar() {
    if( !drive ) {
        if( start ) {
            start= false;
            blink(1);
            amountOnline--;
            return true;
        }

        start= true;
        blink(2);
        amountOnline++;
        return true;
    }
    return false;
}

bool Car::driveCar() {
    if( start ) {
        if( drive ) {
            drive= false;
            amountDriving++;
            return true;
        }

        amountDriving--;
        drive= true;
        return true;
    }
    return false;
}

string decodeDriving(char c) {
    if( c == 'e' )
        return "electric";
    else if( c == 'd' )
        return "diesel";
    else if( c == 'p' )
        return "petrol";
    return "undefined";
}

string decodeType(char c) {
    if( c == 'l' )
        return "sedan";
    else if( c == 's' )
        return "SUV";
    else if( c == 'h' )
        return "hatchback";
    else if( c == 'c' )
        return "cabriolet";
    else if( c == 'p' )
        return "pick-up";
    return "undefined";
}

// void Car::info() {
//     cout << decodeDriving(driving) << " " << decodeType(type) << " " << brand << "\t\twith SN: " << serialNumber << "\t\tis now:" << endl;
//     if( start ) {
//         cout << "\tonline";

//         if( drive ) {
//             cout << ", driving";
//         } else {
//             cout << ", not driving";
//         }
//     } else {
//         cout << "\toffline";
//     }
//     cout << "." << endl;
// }

ostream& operator<<(ostream &os, const Car &car) {
    os << decodeDriving(car.driving) << " " << decodeType(car.type) << " " << car.brand << "\t\twith SN: " << car.serialNumber << "\t\tis now:" << endl;
    if( car.start ) {
        os << "\tonline";

        if( car.drive ) {
            os << ", driving";
        } else {
            os << ", not driving";
        }
    } else {
        os << "\toffline";
    }
    os << "." << endl;
    return os;
}

#pragma package( smart_init )
