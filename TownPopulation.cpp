#include <iostream>
#include <list>
#include <map>

using namespace std;

void show_list(list<int> my_list) {
	cout << "My list: ";
	list<int>::iterator it = my_list.begin();
	while (it != my_list.end()) {
		cout << *(it++) << " ";
	}
	cout << endl;
}

class Town {
public:
	string region;
	string name;
	double population;
	friend ostream& operator<<(ostream& out, const Town& town);
};

ostream& operator<<(ostream& out, const Town& town) {
	out << town.region << " " << town.name
		<< " " << town.population << endl;
	return out;
}

void show_list(list<Town> my_list) {
	//cout << "My list: ";
	list<Town>::iterator it = my_list.begin();
	while (it != my_list.end()) {
		cout << *(it++);
	}
	cout << endl;
}

bool compare_only_by_population(Town a, Town b) {
	
	if (a.population != b.population)
	{
		return a.population > b.population;
	}
	else
	{
		return a.population < b.population;
	}

}

void main() {
	list<Town> towns;
	towns.push_back(Town{ "RostovReg", "Rostov", 2.0e6 });
	towns.push_back(Town{ "RostovReg", "Azov", 82.0e3 });
	towns.push_back(Town{ "RostovReg", "Taganrog", 0.2e6 });

	towns.push_back(Town{ "MoscowReg", "Moscow",  20.0e6 });
	towns.push_back(Town{ "MoscowReg", "Korolev", 183.0e3 });
	towns.push_back(Town{ "MoscowReg", "Podolsk", 187.0e3 });

	towns.sort(compare_only_by_population);
	show_list(towns);

	cout << endl;

	/*
	Отсортировать города чисто по населению не зависимо от Региона и Названия.
	Вывести на экран.
	*/

}
