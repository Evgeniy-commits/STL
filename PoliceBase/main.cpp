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
	std::string addressOffense;
public:
	std::string get_num_prot() const
	{
		return protocol;
	}
	std::string get_address() const
	{
		return addressOffense;
	}
	Offense(const std::string& protocol, const std::string& addressOffense) : protocol(protocol), addressOffense(addressOffense) {}
	~Offense() {};
	friend std::ostream& operator<<(std::ostream& os, const Offense& obj);
};

static const std::map<std::string, std::string> OffenseList =
{
	{"AP0001", "���������� ��������"},
	{"AP0002", "������ �� �������"},
	{"AP0003", "����������� ��������"},
	{"AP0004", "����� � �����������"},
};

std::ostream& operator<<(std::ostream& os, const Offense& obj)
{
	return os << obj.get_num_prot() << tab << OffenseList.at(obj.get_num_prot()) << tab << obj.get_address() << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");

	std::map<std::string, std::list<Offense>> base =
	{
			{"b007nd", {Offense("AP0004", "��. ������ 69")}},
			{"a123nc", {Offense("AP0001", "��. ������ 69"), Offense("AP0003", "��. �����������"), Offense("AP0002", "��. �����������")}}
	};
	print_base(base);
	cout << endl;
	//add_to_list(base);
	//print_base(base);
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
	std::string addressOffense;
	cout << "������� ����� ����������: "; cin >> number_automobile;
	cout << "������� �������������� (����� ������): "; cin >> protocol;
	cout << "������� ����� �����������: ";
	cin.clear();
	cin.ignore();
	std::getline(cin, addressOffense);
	cont[number_automobile].push_back(Offense(protocol, addressOffense));
}