#include <iostream>
#include "car.h"
#include "car_art.h"
#include <windows.h>

using namespace std;

string manual() {
  return R"""(
Next-Gen Car Sharing API
  )""";
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
  cout << manual() << endl;

  Car car("Seat", 's', 'd');
  car.info();
  car.driveCar();
  car.info();
  car.startCar();
  car.info();
  car.driveCar();
  car.info();
  car.startCar();
  car.info();
  car.driveCar();
  car.info();
  car.startCar();
  car.info();
  return 0;
}
