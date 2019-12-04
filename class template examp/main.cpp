#include <iostream>
 
using namespace std;
 
#include <iomanip>
 
template <typename T>
class Stack
{
private:

     // вершина стека
public:
    
    T top;
    bool push( T  ); // поместить элемент в стек
    

};

template <typename T>
struct hello
{
    T t1;
    void h(T);
    void set(const T t);
};

template <typename T>
void hello<T>::h(T t){

    cout << t << endl;

}

template<typename T>
void hello<T>::set(const T t){

    t1 = t;
}


 
int main()
{
    Stack <int> myStack;
 
    myStack.push(2);

    cout << myStack.top << endl;

    hello<string> test;

    test.h("это универсльный вывод");
    test.set("jfjkdlsjf");

 
    return 0;
}
 
// элемент функция класса  Stack для помещения элемента в стек
// возвращаемое значение - true, операция успешно завершена
//                                    false, элемент в стек не добавлен
template <typename T>
bool Stack<T>::push( T value)
{
    top = value;
 
    return true; // успешное выполнение операции
}