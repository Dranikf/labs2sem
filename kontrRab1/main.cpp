#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <vector>
#include "common_funcks.h"

using namespace std;

template<typename T>
bool readFileData(vector<T> * array, string fileName){

    ifstream file(fileName);

    if(!file.is_open())
        return false;

    string dataStr;

    while (!file.eof())
    {
        getline(file, dataStr);
        array->push_back(T(dataStr));
        
    }
    
        
    file.close();

    return true;
}

class zakaz{

private:

    string prod_name;
    int prise;
    double count_post;
    double count_zakazano;


public:

    double count_nedop;
    double prise_nedop;

    zakaz(string dataStr){

        vector<string> data;
        parseDataStr(&data, dataStr);

        prod_name = data[0];
        prise = atoi(data[1].c_str());
        count_post = atof(data[2].c_str());
        count_zakazano = atof(data[3].c_str());
       
    };

    void showData(){
        
        cout << "название продукции: "<<prod_name  << endl;
        cout << "цена продукции: "<<prise  << endl;
        cout << "количество продукции поставлено: "<<count_post  << endl;
        cout << "количество продукции заказано: "<<count_zakazano  << endl;
        cout << "недопоставленно продукции: " << count_nedop << endl;
        cout << "стоимоть недопоставленной продукции: " << prise_nedop << endl; 

    };

    void analyze_data(){

        count_nedop = count_zakazano - count_post > 0 ?count_zakazano - count_post : 0;
        prise_nedop = count_nedop * prise;
    };

};

vector<zakaz> array_f;

int main(){
    setlocale(LC_ALL, "Russian");

    readFileData(&array_f ,"zakazFile");

    ofstream of("goOut");

    for(int i = 0; i < array_f.size(); i++){

        cout << "+++++++++++++++++++++++++++++++"<< endl;
        array_f[i].analyze_data();
        array_f[i].showData();
        cout << "+++++++++++++++++++++++++++++++" << endl;

        of<< array_f[i].count_nedop << " " << array_f[i].prise_nedop << endl;
    }

    of.close();

    return 0;
}