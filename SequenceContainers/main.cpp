//SequenceContainers

#include <iostream> 
#include <array>
using std::cin;
using std::cout;
using std::endl;

#define tab		"\t"

#define STL_ARRAY

unsigned long long Factorial(int number)
{
	if (number < 0)
	{
		//ВОЗЬМЕМ СТАНДАРТНЫЕ ТИПЫ ИСКЛЮЧЕНИЙ
		throw std::invalid_argument("The number cannot be negative!");
	}
	if (number == 0 || number == 1) return 1;
	unsigned long long result = 1;
	result = number * Factorial(number - 1);
	if (result > ULLONG_MAX / number)
	{	// ДЛЯ ULLONG_MAX ФАКТОРИАЛ КОРРЕКТНО ОТОБРАЖАЕТСЯ ДО 20
		// ПРАВИЛЬНЫЙ ТИП ИСКЛЮЧЕНИЯ ДЛЯ ВЫБРОСА — STD::OVERFLOW_ERROR
		throw std::overflow_error("An arithmetic overflow has occurred");
	}
	return result;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//ARRAY
	//throw;
	const int n = 5;
	int f;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size() * 2; i++)
		{
			cout << arr.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cout << "Error: Something went wrong!" << endl;
	}
	try
	{
		cout << "Введите число: "; cin >> f;
		cout << "Факториал " << f << "! = " << Factorial(f) << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cout << "Error: Something went wrong!" << endl;
	}
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
	std::string str;
#endif // STL_ARRAY

}