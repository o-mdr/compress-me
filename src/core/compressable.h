/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#include "common.h"  // error checks
#include <cstdint>   // uint8_t
#include <map>       // std::map
#include <memory>    // smart pointers
#include <stdexcept> // exceptions
#include <utility>   // std::pair
#include <vector>    // std::vector
#include <zstd.h>    // zstd compression
namespace compressable {

struct compressable_item {
    std::vector<uint8_t> compressed_value;
    size_t v_size;

    compressable_item(std::vector<uint8_t> c, size_t v) : compressed_value(c), v_size(v) {}
};

template <class K> using compressable_map = std::map<K, compressable_item>;

// template <class V> V to(const std::vector<uint8_t> &compressed_item) {
//     if (compressed_item.size() == 0) {
//         throw std::invalid_argument("compressed item size was 0");
//     }

//     return static_cast<V>(compressed_item.data());
// }

template <class K, class V>
std::pair<typename compressable_map<K>::iterator, bool>
insert(compressable_map<K> &c_map, const K key, const V &value, const size_t v_size) {
    auto x_max_size = ZSTD_compressBound(v_size);
    std::vector<uint8_t> buf(x_max_size);

    auto x_size = ZSTD_compress(buf.data(), x_max_size, value, v_size, 1);
    check_zstd(x_size);

    buf.resize(x_size);
    buf.shrink_to_fit();

    auto ci = compressable_item(buf, v_size);

    return c_map.insert(std::make_pair(key, ci));
}

template <class K, class V> std::vector<uint8_t> at(compressable_map<K> &c_map, K key) {
    compressable_item ci = c_map.at(key);
    auto r_size = ZSTD_getFrameContentSize(ci.compressed_value.data(), ci.v_size);
    if (r_size == ZSTD_CONTENTSIZE_ERROR) {
        throw std::runtime_error("not compressed by zstd");
    }
    if (r_size == ZSTD_CONTENTSIZE_UNKNOWN) {
        throw std::runtime_error("original size unknown");
    }

    std::vector<uint8_t> buf(r_size);

    auto c_size = ci.compressed_value.size();
    auto d_size = ZSTD_decompress(buf.data(), r_size, ci.compressed_value.data(), c_size);
    check_zstd(d_size);
    if (d_size != r_size) {
        throw std::runtime_error("decompressed size [" + std::to_string(d_size) +
                                 "] bytes did not match ortiginal size [" + std::to_string(r_size) +
                                 "] bytes");
    }
    buf.resize(d_size);
    buf.shrink_to_fit();

    return buf;
}
} // namespace compressable
