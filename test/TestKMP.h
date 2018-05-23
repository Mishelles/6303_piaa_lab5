#ifndef TEST_KMP_H
#define TEST_KMP_H

#include <gtest/gtest.h>
#include "../src/KMP.h"

struct TestKMP : testing::Test {
  KMP* kmp;
  TestKMP();
  ~TestKMP();
};


#endif
