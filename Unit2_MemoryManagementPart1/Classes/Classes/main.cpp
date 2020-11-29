#include "car.h"
#include <iostream>

Car combineCars(const Car& c1, const Car& c2) {
	//Car temp;
	//temp.AddPassengers(c1.getPassengers() + c2.getPassengers());
	//return temp;
	return Car(c1.getFuel()+ c2.getFuel(), c1.getPassengers() + c2.getPassengers());
}

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
	std::cout << "Copy constructor: " << std::endl;
	Car c5(8, 3);
	Car c6(c5);
	c5.Dashboard();
	c6.Dashboard();

	// CANNOT DO THE FOLLOWING: void addPassengers(float) = delete
	//c6.AddPassengers(56.3f);

	// Move semantics
	std::cout << "Move semantics: " << std::endl;
	Car c7;
	c7.AddPassengers(combineCars(c5, c6).getPassengers());

	// Copy elision
	std::cout << "Copy elision: " << std::endl;
	Car c8 = combineCars(c5, c6);
	c8.Dashboard();

	// std::move (so that copy is not made)
	std::cout << "std::move: " << std::endl;
	Car c9(std::move(c8));
	// c8 cannot be used properly again (as the int_ptr variable becomes nullptr)
	// std::cout << c8.getIntPtr() << std::endl;
	c9.Dashboard();


	return 0;
}