#pragma once

class Car {
	// attributes are private by default, can't be directly accessed from outside the class
	float fuel{ 0 };
	float speed{ 0 };
	int passengers{ 0 };
	static int totalCount;
	int* int_ptr = new int(0);

public:
	Car();
	~Car();
	Car(float amount);
	Car(float amount, int passengers);
	Car(const Car & otherCar);
	Car(Car&& otherCar);
	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassengers(int passengers);
	void Dashboard() const;
	static void ShowCount();
	int getFuel() const;
	int getPassengers() const;
	void changeIntPtr(int newVal);
	int getIntPtr() const;

	void AddPassengers(float passengers) = delete;
};