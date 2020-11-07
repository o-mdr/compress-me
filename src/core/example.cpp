#include "compressable.h"
#include <cstdint>  // uint8_t
#include <iostream> // std::cout

int main(int argc, char **argv) {

    int key = 123;
    std::string value = "this is a long really long string";
    compressable::compressable_map<int> cm;

    auto ret = compressable::insert(cm, key, value.c_str(), value.size());
    if (ret.second == true) {
        std::cout << "Element was inserted\n";
    } else {
        std::cout << "Element already exists, nothing has changed\n";
    }

    auto raw_value = compressable::at<int, std::string>(cm, key);
    std::string actual(raw_value.begin(), raw_value.end());

    if (actual == value) {
        std::cout << "Compression and decompression worked OK\n";
    } else {
        std::cout << "Failed to compress and decompress\n";
    }

    return 0;
}
