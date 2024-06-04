#include <iostream>
#include "car.h"
#include "car_art.h"
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

void manual() {
  cout << R"""(
Next-Gen Car Sharing API

[1]   - show all cars
[m]   - manual
[ESC] - program end
  )""" << endl;
}

void showAllCars(const std::vector<Car> &cars) {
  for (const auto& car : cars) {
    cout << car << " ";
  }
}

void SetColor(int textColor, int bgColor) {
    int color = (bgColor << 4) | textColor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
  SetColor(1, 0);
  cout << SUBARU_IMPREZA << endl;
  SetColor(0, 4);
  cout << "Copyright C @Niewiaro 2024" << endl;
  SetColor(7, 0);
  manual();

  vector<Car> cars;
  unsigned char selectedOption;
  do
    {
        selectedOption = getch();
        if (selectedOption == 'm')
          manual();
        if (selectedOption == '1')
          showAllCars(cars); 
        cout << endl;
    } while( selectedOption != 27 ); //ESC


  Car car("Seat", 's', 'd');
  cout << car;
  car.driveCar();
  cout << car;
  car.startCar();
  cout << car;
  car.driveCar();
  cout << car;
  car.startCar();
  cout << car;
  car.driveCar();
  cout << car;
  car.startCar();
  cout << car;
  return 0;
}
