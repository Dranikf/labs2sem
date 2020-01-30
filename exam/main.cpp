#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "common_funcks.h"


using namespace std;

vector<float> sumPokr, ostatok;

class credit;
void getResults(vector<credit> * c);

class credit
{
    public:
        credit(string dataStr);
        string dogovorNumber;

    private:
        
        vector<float> paidSums;
        float summ;
        friend void getResults(vector<credit> * c);
};

void getResults(vector<credit> * c){

    float tempSumPokr, tempOstatok;

    for(int i = 0; i < (*c).size(); i++)
    {
        tempSumPokr = 0;
        tempOstatok = 0;
        for(int j = 0; j < (*c)[i].paidSums.size(); j++){

            tempSumPokr += (*c)[i].paidSums[j];

        }

        tempOstatok = (*c)[i].summ - tempSumPokr;

        sumPokr.push_back(tempSumPokr);
        ostatok.push_back(tempOstatok);

    }

}

vector<credit> cred;

credit::credit(string dataStr){

    vector<string> array;

    parseDataStr(&array , dataStr);

    dogovorNumber = array[0];
    summ = atof(array[1].c_str());

    for(int i = 2; i < array.size(); i++){
        paidSums.push_back(atof(array[i].c_str()));
    }

}

int main(){

    ifstream file("data.txt");
    if(!file.is_open())
        cout << "ошибка открытия файла!" << endl;

    string tempStr;

    while(!file.eof()){

        getline(file, tempStr);
        cred.push_back(credit(tempStr));

    }

    getResults(&cred);

    for(int i = 0 ; i < cred.size(); i++){
        cout << "+++++++++++++++++++++++++++++++++++" << endl;
        cout << "для договора номер " << cred[i].dogovorNumber << endl;
        cout << "сумма покрытия кредита " << sumPokr[i] << endl;
        cout << "остатки задолеженности по договорам" << ostatok[i] << endl;
        cout << "+++++++++++++++++++++++++++++++++++" << endl;

    }

    file.close();

}


