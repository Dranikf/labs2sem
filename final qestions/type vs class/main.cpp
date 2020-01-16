#include <iostream>

using namespace std;

class A{

	public:
		int value;

		A operator+(A a) {
			A temp;

			temp.value = this->value + a.value; 

			return temp;

		};

};

template<class T>
T sum(T a , T b){

	return a + b;

}


int main(){

	int a = 10 , b = 20;

	cout << sum(a,b)  << endl;

	float c = 89.0657f ,d = -43.23f;

	cout<< c + d  << endl;

	A e, g;

	e.value = 23;
	g.value = 90;

	A f = sum(g, e);	
	cout<< f.value  << endl;

}
