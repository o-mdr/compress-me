/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#pragma once

#include <cstdint> // uint8_t
#include <vector>  // std::vector

namespace cm {

struct cm_item {
    std::vector<uint8_t> compressed_value;
    size_t v_size;

    cm_item(std::vector<uint8_t> c, size_t v) : compressed_value(c), v_size(v) {}
};

// template <class V> V to(const std::vector<uint8_t> &compressed_item) {
//     if (compressed_item.size() == 0) {
//         throw std::invalid_argument("compressed item size was 0");
//     }

//     return static_cast<V>(compressed_item.data());
// }
} // namespace cm
