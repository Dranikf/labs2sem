#include <vector>
#include <string>

#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

using namespace std;
// тут объявлены общие для всех прочих файлов структуры и функции

struct  position // структура описывает позиции всех вихуальных объектов в программе
{
    float x, y;
};

void parseDataStr(std::vector<string> *, string);

#endif