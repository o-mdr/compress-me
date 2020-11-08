/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#include "compressable_map.h"
#include <catch2/catch.hpp>

TEST_CASE("Insert", "[compressable_map]") {

    int key = 123;
    std::string value = "this is a long really long string";
    compressable::compressable_map<int> cm;

    auto ret = compressable::insert(cm, key, value.c_str(), value.size());
    REQUIRE(ret.second == true);

    auto ret1 = compressable::insert(cm, key, value.c_str(), value.size());
    REQUIRE(ret1.second == false);
}
