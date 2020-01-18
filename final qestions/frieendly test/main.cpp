#include <iostream>

using namespace std;

class test{
	private:
		void show(){cout << "hello world" << endl;};


	public:
		friend void testf(test * t);
		friend void testf(test & t);

};


void testf(test * t){t->show();};
void testf(test & t){t.show();};


int main(){

	test u;
	testf(&u);
	testf(u);

}
