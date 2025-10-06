#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <list>
#include <map>

using std::cin;
using std::cout;
using std::endl;

#define tab			 "\t"
#define delimiter	 "\n-----------------------------------------------------\n"

const std::map<int, std::string> VIOLATIONS =
{
	{0, "N/A"},
	{1, "Парковка в неположенном месте"},
	{2, "Непристегнутый ремень безопасности"},
	{3, "Пересечение сплошной"},
	{4, "Превышение скорости"},
	{5, "Проезд на красный"},
	{6, "Выезд на встречную полосу"},
	{7, "Езда в нетрезвом состоянии"},
	{8, "Оскорбление офицера"},

};

class Crime
{
	int violation;
	std::string place;
public:
	int get_violation() const
	{
		return violation;
	}
	const std::string& get_place() const
	{
		return place;
	}
	void set_violation(int violation)
	{
		this->violation = violation;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	Crime(int violation, const std::string& place)
	{
		set_violation(violation);
		set_place(place);
	}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os.width(44);
	os << std::left;
	return os << VIOLATIONS.at(obj.get_violation()) << tab << obj.get_place();
}

void print(const std::map< std::string, std::list<Crime>>& base);
void save(const std::map< std::string, std::list<Crime>>& base, const std::string& filename);

void main()
{
	setlocale(LC_ALL, "");

	std::map<std::string, std::list<Crime>> base =
	{
			{"а777аа", {Crime(4, "пр. Ленина 69"), Crime(5, "ул. Энтузиастов"), Crime(7, "ул. Ленина"), Crime(8, "ул. Энтузиастов")}},
			{"a123nc", {Crime(2, "ул. Пролетарская"), Crime(3, "ул. Ватутина")}},
			{"a001eg", {Crime(5, "ул. Пролетарская"), Crime(5, "ул. Октябрьская"), Crime(7, "ул. Ватутина"), Crime(8, "ул. Ватутина")}}
	};

	print(base);
	save(base, "base.txt");
}

void print(const std::map< std::string, std::list<Crime>>& base)
{
	for (std::map< std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			cout << tab << *violation << endl;
		}
		cout << delimiter;
	}
}

void save(const std::map< std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::map< std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		fout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			fout << tab << *violation << endl;
		}
		fout << delimiter;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
}














//class Offense;
//void print_base(const std::map<std::string, std::list<Offense>>& cont);
//void add_to_list(std::map<std::string, std::list<Offense>>& cont);
//
//class Offense
//{
//	std::string protocol;
//	std::string offenseName;
//	std::string addressOffense;
//public:
//	std::string get_num_prot() const
//	{
//		return protocol;
//	}
//	std::string get_offense_name() const
//	{
//		return offenseName;
//	}
//	std::string get_address() const
//	{
//		return addressOffense;
//	}
//	Offense(const std::string& protocol, const std::string& offenseName, const std::string& addressOffense) : protocol(protocol), offenseName(offenseName), addressOffense(addressOffense) {}
//	~Offense() {};
//	friend std::ostream& operator<<(std::ostream& os, const Offense& obj);
//};
//
//std::ostream& operator<<(std::ostream& os, const Offense& obj)
//{
//	return os << obj.get_num_prot() << tab << obj.get_offense_name() << tab << obj.get_address() << endl;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	std::map<std::string, std::list<Offense>> base =
//	{
//			{"b007nd", {Offense("AP0004", "драка с полицейским", "пр. Ленина 69"), Offense("AP0002", "проезд на красный", "ул. Энтузиастов")}},
//			{"a123nc", {Offense("AP0001", "превышение скорости", "пр. Ленина 69"), Offense("AP0003", "пересечение сплошной", "ул. Энтузиастов")}}
//	};
//	print_base(base);
//	cout << endl;
//	add_to_list(base);
//	print_base(base);
//	cout << endl;
//
//}
//
//void print_base(const std::map< std::string, std::list<Offense>>& cont)
//{
//	for (std::map< std::string, std::list<Offense>>::const_iterator it = cont.begin(); it != cont.end(); ++it)
//	{
//		cout.width(15);
//		cout << it->first << ":" << tab;
//		for (std::list<Offense>::const_iterator sec_it = it->second.begin(); sec_it != it->second.end(); ++sec_it)
//		{
//			cout.width(15);
//			cout << *sec_it << tab;
//		}
//		cout << endl;
//	}
//}
//
//void add_to_list (std::map<std::string, std::list<Offense>>& cont)
//{
//	std::string number_automobile;
//	std::string protocol;
//	std::string offenseName;
//	std::string addressOffense;
//	cout << "Введите номер автомобиля: "; cin >> number_automobile;
//	cout << "Введите номер административного правонарушения: "; cin >> protocol;
//	cout << "Название правонарушения: ";
//	cin.clear();
//	cin.ignore();
//	std::getline(cin, offenseName);
//	cout << "Введите место проишествия: ";
//	cin.clear();
//	cin.ignore();
//	std::getline(cin, addressOffense);
//	cont[number_automobile].push_back(Offense(protocol, offenseName, addressOffense));
//}

//class FileOpen
//{
//	FILE* f;
//public:
//	FileOpen(char* filename, char* mode)
//	{
//		if (!(f = fopen(filename, mode)))
//		{
//			exit(0);
//		}
//	}
//	~FileOpen() {
//		fclose(f);
//	}
//};
// }
// void f() {
//	 FileOpen MyFile("test.txt", "r+");
//	 //здесь выполняем нужную работу с файлом
//	 Для усовершенствования нашего принципа мы мож

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