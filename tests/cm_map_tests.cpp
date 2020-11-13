/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#include "cm_map.h"
#include "common_tests.h"
#include <catch2/catch.hpp>

class cmMapFixture {
  protected:
    int key = 123;
    TestStruct ts = {"test", 555, true};
    cm::cm_map<int> uut;
};

TEST_CASE_METHOD(cmMapFixture, "insert string twice", "[cm_map][insert]") {
    std::string value = "this is a long really long string";
    auto ret = cm::insert(uut, key, value.c_str(), value.size());
    REQUIRE(ret.second == true);
    auto ret1 = cm::insert(uut, key, value.c_str(), value.size());
    REQUIRE(ret1.second == false);
}

TEST_CASE_METHOD(cmMapFixture, "insert struct twice", "[cm_map][insert]") {
    auto ret = cm::insert(uut, key, &ts, sizeof(ts));
    REQUIRE(ret.second == true);
    auto ret1 = cm::insert(uut, key, &ts, sizeof(ts));
    REQUIRE(ret1.second == false);

    // auto raw = cm::at<int, TestStruct>(uut, key);
    // auto actual = reinterpret_cast<TestStruct *>(raw.data());
    // REQUIRE(actual->b == true);
}
