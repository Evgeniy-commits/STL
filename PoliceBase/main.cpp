#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <map>

using namespace std;

#define tab			 "\t"
#define delimiter	 "\n-----------------------------------------------------\n"



class Offense;
void print_base(const std::map<std::string, std::list<Offense>>& cont);
void add_to_list(std::map<std::string, std::list<Offense>>& cont);

class Offense
{
	std::string protocol;
	std::string offenseName;
	std::string addressOffense;
public:
	std::string get_num_prot() const
	{
		return protocol;
	}
	std::string get_offense_name() const
	{
		return offenseName;
	}
	std::string get_address() const
	{
		return addressOffense;
	}
	Offense(const std::string& protocol, const std::string& offenseName, const std::string& addressOffense) : protocol(protocol), offenseName(offenseName), addressOffense(addressOffense) {}
	~Offense() {};
	friend std::ostream& operator<<(std::ostream& os, const Offense& obj);
};

std::ostream& operator<<(std::ostream& os, const Offense& obj)
{
	return os << obj.get_num_prot() << tab << obj.get_offense_name() << tab << obj.get_address() << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");

	std::map<std::string, std::list<Offense>> base =
	{
			{"b007nd", {Offense("AP0004", "драка с полицейским", "пр. Ћенина 69"), Offense("AP0002", "проезд на красный", "ул. Ёнтузиастов")}},
			{"a123nc", {Offense("AP0001", "превышение скорости", "пр. Ћенина 69"), Offense("AP0003", "пересечение сплошной", "ул. Ёнтузиастов")}}
	};
	print_base(base);
	cout << endl;
	add_to_list(base);
	print_base(base);
	cout << endl;

}

void print_base(const std::map< std::string, std::list<Offense>>& cont)
{
	for (std::map< std::string, std::list<Offense>>::const_iterator it = cont.begin(); it != cont.end(); ++it)
	{
		cout.width(15);
		cout << it->first << ":" << tab;
		for (std::list<Offense>::const_iterator sec_it = it->second.begin(); sec_it != it->second.end(); ++sec_it)
		{
			cout.width(15);
			cout << *sec_it << tab;
		}
		cout << endl;
	}
}

void add_to_list (std::map<std::string, std::list<Offense>>& cont)
{
	std::string number_automobile;
	std::string protocol;
	std::string offenseName;
	std::string addressOffense;
	cout << "¬ведите номер автомобил€: "; cin >> number_automobile;
	cout << "¬ведите номер административного правонарушени€: "; cin >> protocol;
	cout << "Ќазвание правонарушени€: ";
	cin.clear();
	cin.ignore();
	std::getline(cin, offenseName);
	cout << "¬ведите место проишестви€: ";
	cin.clear();
	cin.ignore();
	std::getline(cin, addressOffense);
	cont[number_automobile].push_back(Offense(protocol, offenseName, addressOffense));
}

//class FileOpen
//{
//	FILE* f;
//public:
//	FileOpen(char* filename, char* mode)
//	{
//		if (!(f = fopen(filename, mode)))
//		{
//			14
//				 ласс auto_ptr
//				exit(0);
//		}
//	}
//	~FileOpen() {
//		fclose(f);
//	}
//};
// }
// void f() {
//	 FileOpen MyFile("test.txt", "r+");
//	 //здесь выполн€ем нужную работу с файлом
//	 ƒл€ усовершенствовани€ нашего принципа мы мож

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
//	cout << "\n¬ведите значение: "; cin >> val;
//	cout << "\n¬ведите ключ: "; cin >> key;
//
//	pair<int, int> element(key, val);
//	our_map.insert(element);
//
//	cout << "\nCurrent element of map --> " << our_map.size();
//	cout << delimiter;
//
//	cout << "\n¬ведите значение: "; cin >> val;
//	cout << "\n¬ведите ключ: "; cin >> key;
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