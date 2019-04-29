#ifndef ALMACEN_H
#define ALMACEN_H

#include "../TAD-ValorOz/valorOz.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Almacen{
private:
  vector<ValorOz> almacen;
public:
  Almacen();
  void addVal(ValorOz& valOz);
  void showVals();

};

#endif
