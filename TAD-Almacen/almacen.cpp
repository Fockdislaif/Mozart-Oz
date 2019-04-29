#include "almacen.h"
#include "../TAD-ValorOz/valorOz.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Almacen :: Almacen(){
  vector<ValorOz> almacen;
}

vector<string> Almacen :: existVal(ValorOz& valOz){
  /*
  Esta funcion verifica si existe un valorOz en el almacen, en caso de que exista
  lo que hace es retornar que tipo de valorOz es y que variable tiene asignada.
  en caso de que no exista retorna "none".
  */
  vector<string> salida = {"none", "0"};
  vector<ValorOz>::iterator it;

  it = find(almacen.begin(), almacen.end(), valOz);

  if( it != almacen.end() ){
    string _type = it->type;
    salida[0] = _type;
    if( _type == "int" ){
      salida[1] = to_string(it->val1);
    }else if( _type == "float" ){
      salida[1] = to_string(it->val2);
    }else if( _type == "var" ){
      salida[1] = it->val3;
    }else if( _type == "record" ){
      salida[1] = it->val3;
    }
    return salida;
  }

  return salida;
}

void Almacen :: addVal( ValorOz& valOz ){
  /*
    Esta funcion añade valores Oz al almacen, para esto, lo que hace es
    verificar si el valorOz ya existe, en caso de que no exista simplemente lo crea.
    en caso contrario lo que hace es verificar si el tipo y el valor de la variable
    es el mismo o si el tipo no esta ligado.
  */
  vector<string> info = existVal(valOz);
  if( info[0] == "none"){
    almacen.push_back(valOz);
  }else{
    if(info[0] == "unLinked"){
      //Llamar a la funcion que modifica el valor que tenga en el almacen
    }
  }
}

void Almacen :: showVals(){
  vector<ValorOz>::iterator it;

  for(it = almacen.begin(); it != almacen.end(); it++){
    it->showInfo();
  }

}
