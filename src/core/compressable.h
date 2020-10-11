/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */
#include <iostream> // std::cout
#include <map>      // std::map
#include <memory>   // smart pointers
#include <utility>  // std::pair
#include <zstd.h>   // zstd compression

namespace compressable {

template <class K, class V>
std::pair<typename std::map<K, V>::iterator, bool>
insert_compress(std::map<K, V> &map, const std::pair<K, V> &kv) {
    size_t const srcSize = sizeof(kv.second);
    size_t const dstSize = ZSTD_compressBound(srcSize);
    auto dst = std::make_unique<unsigned char[]>(dstSize);

    size_t const compressed_size =
        ZSTD_compress(dst.get(), dstSize, &kv.second, srcSize, 1);
    // CHECK_ZSTD(cSize);

    std::cout << "Compressed from " << srcSize << " to " << compressed_size
              << "reserved " << dstSize << "\n";

    return map.insert(kv);
}

} // namespace compressable
