#include <gtest/gtest.h>
#include "../src/KMP.h"
#include <iostream>

struct testState {
  std::string string;
  std::string pattern;
  std::vector<int> results;

  friend std::ostream& operator<<(std::ostream& os, const testState& obj) {

    os << "Source string: " << obj.string;
    os << "Pattern: " << obj.pattern;
    os << "Results: ";

    for (auto result : obj.results) {
      os << result << " ";
    }

    return os;
  }
};

struct TestKMP : testing::Test {
  KMP* kmp;

  TestKMP() {
    kmp = new KMP;
  }

  ~TestKMP() {
    delete kmp;
  }
};

struct patternSearchTest : TestKMP, testing::WithParamInterface<testState> {

};

TEST_P(patternSearchTest, Pattern) {
  auto state = GetParam();
  ASSERT_EQ(state.results, kmp->patternSearch(state.string, state.pattern));
}


INSTANTIATE_TEST_CASE_P(Default, patternSearchTest,
  testing::Values(
  testState{"abab", "ab", {0, 2}}
  ));

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
