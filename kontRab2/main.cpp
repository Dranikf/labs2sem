#include <iostream>
#include <string>
#include <locale>

using namespace std;

enum type {lechenie, otduh, exkursiya};

class marshrut{

	public:
		string country;
		type t;// тип маршрута
		int price;


};

class klient{
	public:
		marshrut m;
		string FIO;
		int countTrips;

		double calculatePrice(){
		
			return countTrips * m.price;

		};
};

int main(){
	
	klient k1;

	k1.m.country = "туркменистан";

	cout << "введите тип путевки"  << endl;
	cout << "1 - лечение, стоимость 400" << endl;
	cout << "2 - отдых, стоимоть 500 " << endl;
	cout << "3 - экстурсия, стоимость 600" << endl;
	int a; cin >> a;
	switch (a){

			case 1: 
				k1.m.t = lechenie; 
				k1.m.price = 400;
				break;
			case 2:
				k1.m.t = otduh;
				k1.m.price = 500;
				break;
			case 3:
				k1.m.t = exkursiya;
				k1.m.price = 600;
				break;

	}	

	k1.FIO = "Кобак Федор Алексеевич";
	k1.countTrips = 5;

	cout << "цена представленной поездки составит "  <<  k1.calculatePrice()<< "у.е."<< endl;

	setlocale(LC_ALL, "Ru");
}
