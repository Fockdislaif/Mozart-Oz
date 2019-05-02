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

string Almacen :: findFather(ValorOz son){
  /*
  El objetivo de esta funcion es encontrar la variable padre para un valor cuando
  se haga la ligadura o linkeamiento con una variable para así mantener el arbol
  a 2 niveles.
  */
  string type, father = son.id;
  vector<ValorOz>::iterator it;
  it = find(almacen.begin(), almacen.end(), son);
  type = it->type;

  while( type == "var" ){
    son.id = it->val3;
    it = find(almacen.begin(), almacen.end(), son);
    type = it->type;
    father = it->id;
  }


  return father;
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
    if( valOz.type != "var" ){
      almacen.push_back(valOz);
    }else{
      valOz.val3 = findFather( ValorOz(valOz.val3) );
      almacen.push_back(valOz);
    }
  }else{
    /*
    Si entra en este else, significa que la variable existe, por lo tanto se debe
    modificar el valorOz que se ingreso con respecto a la variable que desea representar.

    - Para poder hacer esto se debe verificar si la variable no esta ligada.
        - En caso de que no este ligada, entonces se hace la ligadura con el tipo
        y la variable (a un solo nivel).
        - En caso de que este ligada, entonces se pregunta si el valor que tiene es
        el mismo.
          - Si es el mismo no se hace nada.
          - Si no es el mismo entonces da un error y finaliza.
    */
    if(info[0] == "unLinked"){
      /*
      Si la variable está sin ligar entonces se verifica si el tipo de la variable
      a la que apunta es de tipo "var" o no
      */
      if( valOz.type == "var" ){
        /*
        Si la variable a la que apunta es tipo var entonces se usa la funcion
        findFather para encontrar el nodo padre para mantener el arbol a 2 niveles
        y así saber que una variable no puede apuntar a una variable hija que apunte a
        el mismo, así se evita un error de iteraciones infinitas.
        */
        if( findFather( ValorOz(valOz.val3) ) != valOz.id ){
          valOz.val3 = findFather( ValorOz(valOz.val3) );
          vector<ValorOz>::iterator it;
          it = find(almacen.begin(), almacen.end(), valOz);
          int dist = it-almacen.begin();
          almacen[ dist ] = valOz;
        }

      }else{
        /*
        En caso de que la variable este sin ligar y que el valor al que desee
        ligarse ahora sea algo diferente de una variable es decir que es
        un entero, un float o un registro (aún no se han implementado los registros) 
        */
        vector<ValorOz>::iterator it;
        it = find(almacen.begin(), almacen.end(), valOz);
        int dist = it-almacen.begin();
        almacen[ dist ] = valOz;
      }
    }
  }
}

void Almacen :: showVals(){
  vector<ValorOz>::iterator it;

  for(it = almacen.begin(); it != almacen.end(); it++){
    it->showInfo();
  }

}
