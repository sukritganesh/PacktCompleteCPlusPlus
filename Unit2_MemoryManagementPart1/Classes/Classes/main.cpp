#include "car.h"

int main() {
	Car::ShowCount();
	Car car(4);
	car.FillFuel(5);
	car.AddPassengers(2);
	car.Accelerate();
	car.Accelerate();
	car.Accelerate();
	car.Accelerate();
	car.Dashboard();

	const Car c2(10);
	//c2.Accelerate();
	c2.Dashboard();

	Car c3, c4;

	c2.Dashboard();
	c3.Dashboard();

	Car::ShowCount();

	// copy constructor
	Car c5(8);
	Car c6(c5);
	c5.Dashboard();
	c6.Dashboard();

	// CANNOT DO THE FOLLOWING: void addPassengers(float) = delete
	//c6.AddPassengers(56.3f);


	return 0;
}