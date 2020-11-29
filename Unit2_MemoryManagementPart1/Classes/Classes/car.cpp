#include "car.h"
#include <iostream>

int Car::totalCount{ 0 };

Car::Car():Car(0)
{
	std::cout << "Car()" << std::endl;
}

Car::Car(float amount):Car(amount, 0)
{
	std::cout << "Car(float amount)" << std::endl;
}

Car::Car(float amount, int passengers)
{
	std::cout << "Car(float amount, int passengers)" << std::endl;
	++totalCount;
	fuel = amount;
	this->passengers = passengers;
}

// copy constructor
Car::Car(const Car & otherCar)
{
	std::cout << "Car(const Car & otherCar)" << std::endl;
	++totalCount;
	this->fuel = otherCar.fuel;
	this->speed = otherCar.speed;
	this->passengers = otherCar.passengers;
	int_ptr = new int(*otherCar.int_ptr);
}

// move constructor
Car::Car(Car&& otherCar)
{
	// move semantics: shallow copy, then destroy other object
	std::cout << "Car(Car && otherCar)" << std::endl;
	++totalCount;
	this->fuel = otherCar.fuel;
	this->speed = otherCar.speed;
	this->passengers = otherCar.passengers;
	int_ptr = otherCar.int_ptr;
	otherCar.int_ptr = nullptr;
}

Car::~Car()
{
	--totalCount;
	delete int_ptr;
	std::cout << "~Car()" << std::endl;
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

int Car::getFuel() const
{
	return fuel;
}

int Car::getPassengers() const
{
	return passengers;
}

void Car::changeIntPtr(int newVal)
{
	*int_ptr = newVal;
}

int Car::getIntPtr() const
{
	return *int_ptr;
}
