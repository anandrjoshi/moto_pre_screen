#include <iostream>

using namespace std;

class Vehicle
{
      public:
      virtual void drive()
      {
              cout << "vehicle driving..." << endl;
      }
};

class Car : public Vehicle
{
      public:
      void drive()
      {
           cout << "car driving..." << endl;
      }
};

class Truck : public Vehicle
{
      public:
      void drive()
      {
           cout << "truck driving..." << endl;
      }
};      

void call_drive(Vehicle* vehicle)
{
     vehicle->drive();
}

int main()
{
    Vehicle* vehicle = new Vehicle();
    call_drive(vehicle);
    Car car;
    vehicle = &car;
    call_drive(vehicle);    
    Truck truck;
    vehicle = &truck;
    call_drive(vehicle);

    system("pause"); 
    delete vehicle;
    return 0;
}
