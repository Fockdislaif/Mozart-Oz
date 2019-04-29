#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "../TAD-ValorOz/valorOz.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Operaciones{
public:
  ValorOz parse(string n);
  string wType(string t);
  bool isInt(string n);
};

#endif
