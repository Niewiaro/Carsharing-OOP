#ifndef carH
#define carH

#include <string>

class Car {
public:
    Car(std::string, char, char);
    ~Car();
    bool startCar();
    bool driveCar();
    // void info();
    virtual inline void makeSound();
    static int getAmountOfActiveCars();
    static int getAmountOfOnlineCars();
    static int getAmountOfDrivingCars();
    const long long int serialNumber;

    friend std::ostream& operator<<(std::ostream &os, const Car &car);

protected:
    const std::string brand;
    static int amountActive;
    static int amountOnline;
    static int amountDriving;
    static long long int startSerialNumber;
    bool start;
    bool drive;

    const char type;
    const char driving;
};

inline void Car::makeSound() {
    printf("\b");
}

#endif
