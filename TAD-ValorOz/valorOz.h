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
  string rec;
public:
  ValorOz(string _id, string _val, string _type); //Constructor de la clase
  void showInfo(); //Muestra la información que tiene el ValorOz

  bool operator==( const ValorOz& v1){
    return id == v1.id;
  }
};

#endif
