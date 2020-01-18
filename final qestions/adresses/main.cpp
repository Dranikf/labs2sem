#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>


using namespace std;

int main(){

	list<int> l;
	vector<int> v;
	for (int i = 0 ; i < 100 ; i++){
		
		v.push_back(i);
		l.push_back(i);

		for(int j = 0; j < rand() % 100 ; j++)
			int a = rand();
	}

	cout << "vector test ++++++++++++++++++++++++" << endl;
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		cout << &(*i) << endl;
	cout << "vector test ++++++++++++++++++++++++" << endl;


	 cout << "list test ++++++++++++++++++++++++" << endl;
        for (list<int>::iterator i = l.begin(); i != l.end(); i++)
                cout << &(*i) << endl;
        cout << "list test ++++++++++++++++++++++++" << endl;

}
