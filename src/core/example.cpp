#include<stdio.h>
#include <iostream> // std::cout
#include <map> // std::map
#include <utility>  // std::pair

#include "compressable.h"

int main(int argc, char **argv) {
  printf("Hello there.\n");

  std::map<int, int> map;
  std::pair<int, int> p(1, 1);
  // map.insert (p);

  auto ret = compressable::insert_compress(map, p);
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
  
  ret = compressable::insert_compress(map, p);
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
  

  return 0;
}
