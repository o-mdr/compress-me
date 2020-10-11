/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */
#include <map>     // std::map
#include <utility> // std::pair
#include <zstd.h>  // zstd compression

namespace compressable {

template <class K, class V>
std::pair<typename std::map<K, V>::iterator, bool>
insert_compress(std::map<K, V> &map, const std::pair<K, V> &kv) {
    // size_t fSize = sizeof (kv.second);
    //     void *const fBuff = mallocAndLoadFile_orDie(fname, &fSize);
    //     size_t const cBuffSize = ZSTD_compressBound(fSize);
    //     void *const cBuff = malloc_orDie(cBuffSize);

    //     /* Compress.
    //  * If you are doing many compressions, you may want to reuse the context.
    //  * See the multiple_simple_compression.c example.
    //  */
    //     size_t const cSize = ZSTD_compress(cBuff, cBuffSize, fBuff, fSize,
    //     1); CHECK_ZSTD(cSize);

    //     saveFile_orDie(oname, cBuff, cSize);

    //     /* success */
    //     printf("%25s : %6u -> %7u - %s \n", fname, (unsigned)fSize,
    //     (unsigned)cSize, oname);

    //     free(fBuff);
    //     free(cBuff);
    return map.insert(kv);
}

} // namespace compressable
