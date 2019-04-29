#include "Operaciones/operaciones.h"
#include "TAD-Almacen/almacen.h"
#include "TAD-ValorOz/valorOz.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
  Operaciones o;
  Almacen a;
  string line;

  while( getline(cin, line) ){
    ValorOz v = o.parse(line);
    a.addVal(v);

    //v.showInfo();
  }
  a.showVals();

  return 0;
}
