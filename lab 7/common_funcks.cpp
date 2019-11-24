#include "common_funcks.h"

// функция парсит строку с данными, и пишет в вектор
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