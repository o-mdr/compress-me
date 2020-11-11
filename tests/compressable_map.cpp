/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#include "compressable_map.h"
#include "test_common.h"
#include <catch2/catch.hpp>

class CompressableMapFixture {
  protected:
    int key = 123;
    TestStruct ts = {"test", 555, true};
    compressable::compressable_map<int> uut;
};

TEST_CASE_METHOD(CompressableMapFixture, "insert string twice", "[compressable_map][insert]") {
    std::string value = "this is a long really long string";
    auto ret = compressable::insert(uut, key, value.c_str(), value.size());
    REQUIRE(ret.second == true);
    auto ret1 = compressable::insert(uut, key, value.c_str(), value.size());
    REQUIRE(ret1.second == false);
}

TEST_CASE_METHOD(CompressableMapFixture, "insert struct twice", "[compressable_map][insert]") {
    auto ret = compressable::insert(uut, key, &ts, sizeof(ts));
    REQUIRE(ret.second == true);
    auto ret1 = compressable::insert(uut, key, &ts, sizeof(ts));
    REQUIRE(ret1.second == false);

    // auto raw = compressable::at<int, TestStruct>(uut, key);
    // auto actual = reinterpret_cast<TestStruct *>(raw.data());
    // REQUIRE(actual->b == true);
}
