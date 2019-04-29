#ifndef VALOROZ_H
#define VALOROZ_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ValorOz{
public:
  string id;
  string type; //Ligado (int, float, registro) , no ligado (_).
  int val1;
  double val2;
  string val3;
  vector<ValorOz> reg;
public:
  ValorOz(string _id, string _val, string _type); //Constructor de la clase
  void showInfo(); //Muestra la información que tiene el ValorOz
};

#endif
