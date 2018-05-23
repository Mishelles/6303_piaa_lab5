#include "TestKMP.h"
#include "../src/KMP.h"
#include <iostream>

struct testState {
  std::string string;
  std::vector<int> results;

  friend std::ostream& operator<<(std::ostream& os, const testState& obj) {

    os << "[String: " << obj.string << " | ";
    os << "Results: ";

    for (auto result : obj.results) {
      os << result << " ";
    }

    os << "]" <<std::endl;

    return os;
  }
};


struct prefixTest : TestKMP, testing::WithParamInterface<testState> {
    void SetUp() {
      std::cout << GetParam();
    }
};

TEST_P(prefixTest, prefixFunction) {
  auto state = GetParam();
  ASSERT_EQ(state.results, kmp->prefixFunction(state.string));
}


INSTANTIATE_TEST_CASE_P(Default, prefixTest,
  testing::Values(
  testState{"efefeftef", {0,0,1,2,3,4,0,1,2}},
  testState{" ", {0}},
  testState{"abcde", {0, 0, 0, 0, 0}},
  testState{"h", {0}},
  testState{"saaas", {0,0,0,0,1}},
  testState{"abcaababcabcacab", {0,0,0,1,1,2,1,2,3,4,2,3,4,0,1,2}}
  ));

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
