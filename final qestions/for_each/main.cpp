#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;

void summa(int n){
	sum += n;
}

void (*funPtr)(int n) = summa;

int main(){
	
	
	vector<int> v = {1 , 2 , 3, 4 , 5};

	for_each(v.begin(), v.end(), summa);

	cout << "" << sum  << endl;

}
