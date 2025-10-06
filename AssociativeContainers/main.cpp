#include <iostream>
#include<fstream>
#include <string>
#include <map>
#include <list>
using namespace std;
using  std::cin;
using  std::cout;
using  std::endl;

#define tab			 "\t"
#define delimiter	 "\n-----------------------------------------------------\n"

#define STL_MAP

template<typename T> void print_map(std::map< T, std::list<T>>& cont);
template<typename T> void print_map_range(std::map< T, std::list<T>>& cont);

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_MAP
	std::multimap<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Воскресенье"),
		std::pair<int, std::string>(1, "Понедельник"),
		std::pair<int, std::string>(2, "Вторник"),
		std::pair<int, std::string>(3, "Среда"),
		{4, "Четверг"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{6, "Суббота"},
		{7, "Воскресенье"}
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << delimiter;
	for (std::pair<int, std::string> i : week)
	{
		cout << i.first << tab << i.second << endl;
	}
	cout << delimiter;
	std::map<std::string, std::list<std::string>> dictionary = 
	{
			{"occasionaly", {"Иногда", "Время от времени", "Случайно", "Изредка"}},
			{"causes",{"Причина", "Приводить к..."}},
			{"space", {"Космос", "Пространство", "Пробел"}},
			{"void", {"Пустота", "Вакуум"}},
			{"sequence", {"Последовательность", "Ряд", "Эпизод", "Череда"}},
			{"consequence", {"Последствие", "Вывод", "Следствие"}}
	};
	print_map(dictionary);
	cout << endl;
	print_map_range(dictionary);
	cout << endl;
	
#endif // STL_MAP
}

template<typename T> void print_map(std::map< T, std::list<T>>& cont)
{
	for (typename std::map<T, std::list<T>>::iterator it = cont.begin(); it != cont.end(); ++it)
	{
		cout.width(15);
		cout << it->first << ":" << tab;
		for (typename std::list<T>::iterator sec_it = it->second.begin(); sec_it != it->second.end(); ++sec_it)
			cout << *sec_it << ", ";
		cout << endl;
	}
}
template<typename T> void print_map_range(std::map< T, std::list<T>>& cont)
{
	for (std::pair< T, std::list<T> > it : cont)
	{
		cout.width(15);
		cout << it.first << ":" << tab;
		for (T sec_it : it.second) cout << sec_it << ", ";
		cout << endl;
	}
}






//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string>
//#include <map>
//#include <vector>
//
//using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;
//
//#define tab				"\t"
//#define delimiter		"\n-------------------------------------------------------\n"
//
////#define STRING
////#define MAP
//#define MULTIMAP
//
//template<typename container> void show(container col);
//
//void main()
//{
//	setlocale(LC_ALL, "");
//#ifdef STRING
//	string str = "Hello world";
//	int nWordEnd = str.find(' ');
//	string sub_string = str.substr(0, nWordEnd);
//
//	cout << "String: " << str.c_str() << endl;
//	cout << "Sub string: " << sub_string.c_str() << endl;
//	cout << endl;
//	printf("String: %s\n", str.c_str());
//	printf("Sub string: %s\n", sub_string.c_str());
//	cout << endl;
//#endif // 
//
//#ifdef MAP
//	map<int, int> our_map;
//	vector<int> our_vector;
//
//	cout << "\n\nmax size of vector --> " << our_vector.max_size() / sizeof(int);
//	cout << "\n\nmax size of map -->" << our_map.max_size() / sizeof(int);
//	cout << delimiter;
//
//	int val;
//	int key;
//	cout << "\nВведите значение: "; cin >> val;
//	cout << "\nВведите ключ: "; cin >> key;
//
//	pair<int, int> element(key, val);
//	our_map.insert(element);
//
//	cout << "\nCurrent element of map --> " << our_map.size();
//	cout << delimiter;
//
//	cout << "\nВведите значение: "; cin >> val;
//	cout << "\nВведите ключ: "; cin >> key;
//
//	pair <map<int, int>::iterator, bool> err = our_map.insert(make_pair(key, val));
//	if (err.second == false)
//	{
//		///отработает, если уже был элемент с данным ключом
//		cout << "\nError!!!!\n";
//	}
//	cout << "\nCurrent element of map --> " << our_map.size();
//	cout << delimiter;
//#endif // MAP
//
//#ifdef MULTIMAP
//	cout << "map\n\n";
//	//отображение
//	map<string, int> cont;
//	//мультиотображение
//	multimap<string, int> multicont;
//
//	cont.insert(pair<string, int>("Ivanov", 10));
//	cont.insert(pair<string, int>("Petrov", 20));
//	show(cont);
//	cout << delimiter;
//	cont["Sidorov"] = 50;
//	show(cont);
//	cont.insert(pair<string, int>("Ivanov", 100));
//	show(cont);
//	cout << delimiter;
//	multicont.insert(pair<string, int>("Ivanov", 10));
//	multicont.insert(pair<string, int>("Petrov", 20));
//	multicont.insert(pair<string, int>("Sidorov", 20));
//	multicont.insert(pair<string, int>("Pupkin", 30));
//	show(multicont);
//	cout << delimiter;
//	multicont.insert(pair<string, int>("Ivanov", 100));
//	show(multicont);
//	cout << delimiter;
//	multimap<string, int>::iterator it = multicont.find("Petrov");
//	cout << it->first << tab << it->second << endl;
//	cout << delimiter;
//
//	cout << "Count of key Ivanov in multimap = " << multicont.count("Ivanov") << endl;
//	it = multicont.lower_bound("Ivanov");
//	for (; it != multicont.upper_bound("Ivanov") && it != multicont.end(); it++)
//	{
//		cout << it->first << tab << it->second << endl;
//	}
//
//#endif // MULTIMAP
//
//}
//
//
//template<typename container> void show(container col)
//{
//	for (typename container::const_iterator i = col.begin(); i != col.end(); ++i)
//	{
//		cout << i->first << tab << i->second << endl;
//	}
//	cout << endl << endl;
//}
