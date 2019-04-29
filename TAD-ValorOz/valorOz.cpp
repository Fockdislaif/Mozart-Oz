#include "valorOz.h"
#include <iostream>
#include <string>

using namespace std;

ValorOz :: ValorOz(string _id, string _val, string _type){
  /*
  Antes de hacer la asignación se debe verificar un par de cosas:
    Verificar que la variable inicial exista.
      Si ese es el caso verificar si se encuentra sin ligar o si el valor es el mismo.
        En tal caso entonces asigna el valor.
        Si no, entonces no se puede ligar.
      En caso de que no exista entonces se crea la variable y se asigna el valor
      indicado
  */
  std::string::size_type sz;
  if( _type == "unLinked" ){
    id = _id;
    type = _type;
  }else if( _type == "int" ){
    id = _id;
    type = _type;
    val1 = stoi(_val, &sz);
  }else if( _type == "float" ){
    id = _id;
    type = _type;
    val2 = stod(_val, &sz);
  }else if( _type == "var" ){
    id = _id;
    type = _type;
    val3 = _val;
  }else if( _type == "record" ){
    id = _id;
    type = _type;
    rec = _val;
  }
}

void ValorOz :: showInfo(){
  cout << id << " -> ";
  if( type == "unLinked" ){
    cout << "_" << "\n";
  }else if( type == "int" ){
    cout << val1 << "\n";
  }else if( type == "float" ){
    cout << val2 << "\n";
  }else if( type == "var" ){
    cout << val3 << "\n";
  }
}
