#include "almacen.h"
#include "../TAD-ValorOz/valorOz.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Almacen :: Almacen(){
  vector<ValorOz> almacen;
}

void Almacen :: addVal( ValorOz& valOz ){
  almacen.push_back(valOz);
}

void Almacen :: showVals(){
  vector<ValorOz>::iterator it;

  for(it = almacen.begin(); it != almacen.end(); it++){
    it->showInfo();
  }

}
