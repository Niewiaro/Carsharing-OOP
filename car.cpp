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
const char Car::type= '\b';
const char Car::driving= '\b';

int Car::getAmountOfActiveCars() {
  return amountActive;
}

int Car::getAmountOfOnlineCars() {
  return amountOnline;
}

int Car::getAmountOfDrivingCars() {
  return amountDriving;
}

Car::Car(string brand): brand(brand), serialNumber( ++startSerialNumber ) {
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

void Car::info() {
    cout << driving << " " << type << "\t\twith SN: " << serialNumber << "\t\tis now:" << endl;
    if( start ) {
        cout << "\tonline";

        if( drive ) {
            cout << ", driving";
        } else {
            cout << ", not driving";
        }
    } else {
        cout << "offline";
    }
    cout << "." << endl;
}

#pragma package( smart_init )
