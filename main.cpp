#include "Operaciones/operaciones.h"
#include "TAD-Almacen/almacen.h"
#include "TAD-ValorOz/valorOz.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool fail = false;

int main(){
  Operaciones o;
  Almacen a;
  string line;

  while( getline(cin, line) ){
    ValorOz v = o.parse(line);
    a.addVal(v);

    //v.showInfo();
    if( fail ){
      cout << "La ligadura ingresada no es permitida: " << line <<"\n";
      break;
    }
  }
  cout << "- - Estado del almacen - -" << "\n";
  a.showVals();

  return 0;
}
