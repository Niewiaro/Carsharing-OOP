#include <conio.h>
#include <windows.h>

#include <iostream>
#include <vector>

#include "car.h"
#include "car_art.h"

using namespace std;

void manual() {
    cout << R"""(
Next-Gen Car Sharing API
This is terminal to manage all cars in your Next-Gen Car Sharing network.
Press one of below key to perform action:

[1]   - show all cars
[2]   - show selected car
[3]   - select car
[4]   - add new car
[0]   - remove all cars
[m]   - manual
[ESC] - program end
  )""" << endl;
}

void showAllCars(const std::vector<Car> &cars) {
    // for (const auto& car : cars)
    //   cout << car << " ";
    if (cars.size() == 0)
        cout << "Car network is empty" << endl;
    else {
        cout << "Cars in network:" << endl;
        for (size_t i = 0; i < cars.size(); ++i) 
            cout << i + 1 << ". " << cars[i] << endl;
        
        cout << endl;
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
    string brand = "";
    char type, driving, ch = '\0';
    int carIndex = 0;

    do {
        selectedOption = getch();
        if (selectedOption == 'm')
            manual();
        else if (selectedOption == '1')
            showAllCars(cars);
        else if (selectedOption == '2') {
            if (cars.size() > 0) {
                cout << "Enter the car index:" << endl;
                cin >> carIndex;
                if (carIndex > 0 && carIndex <= cars.size()) 
                    cout << cars[carIndex - 1] << endl;
                else 
                    cout << "Invalid index" << endl;
                
            } else 
                cout << "Car network is empty." << endl;
            
        } else if (selectedOption == '3') {
            if (cars.size() > 0) {
                cout << "Enter the car index:" << endl;
                cin >> carIndex;
                if (carIndex > 0 && carIndex <= cars.size()) {
                    cout << cars[carIndex - 1] << endl;

                    do {
                        cout << "Select type:" << endl;
                        cout << R"""(
[p] - power
[d] - drive
                        )""" << endl;
                        ch = getch();
                        if (ch == 27) {
                            cout << "\nOperation canceled." << endl << endl;
                            break;
                        }
                    } while (!(ch == 'p' || ch == 'P' || ch == 'd' ||
                            ch == 'D'));

                    if (ch == 27) 
                        continue; 
                    else if (ch == 'p')
                        cars[carIndex - 1].startCar();
                    else if (ch == 'd')
                        cars[carIndex - 1].driveCar();
                } else 
                    cout << "Invalid index" << endl;
                
            } else 
                cout << "Car network is empty." << endl;
            
        } else if (selectedOption == '4') {
            cout << "Enter the car brand (press ESC to cancel):" << endl;

            brand.clear();
            while ((ch = getch()) != 27) {
                if (ch == '\r') {
                    cout << endl;
                    break;
                }
                cout << ch;
                brand += ch;
            }
            if (ch == 27) {  
                cout << "\nOperation canceled." << endl << endl;
                continue; 
            }

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
                if (type == 27) {
                    cout << "\nOperation canceled." << endl << endl;
                    break;
                }
            } while (!(type == 'l' || type == 'L' || type == 's' ||
                       type == 'S' || type == 'h' || type == 'H' ||
                       type == 'c' || type == 'C' || type == 'p' ||
                       type == 'P'));

            if (type == 27) 
                continue; 

            do {
                cout << "Select driving:" << endl;
                cout << R"""(
[e] - electric
[d] - diesel
[p] - petrol
        )""" << endl;
                driving = getch();
                if (driving == 27) {  
                    cout << "\nOperation canceled." << endl << endl;
                    break;
                }
            } while (!(driving == 'e' || driving == 'E' || driving == 'd' ||
                       driving == 'D' || driving == 'p' || driving == 'P'));

            if (driving == 27) 
                continue;     

            cars.emplace_back(brand, type, driving);
        } else if (selectedOption == '0') {
            if (cars.size() > 0) 
                cars.clear();
            else 
                cout << "Car network is empty." << endl;
        }

        else
            cout << "Unkwnon command" << endl;
        cout << endl;
    } while (selectedOption != 27);  // ESC

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
