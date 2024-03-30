#ifndef carH
#define carH

#include <string>

class Car {
public:
    Car(std::string);
    bool startCar();
    bool driveCar();
    void info();
    virtual inline void makeSound();
    static int getAmountOfActiveCars();
    static int getAmountOfOnlineCars();
    static int getAmountOfDrivingCars();
    const long long int serialNumber;

protected:
    const std::string brand;
    static int amountActive;
    static int amountOnline;
    static int amountDriving;
    static long long int startSerialNumber;
    bool start;
    bool drive;

    static const char type;
    static const char driving;
};

inline void Car::makeSound() {
    printf("\b");
}

#endif
