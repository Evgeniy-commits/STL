//SequenceContainers

#include <iostream> 
#include <array>
#include <vector>
#include <list>
using std::cin;
using std::cout;
using std::endl;

#define tab		"\t"
#define delimiter		"\n-------------------------------------------------------\n"

template<typename T> void vector_info(const std::vector<T>& vec);
template<typename T> void list_print(const std::list<T>& list);
template<typename T> void insert(T& value, int index, std::list<T>& list);
template<typename T> void erase(int index, std::list<T>& list);

template<typename T> class TList : public std::list<T>
{
public:
	void list_print()
	{
		for (const T& i : *this)
		{
			std::cout << i << tab;
		}
		std::cout << std::endl;
	}
};

//#define STL_ARRAY
//#define STL_VECTOR
#define STL_LIST
//#define STL_LIST_CLASS

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

#ifdef STL_VECTOR

	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << tab;
	cout << endl;
	vector_info(vec);
	//vec.shrink_to_fit();
	//vec.reserve(16);
	//vec.resize(18);
	for (int i : vec) cout << i << tab;
	cout << endl;
	vector_info(vec);
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	cout << vec.data() << endl;
	cout << delimiter << endl;
	//int index;
	//int value;
	//cout << "Введите индекс доб. элемента: "; cin >> index;
	//cout << "Введите значение доб. элемента: "; cin >> value;
	//vec.insert(vec.begin() + index, value);
	//for (int i : vec) cout << i << tab;
	//cout << endl;
	int index;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	vec.erase(vec.begin() + index);
	for (int i : vec) cout << i << tab;
	cout << endl;
#endif // STL_VECTOR

#ifdef STL_LIST
	std::list<int> list1 = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
	/*for (const int& i : list) cout << i << tab;
	cout << endl;*/
	for (int i : list1) cout << i << tab;
	cout << endl;
	cout << delimiter << endl;

	for (std::list<int>::const_iterator it = list1.cbegin(); it != list1.cend(); ++it)
		cout << *it << tab;
	cout << endl;
	cout << delimiter << endl;

	for (std::list<int>::const_reverse_iterator it = list1.crbegin(); it != list1.crend(); ++it)
		cout << *it << tab;
	cout << endl;
	cout << delimiter << endl;

	list_print(list1);
	cout << endl;
	cout << delimiter << endl;

	cout << list1.size();
	cout << endl;
	int index;
	int value;
	cout << "Введите индекс доб. элемента: "; cin >> index;
	cout << "Введите значение доб. элемента: "; cin >> value;

	/*std::list<int>::iterator it_list = list1.begin();
	std::advance(it_list, index);
	list1.insert(it_list, value);
	cout << list1.size();
	cout << endl;
	list_print(list1);
	cout << endl;
	cout << delimiter << endl;*/

	try
	{
		insert(value, index, list1);
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n" << e.what() << "\n" << endl;
	}
	cout << list1.size();
	cout << endl;
	list_print(list1);
	cout << endl;
	cout << delimiter << endl;

	int index;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	
	/*std::list<int>::iterator it_list = list1.begin();
	std::advance(it_list, index);
	list1.erase(it_list);
	cout << list1.size();
	cout << endl;
	list_print(list1);
	cout << endl;
	cout << delimiter << endl;*/

	try
	{
		erase(index, list1);
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n" << e.what() << "\n" << endl;
	}
	cout << list1.size();
	cout << endl;
	list_print(list1);
	cout << endl;
	cout << delimiter << endl;

#endif // STL_LIST

#ifdef STL_LIST_CLASS
	int n;
	cout << "Введите размер списка: "; cin >> n;
	TList<int> list1;
	for (int i = 0; i < n; i++)
	{
		list1.push_back(rand() % 100);
	}
	list1.list_print();
#endif // STL_LIST_CLASS

}

template<typename T> void insert(T& value, int index, std::list<T>& list)
{
	if (index > list.size() - 1 || index < 0)
	{
		throw std::out_of_range("THE VALUE IS OUT OF RANGE");
	}
	if(list.empty()) 
	{
		list.push_front(value);
		return;
	}
	if (index <= list.size()/2)
	{
		typename std::list<T>::iterator it_list = list.begin();
		list.insert(it_list, value);
	}
	else
	{
		/*typename std::list<T>::reverse_iterator it_rlist = list.rbegin();
		typename std::list<T>::iterator it_list = it_rlist.base();
		std::advance(it_list, int(index - list.size()));
		list.insert(it_list, value);*/
		typename std::list<T>::iterator it_list = list.end();
		std::advance(it_list, int(index - list.size()));
		list.insert(it_list, value);
	}
}

template<typename T> void erase(int index, std::list<T>& list)
{
	if (index > list.size() - 1 || index < 0)
	{
		throw std::out_of_range("THE VALUE IS OUT OF RANGE");
	}
	if (list.empty()) return;
	if (index <= list.size() / 2)
	{
		typename std::list<T>::iterator it_list = list.begin();
		list.erase(it_list);
	}
	else
	{
		/*typename std::list<T>::reverse_iterator it_rlist = list.rbegin();
		typename std::list<T>::iterator it_list = it_rlist.base();
		std::advance(it_list, int(index - list.size()));
		list.erase(it_list);*/
		typename std::list<T>::iterator it_list = list.end();
		std::advance(it_list, int(index - list.size()));
		list.erase(it_list);
	}
}

template<typename T> void list_print(const std::list<T>& list)
{
	for (typename std::list<T>::const_iterator it = list.cbegin(); it != list.cend(); ++it)
		cout << *it << tab;
	cout << endl;
}

template<typename T> void vector_info(const std::vector<T>& vec)
{
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << delimiter << endl;
}