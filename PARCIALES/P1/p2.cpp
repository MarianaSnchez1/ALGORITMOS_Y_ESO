//Punto 2

void weird_order(vector<int> &v) {
  int min_idx=0; //Crea variables para ver el indice del numero mayor o menor
  int max_idx=1; //Suponemos que el indice del mayor numero empieza en el segundo elemento ya que este se organiza despues de organizar el primer elemento

  for (unsigned j=1; j<v.size(); j++){
    if (v[j] < v[min_idx]){ //Busca elementos en el vector para ver cual es el numero menor
      min_idx =j;
    }
  }
  swap (v[0], v[min_idx]); //Pone el numero mas pequeno en la primera posicion

  for (unsigned i=0; i<v.size(); i++){
    if (v[i] > v[max_idx]){//Busca dentro de los elementos del vector cual es el mayor
      max_idx =i;
    }
  }
  swap (v[1], v[max_idx]); //Pone el numero mas grande en la segunda posicion

  //como la primera y segunda posicion ya estan ocupadas, pone el elemento mediano al final del vector
}
