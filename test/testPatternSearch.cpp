#include "TestKMP.h"
#include "../src/KMP.h"
#include <iostream>

struct testState {
  std::string string;
  std::string pattern;
  std::vector<int> results;

  friend std::ostream& operator<<(std::ostream& os, const testState& obj) {

    os << "[Source string: " << obj.string << " | ";
    os << "Pattern: " << obj.pattern << " | ";
    os << "Results: ";

    for (auto result : obj.results) {
      os << result << " ";
    }

    os << "]" <<std::endl;

    return os;
  }
};


struct patternSearchTest : TestKMP, testing::WithParamInterface<testState> {
    void SetUp() {
      std::cout << GetParam();
    }
};

TEST_P(patternSearchTest, searchPatternInText) {
  auto state = GetParam();
  ASSERT_EQ(state.results, kmp->patternSearch(state.string, state.pattern));
}


INSTANTIATE_TEST_CASE_P(Default, patternSearchTest,
  testing::Values(
  testState{"a", "a", {0}},
  testState{"abab", "ab", {0, 2}},
  testState{"abcde", "f", {-1}},
  testState{"akiGhjdopaAjmkfhta", "a", {0, 9, 17}},
  testState{"abbakiGhjdopabbaAjmkfhtabba", "abba", {0, 12, 23}},
  testState{"htfsuccrhgysuccesskmjgsuccessfulllls", "successfull", {22}},
  testState{"mmmmmmmmmmmm", "m", {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}}

  ));

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
