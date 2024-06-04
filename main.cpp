#include <iostream>
#include "car.h"
#include "car_art.h"
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

string manual() {
  return R"""(
Next-Gen Car Sharing API

[m]   - manual
[ESC] - program end
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

  unsigned char selectedOption;
  do
    {
        selectedOption = getch();
        if (selectedOption == 'm')
          cout << manual() << endl;
        cout << endl;
    } while( selectedOption != 27 ); //ESC

  vector<Car> cars;

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
