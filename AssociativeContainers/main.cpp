#include <iostream>
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

template<typename T> void print_map(std::map< T, std::list<T>> cont);
template<typename T> void print_map_range(std::map< T, std::list<T> > cont);

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

template<typename T> void print_map(std::map< T, std::list<T> > cont)
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
template<typename T> void print_map_range(std::map< T, std::list<T> > cont)
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





//﻿//PoliceLoadOptimisation
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<map>
//#include<list>
//#include<algorithm>
//#include<Windows.h>
//
//#include"Crime.h"
//
//using std::cin;
//using std::cout;
//using std::endl;
//
//#define delimiter "\n-----------------------------------------------\n"
//
//void add(std::map<std::string, std::list<Crime>>& base);
//void print(const std::map<std::string, std::list<Crime>>& base);
//void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate);
//void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate);
//void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
//void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename);
//
//void main()
//{
//	//setlocale(LC_ALL, "");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	std::map<std::string, std::list<Crime>> base/* =
//	{
//		{"a777km", {Crime(1, "улица Ленина"), Crime(2, "ул. Фрунзе")}},
//		{"a557ab", {Crime(5, "ул. Космонавтов")}},
//		{"a001a", {Crime(4, "перекресток Ленина и Октябрьской"), Crime(3, "ул. Октябрьская")}}
//	}*/;
//	load(base, "base.txt");
//	load(base, "base.txt");
//	load(base, "base.txt");
//	print(base);
//
//	/*std::string licence_plate;
//	cout << "Введите номер транпортного средства: "; cin >> licence_plate;
//	print(base, licence_plate);*/
//
//	std::string first_plate, last_plate;
//	cout << "Введите начальный номерной знак: "; cin >> first_plate;
//	cout << "Введите конечный номерной знак: "; cin >> last_plate;
//	print(base, first_plate, last_plate);
//	//save(base, "base.txt");
//	//add(base);
//	//print(base);
//}
//
//void add(std::map<std::string, std::list<Crime>>& base)
//{
//	std::string licence_plate;
//	int id;
//	std::string place;
//	cout << "Введите номер автомобиля: "; cin >> licence_plate;
//	cout << "Введите правонарушение (номер статьи): "; cin >> id;
//	cout << "Введите место проишествия: ";
//	cin.clear();
//	cin.ignore();
//	std::getline(cin, place);
//	//base[licence_plate].push_back(Crime(id, place));
//	std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);
//	if (it != base.end())
//	{
//		it->second.push_back(Crime(id, place));
//	}
//	else
//	{
//		base.insert(std::pair<std::string, std::list<Crime>>(licence_plate, { Crime(id, place) }));
//	}
//}
//void print(const std::map<std::string, std::list<Crime>>& base)
//{
//	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
//	{
//		//cout << std::left;
//		cout << it->first + ":\n";
//		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
//		{
//			cout << "\t" << *jt << ";\n";
//		}
//		//cout << "\n-----------------------------------------------\n";
//		cout << delimiter;
//	}
//}
//void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate)
//{
//	try
//	{
//		cout << licence_plate << ":\n";
//		for (
//			std::list<Crime>::const_iterator it = base.at(licence_plate).begin();
//			it != base.at(licence_plate).end();
//			++it
//			)
//			cout << *it << endl;
//	}
//	/*catch (const std::exception& e)
//	{
//		std::cerr << e.what() << endl;
//	}*/
//	catch (...)
//	{
//		std::cerr << "В базе нет такого номера" << endl;
//	}
//}
//void print(std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate)
//{
//	for (
//		std::map<std::string, std::list<Crime>>::iterator it = base.lower_bound(first_plate);
//		it != base.upper_bound(last_plate);
//		++it
//		)
//	{
//		cout << it->first << ":\n";
//		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
//		{
//			cout << *jt << endl;
//		}
//		cout << delimiter;
//	}
//}
//void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
//{
//	std::ofstream fout(filename);
//	for (std::pair<std::string, std::list<Crime>> i : base)
//	{
//		fout << i.first << ":\t";
//		for (Crime j : i.second)
//		{
//			fout << j << ", ";
//		}
//		fout.seekp(-2, std::ios::cur);	//сдвигаем курсор на 2 позиции влево
//		fout << ";\n";
//	}
//	fout.close();
//	std::string command = std::string("start notepad ") + filename;
//	system(command.c_str());
//	//c_str() возвращает C-string (NULL Terminated Line)
//}
//void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename)
//{
//	std::ifstream fin(filename);
//	if (fin.is_open())
//	{
//		while (!fin.eof())
//		{
//			std::string licence_plate;
//			int id;
//			std::string place;
//			std::string crimes;
//			std::getline(fin, licence_plate, ':');
//			std::getline(fin, crimes);
//			if (crimes.empty())continue;
//
//			/*if (crimes.find(',') != std::string::npos)
//			{
//				for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
//				{
//					end = crimes.find(',', start + 1);
//					place = crimes.substr(start + 1, end);//TODO: проверить с большим количеством нарушений
//					//https://www.cplusplus.com/reference/string/string/substr/
//					place.erase(0, place.find_first_not_of(' '));
//					id = std::stoi(place.substr(0, place.find_first_of(' ')));
//					place.erase(0, place.find_first_of(' ') + 1);
//					base[licence_plate].push_back(Crime(id, place));
//				}
//			}
//			else
//			{
//				id = std::stoi(crimes.substr(0, crimes.find_first_of(' ')));
//				crimes.erase(0, crimes.find_first_of(' '));
//				base[licence_plate].push_back(Crime(id, crimes));
//			}*/
//
//			char* sz_crimes = new char[crimes.size() + 1] {};
//			std::strcpy(sz_crimes, crimes.c_str());
//			char sz_delimiters[] = ",;";
//			for (char* pch = strtok(sz_crimes, sz_delimiters); pch; pch = strtok(NULL, sz_delimiters))
//			{
//				//atoi() - ASCII-string to int
//				while (*pch == ' ')pch++;//Пока строка начинается с символа ' ', смещаем начало строки на 1 символ враво.
//				id = std::atoi(pch);	 //Берем номер правонарушения, преобразуем его в целочисленный формат (int), и сохраняем в id.
//				pch = std::strchr(pch, ' ') + 1;//Для того чтобы убрать id из строки, находим первый пробел в строке, 
//				//и смещаем начало строки на символ, следующий за пробелом.
//				/*if (
//					std::find(base.at(licence_plate).begin(), base.at(licence_plate).end(), Crime(id, pch))
//					== base.at(licence_plate).end()
//					)*/
//				if
//					(
//						std::find
//						(
//							base[licence_plate].begin(),
//							base[licence_plate].end(),
//							Crime(id, pch)
//						) == base[licence_plate].end()
//						)
//					base[licence_plate].push_back(Crime(id, pch));
//			}
//			delete[] sz_crimes;
//		}
//		fin.close();
//	}
//	else
//	{
//		std::cerr << "Error: file not found" << endl;
//	}
//}
