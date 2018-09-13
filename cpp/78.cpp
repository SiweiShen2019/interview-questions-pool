#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>

#include "catch.hpp"
#include "print.cpp"

using namespace std;


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret{vector<int>()};
    for (auto n : nums) {
        int length = ret.size();
        for (int i = 0; i < length; ++i) {
            vector<int> new_subset (ret[i]);
            new_subset.push_back(n);
            ret.push_back(new_subset);
        }
    }
    return ret;
}


TEST_CASE("subsets") {
    SECTION("example") {
        vector<int> input {1, 2, 3};
        vector<vector<int>> expected {
            vector<int>{},
            vector<int>{1},
            vector<int>{2},
            vector<int>{1, 2},
            vector<int>{3},
            vector<int>{1, 3},
            vector<int>{2, 3},
            vector<int>{1, 2, 3},
        };
        REQUIRE(subsets(input) == expected);
    }
}
