// Punto 1.b

int most_freq(map<int, unsigned> hist){
    int mayor= hist.begin()->first; //Suponemos que el de mayor repeticiones es el primer elemento del mapa

    for (map<int,unsigned>::iterator it=hist.begin(); it!=hist.end(); it++){
      if (hist[mayor] < it->second){ //Revisa todo el mapa para ver si encuentra un elemento de mayor repeticiones
        mayor= it->first; //Si lo encuentra pasa a ser el mayor
      }
    }

    return mayor;
}
