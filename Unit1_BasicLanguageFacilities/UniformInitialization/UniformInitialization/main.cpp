#include <iostream>

int main() {

	// primitive data types
	// numbers automatically initialized to 0

	int intDefault{};
	int num1{ 2 };
	int num2{ 0 };
	float floatDefault{};
	float f1{ 1.5f };
	double doubleDefault{};
	double d1{ -0.554 };
	char charDefault{};
	char c1{ 'b' };
	std::string strDefault{};
	std::string mystr{ "Hello World" };

	// uniform initialization also works with arrays
	// no need to provide all array values initially
	int arrIntDefault[5]{};	// array of size 5, all values are 0
	int arr1[5]{ 1, 2, 3 };
	char arrCharDefault[8]{};
	char arr2[6]{ "hello" };		// string length must be 1 less than array length
	char arr3[6]{ "bye" };	
	char arr4[6]{ 'a', 'b', 'c', 'd', 'e', 'f' };
	std::string arr5[5]{};
	std::string arr6[5]{ "space" };
	std::string arr7[5]{ "space", "time" };

	std::cout << "Int Default: " << intDefault << std::endl;
	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl << std::endl;

	std::cout << "Float Default: " << floatDefault << std::endl;
	std::cout << f1 << std::endl << std::endl;

	std::cout << "Double Default: " << doubleDefault << std::endl;
	std::cout << d1 << std::endl << std::endl;

	std::cout << "Char Default: " << "|" << charDefault << "|" << std::endl;
	std::cout << c1 << std::endl << std::endl;

	std::cout << "String Default: " << strDefault << std::endl;
	std::cout << mystr << std::endl << std::endl;

	std::cout << "Int Array Default: " << arrIntDefault[0] << arrIntDefault[1] << arrIntDefault[2] << arrIntDefault[3] << arrIntDefault[4] << std::endl;
	std::cout << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << std::endl << std::endl;

	std::cout << "Char Array Default: " << arrCharDefault[0] << arrCharDefault[1] << arrCharDefault[2] << arrCharDefault[3] << arrCharDefault[4] << arrCharDefault[5] << std::endl;
	std::cout << arr2[0] << arr2[1] << arr2[2] << arr2[3] << arr2[4] << arr2[5] << std::endl;
	std::cout << arr3[0] << arr3[1] << arr3[2] << arr3[3] << arr3[4] << arr3[5] << std::endl;
	std::cout << arr4[0] << arr4[1] << arr4[2] << arr4[3] << arr4[4] << arr4[5] << std::endl << std::endl;

	std::cout << "String Array Default: " << arr5[0] << arr5[1] << arr5[2] << arr5[3] << arr5[4] << std::endl;
	std::cout << arr6[0] << arr6[1] << arr6[2] << arr6[3] << arr6[4] << std::endl;
	std::cout << arr7[0] << arr7[1] << arr7[2] << arr7[3] << arr7[4] << std::endl;


}