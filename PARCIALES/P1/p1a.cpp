//Punto 1.a

map<int, unsigned> freq_histo(list<int> lst) {
    map<int,unsigned> repe; //Crea el mapa donde se va a guardar la informacion

    while (!lst.empty()){
      int key= lst.front(); //crea la llave donde se guarda el numero de la lista
      unsigned value=0; //crea un contador para ver cuantas veces se repite el numero

      for (list<int>::iterator it=lst.begin(); it!=lst.end();it++){
        if (key== *it){
          value ++; //suma cuantas veces se repite el numero
        }
      }

      repe.insert(pair<int,unsigned>(key,value)); //agrega al mapa el numero como llave y cuantas veces aparece como el valor
      lst.pop_front(); //Borra el primer elemento para poder evaluar todos los elementos de la lista
    }

    return repe;
}
