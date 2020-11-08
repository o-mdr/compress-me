#include "cdsc.h"
#include <cstdint>  // uint8_t
#include <iomanip>  // std::hex
#include <iostream> // std::cout

int main(int argc, char **argv) {

    std::cout << "Example compression with [zstd] and [std::map]\n";
    int key = 123;
    std::string value = "this is a long really long string, this is a long really long string";
    compressable::compressable_map<int> cm;

    std::cout << "Inserting: [" << value << "]\n";
    auto result = compressable::insert(cm, key, value.c_str(), value.size());
    compressable::compressable_map<int>::iterator it = result.first;
    auto raw_bytes = it->second.compressed_value;

    std::cout << "Compressed into: ";
    for (const auto &value : raw_bytes) {
        std::cout << std::hex << unsigned(value) << " ";
    }
    std::cout << "\n";

    auto raw = compressable::at<int, std::string>(cm, key);
    std::string actual(raw.begin(), raw.end());
    std::cout << "Retrieved value: [" << actual << "]\n";

    if (actual == value) {
        std::cout << "Compression and decompression worked as expected.\n";
    }

    return 0;
}
