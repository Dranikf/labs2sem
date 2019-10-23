#include <iostream>
#include <string>
// пример по работе с шаблонами

using namespace std;

template <typename T>// T - условное название принимаемого типа
T Sum(T a, T b){ // тут мы создали функцию, она возвращает 
//шаблонный тип и принимает два шаблонных параметра
// функция суммирует переменные не звасимо от 
// класса

return a + b;

}


struct test{

    int test_field;

};

struct test2
{
    int test2_field;
    test2 operator+(test2 t);
};

test2 test2::operator+(test2 t){

    test2 temp;
    temp.test2_field = t.test2_field + test2_field;
    return temp;
}


int main(){

    // хотим, принимаем int
    int a = 20, b = 25; 
    cout << "Sum = " << Sum(a, b) << endl;

    // хотим - примем float
    float a1 = 209, b1 = 25;
    cout << "Sum = " << Sum(a1, b1) << endl;

    // вообще можно в неё теперь закинуть, что угдно
    // главное чтоб был перегружен используемый оператор
    // попробуем string
    string str1 = "str1", str2 = "str2";
    cout <<   Sum(str1, str2) << endl;
    // ну для строк объявлен оператор + который производит конкатинацию


    // теперь попробуем для типов которые не имеют подхдящих операторов
   // test t1, t2;
  //  test t3 = Sum(t1, t2);
    // ну плучаем соответсвенно ошибку

    // ну а вот для класса для которого перегрузил +
    test2 t2_1, t2_2;
    t2_1.test2_field = 1000;
    t2_2.test2_field = 50;
    test2 t2_3 = Sum(t2_1, t2_2);
    cout<< t2_3.test2_field << endl;

    
}