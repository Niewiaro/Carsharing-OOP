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
[2]   - add new car
[m]   - manual
[ESC] - program end
  )""" << endl;
}

void showAllCars(const std::vector<Car> &cars) {
  // for (const auto& car : cars) 
  //   cout << car << " ";
  cout << "Cars in network:" << endl;
  for (size_t i = 0; i < cars.size(); ++i) {
    cout << i + 1 << ". " << cars[i] << endl;
  }
  cout << endl;
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
  // cars.emplace_back("Seat", 's', 'd');
  unsigned char selectedOption;
  string brand = "";
  char type, driving = '\0';

  do {
        selectedOption = getch();
        if (selectedOption == 'm')
          manual();
        else if (selectedOption == '1')
          showAllCars(cars); 
        else if (selectedOption == '2') {
          cout << "Enter the car brand:" << endl;
          cin >> brand;

          do {
            cout << "Select type:" << endl;
            cout << R"""(
[l] - sedan
[s] - SUV
[h] - hatchback
[c] - cabriolet
[p] - pick-up
            )""" << endl;
            type = getch();
          } while (!(type == 'l' || type == 'L' || type == 's' || type == 'S' || type == 'h' || type == 'H' || type == 'c' || type == 'C' || type == 'p' || type == 'P'));

          do {
            cout << "Select driving:" << endl;
            cout << R"""(
[e] - electric
[d] - diesel
[p] - petrol
            )""" << endl;
            driving = getch();
          } while (!(driving == 'e' || driving == 'E' || driving == 'd' || driving == 'D' || driving == 'p' || driving == 'P'));
          cars.emplace_back(brand, type, driving);
        }
        else 
          cout << "Unkwnon command" << endl;
        cout << endl;
    } while( selectedOption != 27 ); //ESC


  // cout << car;
  // car.driveCar();
  // cout << car;
  // car.startCar();
  // cout << car;
  // car.driveCar();
  // cout << car;
  // car.startCar();
  // cout << car;
  // car.driveCar();
  // cout << car;
  // car.startCar();
  // cout << car;
  return 0;
}
