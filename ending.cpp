#include <iostream>

using namespace std;

/*Число чего-либо, первая буква чего-либо
r=рубль
a=попытка
t=раз
h=час
w=целая
n=купюра
y=год*/
string ending(int number, char word) {
    int ending;
    string rub[4] = { " рубль", " рубля", " рублей", " рублей" };//рубль
    string attemt[4] = { " попытка", " попытки", " попыток", " попыток" };//попытка
    string times[4] = { " раз", " раза", " раз", " раз" };//раз
    string hour[4] = { " час", " часа", " часов", " часов" };//час
    string whole[4] = { " целая", " целых", " целых", " целых" };//целая
    string note[4] = { " купюра", " купюры", " купюр", " купюр" };//купюра
    string year[4] = { " год", " года", " лет", " лет" };//год
    string cub[4] = { " кубик", " кубика", " кубиков", " кубиков" };//кубик
    string set[4] = { " набор", " набора", " наборов", " наборов" };//набор
    string move[4] = { " ход", " хода", " ходов", " ходов" }; //ход

    if ((number / 10) % 10 == 1) ending = 3;
    else if (number % 10 == 0 || number % 10 >= 5) ending = 2;
    else if (number % 10 > 1 && number % 10 < 5) ending = 1;
    else if (number % 10 == 1) ending = 0;

    if (word == 114) return rub[ending];    //r
    if (word == 97) return attemt[ending];  //a
    if (word == 116) return times[ending];  //t
    if (word == 104) return hour[ending];   //h
    if (word == 119) return whole[ending];  //w
    if (word == 110) return note[ending];   //n
    if (word == 121) return year[ending];    //y
    if (word == 99) return cub[ending];    //c
    if (word == 115) return set[ending];    //s
    if (word == 109 ) return move[ending]; //m
 }