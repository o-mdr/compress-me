/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#pragma once

#include "common.h"  // cm_item
#include "error.h"   // error checks
#include <map>       // std::map
#include <memory>    // smart pointers
#include <stdexcept> // exceptions
#include <utility>   // std::pair
#include <vector>    // std::vector
#include <zstd.h>    // zstd compression

namespace cm {

template <class K>
using cm_map = std::map<K, cm_item>;

template <class K, class V>
std::pair<typename cm_map<K>::iterator, bool> insert(cm_map<K> &c_map, const K key, const V &value,
                                                     const size_t v_size) {
    auto x_max_size = ZSTD_compressBound(v_size);
    std::vector<uint8_t> buf(x_max_size);
    auto x_size = ZSTD_compress(buf.data(), x_max_size, value, v_size, 1);
    check_zstd_size(x_size);

    compact(buf, x_size);
    auto ci = cm_item(buf, v_size);
    return c_map.insert(std::make_pair(key, ci));
}

template <class K, class V>
std::vector<uint8_t> at(cm_map<K> &c_map, K key) {
    cm_item ci = c_map.at(key);
    auto r_size = ZSTD_getFrameContentSize(ci.compressed_value.data(), ci.v_size);
    check_zstd_frame_size(r_size);

    std::vector<uint8_t> buf(r_size);
    auto c_size = ci.compressed_value.size();
    auto d_size = ZSTD_decompress(buf.data(), r_size, ci.compressed_value.data(), c_size);
    check_zstd_size(d_size);
    check_zstd_same_size(d_size, r_size);

    compact(buf, d_size);
    return buf;
}
} // namespace cm
