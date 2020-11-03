#include "compressable.h"
#include <cstdint>  // uint8_t
#include <iostream> // std::cout
#include <map>      // std::map
// #include <stdio.h>
#include <utility> // std::pair
#include <vector>  // std::vector

int main(int argc, char **argv) {

    compressable::compressable_map<int> cm;

    std::string payload = "this is a long really long string, this is a long really long string";

    auto ret = compressable::insert(cm, 333, payload.c_str(), payload.size());
    if (ret.second == false) {
        std::cout << "element 'z' already existed";
    }

    auto f = compressable::at<int, std::string>(cm, 333);

    std::string str(f.begin(), f.end());

    return 0;
}
