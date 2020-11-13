/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#include "cm.h"
#include <cstdint>  // uint8_t
#include <iomanip>  // std::hex
#include <iostream> // std::cout

int main(int argc, char **argv) {

    std::cout << "Example compression with [zstd] and [std::map]\n";
    int key = 123;
    std::string value = "this is a long really long string, this is a long really long string";
    cm::cm_map<int> cm;

    std::cout << "Inserting: [" << value << "]\n";
    auto result = cm::insert(cm, key, value.c_str(), value.size());
    cm::cm_map<int>::iterator it = result.first;
    auto raw_bytes = it->second.compressed_value;

    std::cout << "Compressed into: ";
    for (const auto &value : raw_bytes) {
        std::cout << std::hex << unsigned(value) << " ";
    }
    std::cout << "\n";

    auto raw = cm::at<int, std::string>(cm, key);
    std::string actual(raw.begin(), raw.end());
    std::cout << "Retrieved value: [" << actual << "]\n";

    if (actual == value) {
        std::cout << "Compression and decompression worked as expected.\n";
    }

    return 0;
}
