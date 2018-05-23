#include "TestKMP.h"

TestKMP::TestKMP() {
  kmp = new KMP;
}

TestKMP::~TestKMP() {
  delete kmp;
}
