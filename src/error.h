/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#pragma once

#include <stdexcept> // std::runtime_error
#include <zstd.h>    // zstd compression

namespace compressable {

void check_zstd(const size_t zstd_size) {
    if (ZSTD_isError(zstd_size))
        throw std::runtime_error(ZSTD_getErrorName(zstd_size));
}

} // namespace compressable
