#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;

void summa(int n){
	sum += n;
}

void (*funPtr)(int n) = summa;

class functor{
	public:
		void operator() (int n) {sum += n;};
};

int main(){
	
	
	vector<int> v = {1 , 2 , 3, 4 , 5};

	for_each(v.begin(), v.end(), summa);

	cout << "sum = " << sum  << endl;

	sum = 0;
	functor f;
	for_each(v.begin(), v.end(), f);
	cout<< "sum 2 = " << sum << endl;


	sum = 0;
	for_each(v.begin(), v.end(), [] (int n){sum += n;});
	cout << "sum 3 = " << sum << endl;

}
