#include <iostream>
#include <string>
#include <locale.h>
//#include <Windows.h>  на линуксе либы этой нет потому заремил
#include <vector>
#include <fstream> // подулюючим потоки из зайла, Говядинова обожает когда подгружаешь данные с файла
// #include <string> неапонятно почему ты дважды подключил string, да и непонятно зачем вообще подключил, у тебя он нигде не используется
// но я использую потому оставил

using namespace std;

// а вот тут начинается жесть...
// Никита неправильно понимаешь ООП
// дело в том что тебе лишь надо создать ОДИН класс и наклепать его объектов, судя по условию задачи!!!
// т.е тебе надо создать класс на все случаи жизни, универсальный и в его поля писать нужные значения
// а не на каждый случай создавать по классу


/*class cContract {
public:
	virtual void determinate() {}; //Создание виртуальной функции
};

class cOOOKosmos : public cContract {
protected:
	string number = "345/12"; //Номер договора
	double delivery_amount = 890.6; //Сумма поставки по договору
	double to_delivered = 850; //Поставлено фактически
public:
	void determinate() override { //Реализация виртуальной функции в дочернем классе
		if (delivery_amount - to_delivered >= 0) {
			cout << "ООО Космос отклонение: " << delivery_amount - to_delivered << endl;
		}
		else {
			cout << "ООО Космос превышение: " << to_delivered - delivery_amount<< endl;
		}
	}
};

class cBelMed : public cContract {
protected:
	string number = "234/12"; //Номер договора
	double delivery_amount = 456.8; //Сумма поставки по договору
	double to_delivered = 460.6; //Поставлено фактически
public:
	void determinate() override { //Реализация виртуальной функции в дочернем классе		
		if (delivery_amount - to_delivered >= 0) {
			cout << "БелМед отклонение: " << delivery_amount - to_delivered << endl;
		}
		else {
			cout << "БелМед превышение: " << to_delivered - delivery_amount << endl;
		}
	}
};

class cOAOZara : public cContract {
protected:
	string number = "678/13"; //Номер договора
	double delivery_amount = 56.89; //Сумма поставки по договору
	double to_delivered = 100.4; //Поставлено фактически
public:
	void determinate() override { //Реализация виртуальной функции в дочернем классе		
		if (delivery_amount - to_delivered >= 0) {
			cout << "ОАО Заря отклонение: " << delivery_amount - to_delivered << endl;
		}
		else {
			cout << "ОАО Заря превышение: " << to_delivered - delivery_amount << endl;
		}
	}
};

class cBelvest : public cContract {
protected:
	string number = "2345/14"; //Номер договора
	double delivery_amount = 345.56; //Сумма поставки по договору
	double to_delivered = 356.9; //Поставлено фактически
public:
	void determinate() override { //Реализация виртуальной функции в дочернем классе		
		if (delivery_amount - to_delivered >= 0) {
			cout << "Белвест отклонение: " << delivery_amount - to_delivered << endl;
		}
		else {
			cout << "Белвест превышение: " << to_delivered - delivery_amount << endl;
		}
	}
};

class cMarko : public cContract {
protected:
	string number = "123/13"; //Номер договора
	double delivery_amount = 123.9; //Сумма поставки по договору
	double to_delivered = 98.89; //Поставлено фактически
public:
	void determinate() override { //Реализация виртуальной функции в дочернем классе		
		if (delivery_amount - to_delivered >= 0) {
			cout << "Марко отклонение: " << delivery_amount - to_delivered << endl;
		}
		else {
			cout << "Марко превышение: " << to_delivered - delivery_amount << endl;
		}
	}
};

void app(vector<cContract*>& Contract) {
	//Создание указателей на классы договоров
	cOOOKosmos* OOOKosmos = new cOOOKosmos; 
	cBelMed* BelMed = new cBelMed;
	cOAOZara* OAOZara = new cOAOZara;
	cBelvest* Belvest = new cBelvest;
	cMarko* Marko = new cMarko;

	cContract* p = new cContract; //временный указатель на базовый класс

	p = OOOKosmos; //присвоение временному указателю указатель на договор
	Contract.push_back(p); //добавление указателя в вектор

	p = BelMed;
	Contract.push_back(p);

	p = OAOZara;
	Contract.push_back(p);

	p = Belvest;
	Contract.push_back(p);

	p = Marko;
	Contract.push_back(p);
}

void output(vector<cContract*>& Contracts) { //вывод
	for (int i = 0; i < Contracts.size(); i++) {
		Contracts[i]->determinate();
	}
}*/

class Customer{

	private:
		string 	name; // имя заказчика
		string 	number; // номер, да я знаю, номер хочеться объявить как число но туда закрался слеш (см условие), потому проще в виде текста 
		float 	summ; //сумма доставки по договору
		float	fact; // поставлено фактически
	public:
		Customer(string); // конструктор который должен заполнять класс
							// мы в него просто суем строку с полями разделенными пробелами в нужной последовательности
							// удобно для чтения из файла

		virtual float calculate() {return summ - fact;}; // функция будет слитать отклонение
		// да, знаю, без наследование нет никакого смысла в ее виртуализации
		// но сказано виртуальная, будет виртуальная...
		string getName(){return name;}; // просто функция для получения имени(геттер)
};

// функция парсит str и по адресу dataPointer пишет массив из подстрок разделенных пробелом
// интелектуальная собственность Кобака Фёдора XD
void parseDataStr(std::vector<string> * dataPointer, string str){

    int pos, prePos = 0, i =0;
    string tempStr;

    while((pos = str.find(" ", prePos)) != string::npos){

        tempStr = str.substr(prePos, pos - prePos);
        dataPointer->push_back(tempStr);
        prePos = pos + 1;
        i++;

    }

    dataPointer->push_back(str.substr(prePos, str.length() - prePos));

}

Customer::Customer(string dataStr){

	std::vector<string> data;
	parseDataStr(&data, dataStr);
	name = data[0];
	number = data[1];
	summ = atof(data[2].c_str());
	fact = atof(data[3].c_str());

}


int main()
{
	//SetConsoleCP(1251); //русификация консоли
	//SetConsoleOutputCP(1251);  // этих штук тоже нет
	setlocale(LC_ALL, "Ru");


	vector<Customer> array; // создаем заявленный в условии маассив, можно лубой другой контейнер
	// но вектор мне привычнее всего
	ifstream file("dataFile"); // поудключаю файл в который я заботливо занес данные из условиия...

	if(!file.is_open()){ 
		cout<< "не удалось подгрузить файл!" << endl;
		return 0;
	}


	string tempString;
	while(!file.eof())
	{
		getline(file , tempString); // плучаем псотрочно данные из файла
		// в каждой строке данные для каждого нового объекта
		array.push_back(/*тут вызываем конструктор ->*/Customer(tempString) /*он вернет в push_back объект, так и заполним массив*/);
	}
	
	
	for(int i = 0; i < array.size(); i++) //перебираем элементы массива и выводим данные
	{
		cout << "_________________________________________________" << endl;
		cout << array[i].getName() << " | " << array[i].calculate() << endl;

	}

	file.close();

	system("pause"); //пауза в консоли
}
