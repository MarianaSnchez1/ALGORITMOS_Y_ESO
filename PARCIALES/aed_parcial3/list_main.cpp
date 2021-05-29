#include "list.hpp"
using namespace std;

int main() {
  List<int> l;
  cout << ":::";
  for(int i = 0; i < 5; ++i){
   l.push_back(i);
   l.display();
   cout << "AA";
 }

  for(int i = 0; i < 5; ++i){
    l.push_front(i);
    l.display();
    cout << "BB";
  }

  l.display();
  l.pop_back();
  l.pop_front();

  l.display();

  return 0;
}
