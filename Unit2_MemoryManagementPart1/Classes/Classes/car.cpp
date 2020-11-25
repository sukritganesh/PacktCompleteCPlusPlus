#include "car.h"
#include <iostream>

int Car::totalCount{ 0 };

Car::Car():Car(0)
{
}

Car::~Car()
{
	--totalCount;
	delete int_ptr;
	std::cout << "~Car()" << std::endl;
}

Car::Car(float amount):Car(amount, 0)
{
}

Car::Car(float amount, int passengers)
{
	std::cout << "Car()" << std::endl;
	++totalCount;
	fuel = amount;
	this->passengers = passengers;
}

Car::Car(const Car & otherCar)
{
	++totalCount;
	this->fuel = otherCar.fuel;
	this->speed = otherCar.speed;
	this->passengers = otherCar.passengers;
	int_ptr = new int(*otherCar.int_ptr);
}

void Car::FillFuel(float amount)
{
	fuel = amount;
}

void Car::Accelerate()
{
	speed++;
	fuel -= 0.5f;
}

void Car::Brake()
{
	speed = 0;
}

void Car::AddPassengers(int passengers)
{
	this->passengers = passengers;
}

void Car::Dashboard() const
{
	std::cout << "Fuel: " << fuel << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Passengers: " << passengers << std::endl;
	std::cout << "Total Cars: " << totalCount << std::endl;
}

void Car::ShowCount()
{
	std::cout << "Total Cars: " << totalCount << std::endl;
}

void Car::changeIntPtr(int newVal)
{
	*int_ptr = newVal;
}

int Car::getIntPtr()
{
	return *int_ptr;
}
