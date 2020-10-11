#include <iostream> // std::cout
#include <map>      // std::map
#include <stdio.h>
#include <utility> // std::pair

#include "compressable.h"

int main(int argc, char **argv) {
    printf("Hello there.\n");

    std::map<int, std::string> map;
    std::pair<int, std::string> p(1, "this is a long really long string");
    // map.insert (p);

    auto ret = compressable::insert_compress(map, p);
    if (ret.second == false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    ret = compressable::insert_compress(map, p);
    if (ret.second == false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    return 0;
}
