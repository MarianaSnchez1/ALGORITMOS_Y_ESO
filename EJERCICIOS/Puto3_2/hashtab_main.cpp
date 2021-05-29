#include "hashtab.hpp"

int main() {
  HashTab mytab;

  vector<int> vec = {-3,2,6,-1,0,1,5,-2,-3,3,8};

  for(int ini = 0; ini < vec.size(); ini++){
    for(int fin = ini+1; fin < vec.size()+1; fin++){
      vector<int> subv(vec.begin()+ini, vec.begin()+fin);
      mytab.insert(subv);
    }
  }

  mytab.display_bucket(3);

  return 0;
}
