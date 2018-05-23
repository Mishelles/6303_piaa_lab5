#include "TestKMP.h"
#include "../src/KMP.h"
#include <iostream>

struct testState {
  std::string checkingString;
  std::string sourceString;
  int result;

  friend std::ostream& operator<<(std::ostream& os, const testState& obj) {

    os << "[Checking string(A): " << obj.checkingString << " | ";
    os << "Source(B): " << obj.sourceString << " | ";
    os << "Result: " << obj.result;

    os << "]" <<std::endl;

    return os;
  }
};


struct checkShiftTest : TestKMP, testing::WithParamInterface<testState> {
    void SetUp() {
      std::cout << GetParam();
    }
};

TEST_P(checkShiftTest, checkCycleShift) {
  auto state = GetParam();
  ASSERT_EQ(state.result, kmp->checkShift(state.sourceString, state.checkingString));
}


INSTANTIATE_TEST_CASE_P(Default, checkShiftTest,
  testing::Values(
  testState{"defabc", "abcdef", 3},
  testState{"m", "mmmm", -1},
  testState{"kkk", "k", -1},
  testState{"poploly", "lolypop", 3},
  testState{"12345kdcskbdcasda", "a12345kdcskbdcasd", 16}
  ));

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
