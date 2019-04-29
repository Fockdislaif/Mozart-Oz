#include "operaciones.h"
#include "../TAD-Almacen/almacen.h"
#include "../TAD-ValorOz/valorOz.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

Operaciones op;

bool Operaciones :: isInt(string n){
  /*
  Funcion que permite saber si el string ingresado es un entero
  */
  string::iterator it;
  it = find( n.begin(), n.end(), '.');

  if( it != n.end() ){
    return false;
  }
  return true;
}

string Operaciones :: wType(string s){
  /*
  Retorna el tipo de variable que se ingreso
    Tipos: record, var, int, float, unLinked
      registro está escrito en minuscula.
      variable está escrita en MAYUSCULA.
      int no tiene un '.'
      float no tiene un '.'
      unLinked es igual a _
  */
  string type = "unLinked";
  if( s == "_" ){
    return type;
  }else if( s[0] >= 'a' && s[0] <= 'z' ){
    type = "record";
    return type;
  }else if( s[0] >= 'A' && s[0] <= 'Z' ){
    type = "var";
    return type;
  }else{
    if( op.isInt(s) ){
      type = "int";
      return type;
    }else{
      type = "float";
      return type;
    }
  }
}

ValorOz Operaciones :: parse(string n){
  int i;
  string id = "", val = "", type;
  for(i = 0; i < n.size(); i++){
    //Encuentra el identificador de la variable
    if( n[i] == '=' ){
      i++;
      break;
    }else{
      id += n[i];
    }
  }

  for(i; i < n.size(); i++){
    //Encuentra la variable
      val += n[i];
  }
  type = op.wType(val);

  return ValorOz(id, val, type);
}
