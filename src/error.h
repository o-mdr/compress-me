/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#pragma once

#include <stdexcept> // std::runtime_error
#include <zstd.h>    // zstd compression

namespace cm {

// sztd errors
inline void check_zstd_size(const size_t size) {
    if (ZSTD_isError(size))
        throw std::runtime_error(ZSTD_getErrorName(size));
}

inline void check_zstd_same_size(const size_t d_size, const size_t r_size) {
    if (d_size != r_size) {
        throw std::runtime_error("decompressed size [" + std::to_string(d_size) +
                                 "] bytes did not match ortiginal size [" + std::to_string(r_size) +
                                 "] bytes");
    }
}

inline void check_zstd_frame_size(const size_t size) {
    if (size == ZSTD_CONTENTSIZE_ERROR) {
        throw std::runtime_error("not compressed by zstd");
    }
    if (size == ZSTD_CONTENTSIZE_UNKNOWN) {
        throw std::runtime_error("original size unknown");
    }
}

} // namespace cm
