/*
 * Copyright (c) 2020, Oleksii Mandrychenko. All rights reserved.
 * This source code is licensed under MIT license and GNU GPLv2.
 * You may choose either license at your own will.
 */

#include "benchmark/benchmark.h"
#include "cm.h"
#include <map>
#include <string>
#include <utility> // std::pair

static std::string value = "this is a long really long string, this is a long really long string";

static size_t estimate_row_size(const std::map<int, std::string> &m) {
    return sizeof(int) + m.at(0).length() * sizeof(char);
}

static size_t estimate_row_size(const cm::cm_map<int> &m) {
    return sizeof(int) + m.at(0).compressed_value.size() * sizeof(u_int8_t) +
           sizeof(m.at(0).v_size);
}

static void BM_cm_insert_at(benchmark::State &state) {
    int key = 0;
    cm::cm_map<int> uut;
    for (auto _ : state) {
        cm::insert(uut, key, value.c_str(), value.size());
        auto raw = cm::at<int, std::string>(uut, key);
        std::string actual(raw.begin(), raw.end());
        key++;
    }
    state.counters["Estimated row size"] = estimate_row_size(uut);
    state.counters["Number of keys"] = uut.size();
}

static void BM_map_insert_at(benchmark::State &state) {
    int key = 0;
    std::map<int, std::string> uut;
    for (auto _ : state) {
        uut.insert(std::make_pair(key, value));
        std::string actual = uut.at(key);
        key++;
    }
    state.counters["Estimated row size"] = estimate_row_size(uut);
    state.counters["Number of keys"] = uut.size();
}

// Register the function as a benchmark
BENCHMARK(BM_cm_insert_at);
BENCHMARK(BM_map_insert_at);
